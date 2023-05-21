#include <iostream>
#include <vector>
using namespace std;

/*
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

*/

/**
 * @brief 
 * 两次二分查找，分别查找坐边界和右边界
 * 
 */
class Solution {
  public:
    int search(vector<int>& nums, int target) {
      if (nums.size() == 0)
        return 0;
      
      return upper_bound(nums, target) - lower_bound(nums, target) + 1;
    }

    // 查找上边界
    int upper_bound(vector<int>& nums, int target) {
      int l = 0, r = nums.size() - 1, mid = 0;

      // 查找target的上边界
      while (l < r) {
        mid = l + (r - l) / 2 + 1;

        if (nums[mid] <= target)
          l = mid;
        else
          r = mid - 1;
      }

      return nums[l] == target ? l : -1;
    }

    // 查找下边界
    int lower_bound(vector<int>& nums, int target) {
      int l = 0, r = nums.size() - 1, mid = 0;

      // 查找target的下边界
      while (l < r) {
        mid = l + (r - l) / 2;

        if (nums[mid] >= target)
          r = mid;
        else
          l = mid + 1;
      }

      return nums[l] == target ? l : 0;
    }
};

int main() {
  vector<int> inputs = {5,7,7,8,8,8,8,8,8,10};
  int target = 7;
  Solution ss;
  cout << ss.search(inputs, target);
  return 0;
}
