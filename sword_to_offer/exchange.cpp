#include <iostream>
#include <vector>
using namespace std;

/* 利用头尾指针法
class Solution {
 public:
  vector<int> exchange(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      while (nums[l] % 2) {
        l++;
        if (l >= r)
          break;
      }
      while (nums[r] % 2 == 0) {
        r--;
        if (l >= r)
          break;
      }
      if (l < r) {
        int tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
      }
    }
    return nums;
  }
};  */

/* 单指针法
class Solution {
 public:
  vector<int> exchange(vector<int>& nums) {
    int odd = 0, i = 0;
    while (i < nums.size()) {
      if (nums[i] % 2)
        swap(nums[i++], nums[odd++]);
      else
        i++;
    }
    return nums;
  }
};  */

// 定义快慢双指针法
class Solution {
 public:
  vector<int> exchange(vector<int>& nums) {
    int fast = 0, low = 0;
    while (fast < nums.size()) {
      if (nums[fast] % 2) {
        swap(nums[fast], nums[low]);
        low ++;
      }
       fast ++;
    }
    return nums;
  }
}; 