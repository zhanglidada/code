#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。
 * Notes:
 * 字符串只包含小写字母
********************************************************************************************/


/*******************************************************************************************
 * Notes:
 * 使用hash表保存每个元素第一次出现的pos
 * vector保存每个元素的访问顺序
********************************************************************************************/
class Solution {
  public:
    int firstUniqChar(string s) {
      for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        // 元素在字符串中第一次出现，插入hash表中并进入数组保存顺序
        if (!hash_table.count(c)) {
          hash_table[c] = i;  // 保存第一次出现的位置
          order.emplace_back(c);
        } else {
          // 多次出现的字符pos为-1
          hash_table[c] = -1;
        }
      }
      for (auto num : order) {
        if (hash_table[num] != -1)
          return hash_table[num];
      }
      return -1;
    }
  private:
    unordered_map<char, int> hash_table;  // 存储元素第一次出现位置
    vector<char> order;  // 元素出现的顺序
};

/*******************************************************************************************
 * Notes:
 * 1.使用hash表保存每个元素出现的频率
 * 2.重新遍历字符串，查找第一个仅出现一次的字符
********************************************************************************************/
class Solution {
  public:
    int firstUniqChar(string s) {
      for (auto c : s) {
        // 当前字符第一次出现
        if (!hash_table.count(c)) {
          hash_table[c] = 1;
        } else {
          hash_table[c] ++;
        }
      }

      for (int i = 0; i < s.size(); i++) {
        c = s[i];
        if (hash_table[c] == 1)
          return i;
      }
      return -1;
    }
  private:
    unordered_map<char, int> hash_table;
    char c;
};