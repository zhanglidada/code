#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 采用动态规划的方式
/*
class Solution {
  public:
    int coinChange(vector<int>& coins, int amount) {
      int MAX = amount + 1;
      vector<int> dp(amount + 1, MAX);
      dp[0] = 0;
      int n = coins.size();
      for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
          // 可以从i-cj状态转移得到
          if (i >= coins[j]) {
            dp[i] = min(dp[i], dp[i - coins[j]] + 1);
          }
        }
      }
      return dp[amount] > amount ? -1 : dp[amount];
    }
};  */

// 记忆化搜索，使用了一个记忆化数组
class Solution {
  public:
    int coinChange(vector<int>& coins, int amount) {
      if (amount < 1) {
        return 0;
      }
      count.resize(amount, 0);
      // 返回递归后的结果
      return dp(coins, amount);
    }
    int dp(vector<int>& coins, int remember) {
      if (remember < 0)  return -1;
      // 当前找到了初始位置，返回0
      if (remember == 0)  return 0;
      if (count[remember - 1] != 0)  return count[remember - 1];
      
      int Min = INT32_MAX;
      for (auto coin : coins) {
        int res = dp(coins, remember - coin);
        if (res >= 0 && res < Min)
          Min = res;
      }
      count[remember - 1] = Min == INT32_MAX ? -1 : Min + 1;
      return count[remember - 1];
    }
  private:
    // 记忆化数组
    vector<int> count;
};

int main() {
  int amount = 3;
  vector<int> nums = {2};
  Solution ss;
  cout << ss.coinChange(nums, amount);
  return 0;
}