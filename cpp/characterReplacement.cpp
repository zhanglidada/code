#include <iostream>
#include <vector>
#include <array>
using namespace std;

// 滑动窗口的经典问题
class Solution {
 public:
  int characterReplacement(string s, int k) {
    if (s.empty())
      return 0;
    array<int, 26> map = {0}; // 建立当前链表中 字符->字符数量的映射
    int left = 0, right = 0;  // left和right表示可以在修改k个字符后最大的重复子链长度
    int maxCount = 0;
    for (right = 0; right < s.size(); right++) {
      map[s[right] - 'A'] ++;
      maxCount = max(maxCount, map[s[right] - 'A']);  // 当前窗口内最多字符的个数
      if (right - left + 1 - maxCount > k) { //需要替换的字符个数就是当前窗口的大小减去窗口中数量最多的字符的数量
        map[s[left] - 'A'] --;  // 缩小窗口
        left++;
      }
    }
    return s.size() -left;
  }
};