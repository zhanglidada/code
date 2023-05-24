#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 采用hash映射，两次遍历字符串
class Solution {
 public:
  char firstUniqChar(string s) {
    unordered_map<char, bool> hashmap;

    // 遍历串中每一个字符，设置其unique属性
    for (auto c : s) {
      if (hashmap.count(c) == 0)
        hashmap[c] = true;
      else
        hashmap[c] = false;
    }

    // 从头遍历串，找到第一个unique字符
    for (auto c : s) {
      if (hashmap[c])
        return c;
    }

    // s为空串或者不存在唯一字符
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