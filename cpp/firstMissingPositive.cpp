#include <iostream>
#include <vector>
using namespace std;
/*
  题目要求空间复杂度为常数，时间复杂度为O(n)
*/
/*
// 采用改进后的hash表，注意只能使用O(1)的空间复杂度
class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    int numsSize = nums.size();
    // 所有小于0的数均变成n+1；第一遍循环之后数组中所有的数字均>0
    for (auto& num : nums) {
      if (num <= 0)
        num = numsSize + 1;
    }
    // 查找数组之内的值x，若abs(x)<=n，将数组的abs(x)-1位置的值变为-abs(nums[abs(x)-1])
    // 若数组下标为i的值为负，说明值在1~n的范围内(i+1)，存在于数组中(类似hash表)
    for (auto& num : nums) {
      if (abs(num) <= numsSize) {
        int pos = abs(num) - 1;
        nums[pos] = -abs(nums[pos]);
      }
    }
    for (int i = 0; i < numsSize; i++) {
      if (nums[i] > 0)  // 说明i+1是未出现的最小正整数
        return i + 1;
    }
    return numsSize + 1;
  }
};  */

// 采用置换方式
class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    int numSize = nums.size();
    for (int i = 0; i < numSize; i++) {
      // 将满足条件的值放在应该放置的位置
      while (nums[i] > 0 && nums[i] <= numSize && nums[i] != nums[nums[i] - 1]) {
        // 如果nums[i] != nums[nums[i] - 1]，跳出循环继续下一个
        swap(nums[i], nums[nums[i] - 1]);
      }
    }
    for (int i = 0; i < numSize; i++) {
      if (nums[i] != (i+1))
        return i + 1;
    }
    return numSize + 1;
  }
};
int main() {
  return 0;
}