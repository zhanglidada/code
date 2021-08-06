#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1;
    // 先搜索右边界right
    while (i <= j) {
      int mid = i + (j - i) / 2;
      // 相等的时候也尽量向右移动
      if (nums[mid] <= target)  i = mid + 1;
      else j = mid - 1;
    }
    int right = i;
    if (j < 0 || nums[j] != target)  return 0;
    // 搜索左边界left(因为右边界存在的时候target肯定存在于数组中)
    i = 0, j = nums.size() - 1;
    while (i <= j) {
      int mid = i + (j - i) / 2;
      if (nums[mid] < target)  i = mid + 1;
      // 相等的时候尽量向左移
      else j = mid - 1;
    }
    int left = j;
    return right - left - 1;
  }
};
// 改进一下
class Solution {
 public:
  // 其实可以改为查找target的右边界和target-1的右边界
  int search(vector<int>& nums, int target) {
    return helper(nums, target) - helper(nums, target - 1);
  }
  // helper 函数旨在查找数字 tar 在数组 nums 中的插入点,将大于target的数字插入到其后面
  int helper(vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1;
    while (i <= j) {
      int mid = i + (j - i) / 2;
      if (nums[mid] <= target)  i = mid + 1;
      else j = mid - 1;
    }
    return i;
  }
};
int main() {
  vector<int> inputs = {5,7,7,8,8,10};
  int target = 8;
  Solution ss;
  cout << ss.search(inputs, target);
  return 0;
}