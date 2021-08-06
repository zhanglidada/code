#include <iostream>
#include <vector>
using namespace std;

/*
// 前缀和加二分查找的方法
class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    if (nums.size() == 0)
      return 0;
    int ans = INT32_MAX;
    int n = nums.size();
    vector<int> sums(n + 1, 0);
    // 计算前缀和，由于nums中的值均>0，所以sums数组是递增数组
    // sums[i]是nums[0] --> nums[i-1]的元素之和
    for (int i = 1; i <= n; i++) {
      sums[i] = sums[i - 1] + nums[i - 1]; 
    }
    for (int i = 0; i < n; i++) {
      int target = s + sums[i];
      int bound = lowerBound(sums, i + 1, n, target);
      if (bound != -1)
        ans = min(ans, bound - i);
    }
    return ans == INT32_MAX ? 0 : ans;
  }
  // 用二分查找的方式获得值>=target的最小数组下标
  int lowerBound(vector<int>& sums, int left, int right, int target) {
    int mid = -1;
    while (left < right) {
      mid = (left + right) / 2;
      if (sums[mid] == target)
        return mid;
      else if (sums[mid] < target)
        left = mid + 1;  // left是最先可能满足条件的位置
      else
        right = mid;
    }
    return sums[left] >= target ? left : -1;
  }
};  */

// 采用双指针的方式
class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    if (nums.size() == 0)
      return 0;
    int sum = 0, start = 0, end = 0;
    int ans = INT32_MAX;
    while (end < nums.size()) {
      sum += nums.at(end);
      while (sum >= s) {
        ans = min(ans, end - start + 1);
        sum -= nums[start];
        start ++;
      }
      if (sum < s)
        end ++;
    }
    ans = ans == INT32_MAX ? 0 : ans;
    return ans;
  }
};
int main() {
  int s = 7;
  vector<int> nums = {2,3,1,2,4,3};
  Solution ss;
  cout << ss.minSubArrayLen(s, nums);
  return 0;
}