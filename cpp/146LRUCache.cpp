#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>

using namespace std;

typedef struct node node_t;
struct node {
  int     key;
  int     value;
  node_t* prev;
  node_t* next;
  node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

// 用hash表快速判断当前要访问的节点是否在LUR中
// 用双向链表保存LRU链
class LRUCache {
  public:
    // 初始化，设置LRU链表容量以及哨兵节点
    LRUCache(int capacity) {
      size = capacity;

      // 初始化两个哨兵节点
      l = new node_t(-1, -1);
      r = new node_t(-1, -1);

      l->next = r;
      r->prev = l;
    }
    
    int get(int key) {
        // 访问节点并将其移动到链表头
        if (map.find(key) != map.end()) {
          node_t* node = map[key];
          
          // 从当前位置移除
          node->prev->next = node->next;
          node->next->prev = node->prev;
          
          // 插入链表头
          node->next = l->next;
          l->next->prev = node;
          l->next = node;
          node->prev = l;

          return node->value;
        }
        else {
          return -1;
        }
    }
    
    // key存在的时候更新值，并将其放到链表头；key不存在则将其插入到链表头（链表满了就将链表尾节点移除）
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
          node_t* node = map[key];

          // 从当前位置移除
          node->prev->next = node->next;
          node->next->prev = node->prev;
          
          // 插入链表头
          node->next = l->next;
          l->next->prev = node;
          l->next = node;
          node->prev = l;

          node->value = value;
        }
        else {
          node_t* node = nullptr;

          // 先判断链表是否已满,如果已满就移除链表尾节点
          if (map.size() == size) {
            node = r->prev;
            node->prev->next = r;
            r->prev = node->prev;

            // 移除map中对应的节点
            map.erase(node->key);
          }

          if (node  == nullptr)
            node = new node_t(key, value);
          else {
            node->key = key;
            node->value = value;
          }

          // 再将节点插入链表
          node->next = l->next;
          l->next->prev = node;
          l->next = node;
          node->prev = l;

          // 插入map中
          map[key] = node;
        }
    }

  private:
    int size;
    unordered_map<int, node_t*> map;
    node_t* l, *r;  // 哨兵节点
};