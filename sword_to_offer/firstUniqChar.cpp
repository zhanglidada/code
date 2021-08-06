#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 采用hash映射
class Solution {
 public:
  char firstUniqChar(string s) {
    unordered_map<char, bool> hashmap;
    for (auto c : s) {
      if (hashmap.count(c) == 0)
        hashmap[c] = true;
      else
        hashmap[c] = false;
    }
    for (auto c : s) {
      if (hashmap[c])
        return c;
    }
    return ' ';
  }
};

// 利用数组代替hash映射
class Solution {
 public:
  char firstUniqChar(string s) {
    vector<int> table(26, 0);
    for (auto c : s) {
      table[c - 'a'] ++;
    }
    for (auto c : s) {
      if (table[c - 'a'] == 1)
        return c;
    }
    return ' ';
  }
};