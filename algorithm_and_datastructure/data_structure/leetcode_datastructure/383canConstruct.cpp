#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
 * 如果可以，返回 true ；否则返回 false 。
 * Notes:
 * magazine 中的每个字符只能在 ransomNote 中使用一次。
********************************************************************************************/

/*******************************************************************************************
 * Notes:
 * 使用两个hash表即可
********************************************************************************************/
class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
      if (ransomNote.size() > magazine.size())  return false;
      
      // 存储每个字符出现次数
      for (auto c : ransomNote) {
        if (!hash_rans.count(c)) {
          hash_rans[c] = 1;
        } else {
          hash_rans[c] ++;
        }
      }
      for (auto c : magazine) {
        if (!hash_mag.count(c)) {
          hash_mag[c] = 1;
        } else {
          hash_mag[c] ++;
        }
      }

      for (auto it = hash_rans.cbegin(); it != hash_rans.cend(); it++) {
        // ransomNote中某个字符个数大于magazine中对应字符个数
        if (it->second > hash_mag[it->first])
          return false;
      }
      return true;
    }
  private:
    // ransomNote 和 magazine 中每个字符出现次数
    unordered_map<char, int> hash_rans;
    unordered_map<char, int> hash_mag;
};

/*******************************************************************************************
 * Notes:
 * 1.使用两个hash表即可(方法优化)
 * 2.先遍历magazine，遍历ransomnote时将hashmap中对应个数递减，若 < 0则false
********************************************************************************************/
class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
      if (ransomNote.size() > magazine.size())  return false;
      
      // 首先遍历magazine中所有的字符并计数每种字符个数
      for (auto c : magazine) {
        index = c - 'a';
        cnt[index] ++;
      }

      // 计算ransom note中字符格式，并与mag中字符个数比较
      for (auto c : ransomNote) {
        index = c - 'a';
        cnt[index]--;
        if (cnt[index] < 0)
          return false;
      }

      return true;
    }
  private:
    // 初始化每个字符出现次数的数组
    vector<int> cnt = vector<int>(26, 0);
    int index = 0;
};