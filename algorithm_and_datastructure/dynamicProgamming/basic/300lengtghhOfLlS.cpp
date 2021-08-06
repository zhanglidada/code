#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 采用动态规划的方式
/*
class Solution {
  public:
    int lengthOfLIS(vector<int>& nums) {
      int len = nums.size();
      // dp[i] 表示以i结尾的数组中，最长连续子数组的长度(nums[i]) 必须被选中
      vector<int> dp(len, 0);
      for (int i = 0; i < len; i++) {
        dp[i] = 1;  // 初始化以当前元素结尾的最长递增子序列长度
        for (int j = 0; j < i; j++) {
          if (nums[i] > nums[j])
            dp[i] = max(dp[j]  + 1, dp[i]);
        }
      }
      return *max_element(dp.begin(), dp.end());
    }
};  */

// 采用贪心 + 二分查找
// 目的是为了让子序列递增速度放慢
class Solution {
  public:
    int lengthOfLIS(vector<int>& nums) {
      int n = nums.size();
      // 初始化递增子序列的长度
      int len = 1;
      dp = vector<int>(n + 1, 0);

      // 长度为1的最长递增子序列初始化为起始元素
      dp[1] = nums[0];
      for (int i = 1; i < n; i++) {
        if (nums[i] > dp[len]) {
          dp[++len] = nums[i];
        } else {
          // 二分查找其在dp数组中的位置并替换
          int pos = binarySort(dp, len, nums[i]);
          dp[pos] = nums[i];
        }
      }
      return len;
    }
    // 传递当前数组中有效长度
    int binarySort(vector<int>& dp, int len, int input) {
      int l = 1, r = len;
      int mid = (l + r) / 2;
      while (l <= r) {
        mid = (r + l) / 2;
        if (dp[mid] < input) {
          l = mid + 1;
        } 
        else {
          r = mid - 1;
        }
      }
      return r + 1;
    }
  private:
    vector<int> dp;
};
int main() {
  vector<int> nums = {1,3,6,7,9,4,10,5,6};
  Solution ss;
  cout << ss.lengthOfLIS(nums);
  return 0;
}