#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 采用滑动窗口的方法，由于在上个left指针开始到right结尾的之间没有重复元素，
// 所以下一个left开始，right只需要接着再往后移动就好
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<int> charTable;
    // right指针初始化为-1，表示出现在左边界的左侧，还没有开始滑动
    int left, right = -1;
    int maxSubLength = 0;
    for (left = 0; left < s.size(); left ++) {
      if (left != 0) {
        // 每次左指针向右移动一次，删除左指针之前记录在hash中的char
        charTable.erase(s.at(left - 1));
      }
      while (right + 1 < s.size() && !charTable.count(s.at(right + 1))) {
        charTable.insert(s[right + 1]);
        right++;
      }
      maxSubLength = max(maxSubLength, right - left + 1);
    }
    return maxSubLength;
  }
};
int main() {
  return 0;
}