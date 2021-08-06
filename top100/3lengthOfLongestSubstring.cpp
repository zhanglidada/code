#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
  startsubstr为每个可能的子串的开始位置
  hashchar中存放的是遍历过程中字符最近一次出现的位置
  针对滑动窗口的优化，对于重复出现的字符，如果大于startsubstr，则从startsubstr下一个开始进行滑动
*/
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> hashchar;
    if (s.size() == 0)  return 0;
    int currentLen = 0, maxLen = 0, startsubstr = 0;
    for (int i = 0; i < s.size(); i++) {
      // 对一个子数组中第一次访问的元素进行插入
      if (hashchar.count(s[i]) == 0)  hashchar[s[i]] = i, currentLen++;
      else {
        // 子串中出现第一个重复的字符
        maxLen = max(maxLen, currentLen);
        startsubstr = max(hashchar[s[i]], startsubstr);
        currentLen = i - startsubstr;
        hashchar[s[i]] = i;
      }
    }
    maxLen = max(maxLen, currentLen);
    return maxLen;
  }
};
int main() {
  string s = "aabce";
  Solution ss;
  cout << ss.lengthOfLongestSubstring(s);
}