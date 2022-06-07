#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * Notes:
 * 若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
********************************************************************************************/

/*******************************************************************************************
 * Notes:
 * 很简单，立马想到hashtable
********************************************************************************************/
class Solution {
  public:
    bool isAnagram(string s, string t) {
      if (s.size() != t.size()) return false;

      for (auto c : s) {
        index = c - 'a';
        cnt[index] ++;
      }

      for (auto c : t) {
        index = c - 'a';
        cnt[index] --;
        if (cnt[index] < 0)
          return false;
      }

      return true;
    }
  private:
    int cnt[26] = {0};
    int index = 0;
};

/*******************************************************************************************
 * Notes:
 * 由于需要比较两个字符串之间的区别，所以可以先对其进行排序，之后比较字符串是否相等即可
********************************************************************************************/
class Solution {
  public:
    bool isAnagram(string s, string t) {
      if (s.size() != t.size()) return false;

      sort(s.begin(), s.end(), [](char a, char b) {
        return a < b;
      });

      sort(t.begin(), t.end(), [](char a, char b) {
        return a < b;
      });

      return s == t;
    }
};