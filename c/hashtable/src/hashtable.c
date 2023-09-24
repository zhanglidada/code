#include "hashtable.h"
#include "hashfunc.h"

#ifdef __WITH_MURMUR

#include "murmur.h"

#endif //__WITH_MURMUR

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

uint32_t global_seed = 2976579765;

/*---------------------------------- Debug macro ----------------------------------*/

#ifdef DEBUG
#define debug(M, ...) fprintf(stderr, "%s:%d - " M, __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define debug(M, ...)
#endif

// init hash table 
void ht_init(hash_table_t *table, ht_flags flags, double max_load_factor
#ifndef __WITH_MURMUR
        , HashFunc *for_x86_32, HashFunc *for_x86_128, HashFunc *for_x64_128
#endif //__WITH_MURMUR
)
{
  unsigned int i = 0;

  #ifdef __WITH_MURMUR

    table->hashfunc_x86_32 = MurmurHash3_x86_32;
    table->hashfunc_x86_128 = MurmurHash3_x86_128;
    table->hashfunc_x64_128 = MurmurHash3_x64_128;

  #else  // __WITH_MURMUR

  table->hashfunc_x86_32 = for_x86_32;
  table->hashfunc_x86_128 = for_x86_128;
  table->hashfunc_x64_128 = for_x64_128;

  #endif  // __WITH_MURMUR

  table->array_size = HT_INITIAL_SIZE;  // 初始size
  // array空间分配
  table->array = malloc(table->array_size * sizeof(table->array));

  if(table->array == NULL) 
  {
    debug("ht_init failed to allocate memory\n");
  }

  // 初始化其余属性
  table->key_count = 0;
  table->collisions = 0;
  table->flags = flags;
  table->max_load_factor = max_load_factor;
  table->current_load_factor = 0.0;

  for (i = 0; i < table->array_size; i++)
  {
    table->array[i] = NULL;
  }

  return;
}

// 释放hashtable内部分配的内存
void ht_destroy(hash_table_t *table)
{
  unsigned int          i = 0;
  hash_entry_t*         entry = NULL;
  hash_entry_t*         tmp_entry = NULL;
  
  if(table->array == NULL) 
  {
    debug("ht_destroy got a bad table\n");
  }

  // 从头遍历hash数组
  for (i = 0; i < table->array_size; i++)
  {
    // hash数组每个元素为hash冲突链的首节点
    entry = table->array[i];

    // 删除hash数组当前index下的所有冲突节点
    while (entry != NULL)
    {
      tmp_entry = entry->next;  // 指向链表下一个指针

      // 删除当前冲突节点
      he_destroy(table->flags, entry);

      entry = tmp_entry;
    }
  }

  table->hashfunc_x86_32 = NULL;
  table->hashfunc_x86_128 = NULL;
  table->hashfunc_x64_128 = NULL;
  table->array_size = 0;
  table->key_count = 0;
  table->collisions = 0;
  free(table->array);
  table->array = NULL;

  return;
}


// insert one hash entry into hashtable,
// 根据key value构造一个hash entry并插入hashtable中
void ht_insert(hash_table_t*  table, void* key, size_t key_size, void* value, size_t value_size)
{
  // 构造hash entry
  hash_entry_t* entry = he_create(table->flags, key, key_size, value, value_size);

  // hash entry insert into hashtable
  ht_insert_he(table, entry);

  return;
}

// create a new hash entry
hash_entry_t* he_create(int flags, void* key, size_t key_size, void* value, size_t value_size)
{
  hash_entry_t* entry;
  
  entry = malloc(sizeof(hash_entry_t));  // 新创建实例
  if (entry == NULL)
  {
    debug("Failed to create hash_entry\n");
    goto func_end;
  }

  // 设置hash_entry key
  entry->key_size = key_size;
  if (flags & HT_KEY_CONST)
  {
    entry->key = key;
  }
  else
  {
    // 分配key 并拷贝
    entry->key = malloc(key_size);
    if (entry->key == NULL)
    {
      debug("Failed to create hash_entry\n");
      goto func_end;  // 失败时释放entry
    }

    memcpy(entry->key, key, key_size);
  }

  // 设置entry value
  entry->value_size = value_size;
  if (flags & HT_VALUE_CONST)
  {
    entry->value = value;
  }
  else
  {
    entry->value = malloc(sizeof(value_size));
    if (entry->value == NULL)
    {
      debug("Failed to create hash_entry\n");
      goto func_end;  // 失败时释放entry
    }

    memcpy(entry->value, value, value_size);
  }

  entry->next = NULL;

  return entry;  // 成功时返回entry

func_end:
  // entry非空时释放内存
  if (entry != NULL)
  {
    if (entry->key != NULL)
      free(entry->key);

    if (entry->value != NULL)
      free(entry->value);

    free(entry);
  }

  return NULL;
}

// insert one entry into hash table
void ht_insert_he(hash_table_t* table, hash_entry_t* entry)
{
  hash_entry_t*       tmp_entry = NULL;
  unsigned int        index = 0;

  // 设置需要插入的entry节点
  entry->next = NULL;

  // 计算当前插入节点在hashtable中下标
  index = ht_index(table, entry->key, entry->key_size);
  // 获取当前index冲突链的首节点
  tmp_entry = table->array[index];

  // 当前插入节点不存在冲突，插入并返回
  if (tmp_entry == NULL)
  {
    table->array[index] = entry;
    table->key_count ++;
    return;
  }
  
  // 存在冲突，在链中向后查找(当前节点为链表中最后一个节点则不做比较)
  while (tmp_entry->next != NULL)
  {
    // 比较冲突节点的key值是否相同
    if (he_key_compare(tmp_entry, entry))
      break;
    else
      tmp_entry = tmp_entry->next;
  }

  // 需要插入的entry key值存在于链中
  if (he_key_compare(tmp_entry, entry))
  {
    // 重置tmp_entry节点的value
    he_set_value(table->flags, tmp_entry, entry->value, entry->value_size);
    // 删除当前要插入的entry
    he_destroy(table->flags, entry);
  }
  else
  {
    // 新增entry挂在冲突链的尾部
    tmp_entry->next = entry;
    table->collisions += 1;  // 冲突增加
    table->key_count += 1;
    table->current_load_factor = (double)table->collisions / table->array_size;  // 重置装载因子

    // 当table auto resize开启且load fator过大时，resize table
    if (!(table->flags & HT_NO_AUTORESIZE) && (table->current_load_factor > table->max_load_factor))
    {
      // resize table to 2 double of current table size
      ht_resize(table, table->array_size * 2);

      // 重新计算hash table装载因子
      table->current_load_factor = (double)table->collisions / table->array_size;
    }
  }

  return;
}


// 根据hash key返回hash value
void* ht_get(hash_table_t* table, void* key, size_t key_size, size_t* value_size)
{
  unsigned int            index = ht_index(table, key, key_size);  // 计算当前key所在hash数组下标
  hash_entry_t*           entry = table->array[index];  // hash 冲突链首节点
  hash_entry_t            tmp;

  tmp.key                 = key;
  tmp.key_size            = key_size;

  // 冲突链中存在节点
  while (entry != NULL)
  {
    if (he_key_compare(entry, &tmp))
    {
      if (value_size != NULL)
        *value_size = entry->value_size;

        return entry->value;
    }
    else
    {
      entry = entry->next;  // 查找冲突链中的下一个节点
    }
  }

  return NULL;  // 当前key对应节点不在hashtable中
}


// 从hash table 中移除key对应的hash entry
void ht_remove(hash_table_t*  table, void* key, size_t key_size)
{
  unsigned int index = ht_index(table, key, key_size);  // 计算key所在index
  hash_entry_t* entry = table->array[index];  // 获取冲突链首节点
  hash_entry_t* prev = NULL;
  hash_entry_t  tmp;

  // 设置临时hash entry，用于和被删除节点比较
  tmp.key = key;
  tmp.key_size = key_size;

  // 从冲突链中查找
  while (entry != NULL)
  {
    // 比较要查找节点key同当前hash冲突链中的节点是否相同
    if (he_key_compare(entry, &tmp))  // 要删除节点被找到
    {
      // 要删除节点为hash冲突链中的第一个节点
      if (prev == NULL)
        table->array[index] = entry->next;
      else
        prev->next = entry->next;

      table->key_count --;  // hash table中entry个数-1

      // 冲突链中存在不止一个节点，删除冲突节点时需要将冲突计数-1
      if (prev != NULL)
        table->collisions --;

      // 销毁找到的节点
      he_destroy(table->flags, entry);

      return;
    }
    else
    {
      // 继续查找节点
      prev = entry;
      entry = entry->next;
    }
  }
}

// 判断当前hash table是否包含key所指节点
int ht_contains(hash_table_t* table, void* key, size_t key_size)
{
  unsigned int index = ht_index(table, key, key_size);
  hash_entry_t* entry = table->array[index];
  hash_entry_t  tmp;

  tmp.key = key;
  tmp.key_size = key_size;

  while (entry != NULL)
  {
    if (he_key_compare(entry, &tmp))
      return 1;
    else
      entry = entry->next;
  }

  return 0;
}

// 获取hash table size
unsigned int ht_size(hash_table_t* table)
{
  return table->key_count;
}


// 返回hashtable中所有的key
void** ht_keys(hash_table_t* table, unsigned int* key_count)
{
  void** ret = NULL;
  hash_entry_t* tmp = NULL;
  unsigned int i = 0;
  unsigned int num = 0;

  if (table->key_count == 0)
  {
    *key_count = num;
    return NULL;
  }

  // array of pointers to keys
  ret = malloc(table->key_count * sizeof(void*));
  
  // loop over all of the chains, walk the chains and add each entry to the array of keys
  // 遍历整个hash数组
  for (i = 0; i < table->array_size; i++)
  {
    // 获取冲突链首节点
    tmp = table->array[i];
    // 遍历冲突链中的所有节点并添加到返回链中
    while (tmp != NULL)
    {
      ret[num ++] = tmp->key;
      tmp = tmp->next;

      // 应该永远不会发生的情况
      if(num >= table->key_count) {
        debug("ht_keys: too many keys, expected %d, got %d\n", table->key_count, num);
      }
    }
  }

  return ret;
}

// 清空并重置hashtable
void ht_clear(hash_table_t* table)
{
  ht_destroy(table);

  ht_init(table, table->flags, table->max_load_factor,
  #ifndef __WITH_MURMUR
    table->hashfunc_x86_32, table->hashfunc_x86_128, table->hashfunc_x64_128
  #endif //__WITH_MURMUR
  );
}


// Calulates the index in the hash table's internal array from the given key
// 不同的key计算得到的index， 对table size取模可能相同
unsigned int ht_index(hash_table_t* table, void* key, size_t key_size)
{
  uint32_t            index = 0;

  // 根据hashfunc计算entry key对应的hash值
  table->hashfunc_x86_32(key, key_size, global_seed, &index);
  // 取模，获取实际下标
  index %= table->array_size;

  return index;
}

// 重置hash table数组到指定size大小
void ht_resize(hash_table_t* table, unsigned int new_size)
{
  hash_table_t                new_table;
  unsigned int                i = 0;
  hash_entry_t*               entry = NULL;  // 冲突链首节点
  hash_entry_t*               next = NULL;  // next hash entry

  debug("ht_resize(old=%d, new=%d)\n",table->array_size,new_size);
  new_table.hashfunc_x86_32 = table->hashfunc_x86_32;
  new_table.hashfunc_x86_128 = table->hashfunc_x86_128;
  new_table.hashfunc_x64_128 = table->hashfunc_x64_128;
  new_table.array_size = new_size;  // 新table数组size
  new_table.array = malloc(new_size * sizeof(hash_entry_t*));  // 新数组内存分配
  new_table.key_count = 0;
  new_table.collisions = 0;
  new_table.flags = table->flags;
  new_table.max_load_factor = table->max_load_factor;

  // 初始化hashtable 数组
  for (i = 0; i < new_table.array_size; i++)
    new_table.array[i] = NULL;

  for (i = 0; i < table->array_size; i++)
  {
    // 获取冲突链首节点
    entry = table->array[i];
    while (entry != NULL)
    {
      next = entry->next;
      // 当前table的冲突链上节点直接插入到新table的冲突链上
      ht_insert_he(&new_table, entry);
      entry = next;  // 获取下一个冲突链上的节点
    }
    table->array[i] = NULL;
  }

  // 释放old hashtable 内部分配内存
  ht_destroy(table);

  table->hashfunc_x86_32 = new_table.hashfunc_x86_32;
  table->hashfunc_x86_128 = new_table.hashfunc_x86_128;
  table->hashfunc_x64_128 = new_table.hashfunc_x64_128;
  table->array_size = new_table.array_size;
  table->array = new_table.array;
  table->key_count = new_table.key_count;
  table->collisions = new_table.collisions;

}

void ht_set_seed(uint32_t seed)
{
  global_seed = seed;
}

// 比较两个entry对应的key是否相等（hash冲突链中entry key对应的hash值相同）
int he_key_compare(hash_entry_t* entry1, hash_entry_t* entry2)
{
  if (entry1->key_size != entry2->key_size)
    return 0;

  // 比较key指向地址的前key_size个字节是否一致
  return (memcpy(entry1->key, entry2->key, entry1->key_size));
}


// 设置已存在实例的value(key相等时重置hash冲突链上冲突节点的value值)
int he_set_value(int flags, hash_entry_t* entry, void* value, size_t value_size)
{
  if (!(flags & HT_VALUE_CONST))
  {
    if (entry->value)
      free(entry->value);

    entry->value = malloc(value_size);
    if (entry->value == NULL)
    {
      debug("Failed to set entry value\n");
      return;
    }
    memcpy(entry->value, value, value_size);
  }
  else
    entry->value = value;

  entry->value_size = value_size;
}

// 删除当前hash entry实例
void he_destroy(int flags, hash_entry_t* entry)
{
  // entry的key为新分配的内存，需要释放
  if (!(flags & HT_KEY_CONST))
    free(entry->key);

  // entry的value为新分配的内存，需要释放
  if (!(flags & HT_VALUE_CONST))
    free(entry->value);
  
  free(entry);
}


