#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 采用动态规划和hashmap
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty())  return 0;
    unordered_map<char, int> hashmap;
    int dp0 = 1, dp1;
    hashmap.insert(pair<char, int>(s[0], 0));
    int maxsubLen = 1;
    for (int i = 1; i < s.size(); i++) {
      if (hashmap.count(s[i]) == 0 || i - hashmap[s[i]] > dp0) {
        dp1 = dp0 + 1;
      } else {
        dp1 = i - hashmap[s[i]];
      }
      hashmap[s[i]] = i;
      maxsubLen = max(maxsubLen, dp1);
      dp0 = dp1;
    }
    return maxsubLen;
  }
};

// 采用双指针进行滑动窗口，利用hashmap进行字典检查
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty())  return 0;
    unordered_map<char, int> hashmap;
    int i = -1;
    hashmap.insert(pair<char, int>(s[0], 0));
    int maxsubLen = 1;
    for (int j  = 1; j < s.size(); j++) {
      // 包含左指针,将i指向当前字符在字符串中上一次出现的位置
      if (hashmap.count(s[j]) != 0) {
        i = max(hashmap[s[j]], i);
      }
      hashmap[s[j]] = j;
      maxsubLen = max(maxsubLen, j - i);
    }
    return maxsubLen;
  }
};