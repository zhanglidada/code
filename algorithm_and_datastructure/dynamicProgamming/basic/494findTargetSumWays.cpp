#include <iostream>
#include <vector>
using namespace std;

// 首先想到的就是采用回溯算法
class Solution {
  public:
    int findTargetSumWays(vector<int>& nums, int target) {
      // 回溯算法的起始位置
      backtrack(nums, target, 0, 0);
      return count;
    }
    void backtrack(vector<int>& nums, int target, int index, int sum) {
      // 已经遍历到最后一个元素
      if (index == nums.size()) {
        if (target == sum) {
          count ++;
        }
      } else {
        // 分别在当前元素之前添加 +/-
        backtrack(nums, target, index + 1, sum + nums[index]);
        backtrack(nums, target, index + 1, sum - nums[index]);
      }
    }
  private:
    int count = 0;
};

// 转换为01背包问题，因为每个元素有且仅有一个
class Solution {
  public:
    int findTargetSumWays(vector<int>& nums, int target) {
      int len = nums.size();
      int sum = 0;
      int x = 0;
      for (int i = 0; i < len; i++) {
        sum += nums[i];
      }
      
      // 此时没有方案
      if (abs(target) > abs(sum))  return 0;
      if ((sum + target) % 2)  return 0;

      x = (sum + target) / 2;
      vector<int> dp(x + 1, 0);
      dp[0] = 1;
      for (int i = 0; i < len; i++) {
        for (int j = x; j >= nums[i]; j--) {
          dp[j] += dp[j - nums[i]];
        }
      }
      return dp[x];
    }
};