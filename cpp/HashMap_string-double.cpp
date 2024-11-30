#include <iostream>
#include <vector>
#include <string>

struct hashnode {
  std::string     key;
  double          value;
  hashnode*       next;

  hashnode(const std::string& key, double value) : key(key), value(value), next(nullptr) {}
};

class HashTable {
  public:
    HashTable(int size) : table_size(size), table(size, nullptr) {}

    ~HashTable() {
      for (int i = 0; i < table_size; i++) {
        hashnode* node = table[i];
        // 依次删除链地址法中的每个节点
        while (node != nullptr) {
          hashnode* next = node->next;
          delete node;
          node = next;
        }

        table[i] = nullptr;
      }
    }

    void insert(const std::string& key, double value) {
      int index = hashFunction(key);
      hashnode* node = table[index];

      if (node == nullptr) {
        table[index] = new hashnode(key, value);
      }
      else {
        while (node != nullptr) {
          if (node->key == key) {
            node->value = value;
            return;
          }
          
          if (node->next == nullptr)
            break;

          node = node->next;
        }

        node->next = new hashnode(key, value);
      }

      return;
    }

    // 删除指定的键值对
    void erase(const std::string& key) {
      int index = hashFunction(key);
      hashnode* node = table[index];
      hashnode* prev = nullptr;

      while (node != nullptr) {
        if (node->key == key) {
          if (prev == nullptr) {
            table[index] = node->next;
          }
          else {
            prev->next = node->next;
          }

          delete node;
          return;
        }
        
        prev = node;
        node = node->next;
      }

      throw std::runtime_error("Key not found!");
    }


    double get(const std::string& key) {
      int index = hashFunction(key);
      hashnode* node = table[index];

      while (node != nullptr) {
        if (node->key == key)
          return node->value;
        
        node = node->next;
      }

      throw std::runtime_error("Key not found!");
    }

  private:
    // 哈希函数，这里采用简单的将字符串每个字符的ASCII值相加后取模的方式
    int hashFunction(const std::string& key) {
        int hashValue = 0;
        for (char c : key) {
            hashValue += c;
        }
        return hashValue % table_size;
    }

    int table_size;
    std::vector<hashnode*> table;  
};

int main(int argc, char* argv[]) {
  HashTable hashTable(10);

  // 插入键值对
  hashTable.insert("key1", 12.34);
  hashTable.insert("key2", 56.78);

  // 获取并输出键值对的值
  try {
      std::cout << "Value for key1: " << hashTable.get("key1") << std::endl;
      std::cout << "Value for key2: " << hashTable.get("key2") << std::endl;
  } catch (std::runtime_error& e) {
      std::cout << e.what() << std::endl;
  }

  // 修改键值对的值
  hashTable.insert("key1", 99.99);
  try {
      std::cout << "Updated value for key1: " << hashTable.get("key1") << std::endl;
  } catch (std::runtime_error& e) {
      std::cout << e.what() << std::endl;
  }

  // 删除键值对
  hashTable.erase("key2");
  try {
      hashTable.get("key2");
  } catch (std::runtime_error& e) {
      std::cout << e.what() << std::endl;
  }

  return 0;
}