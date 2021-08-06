#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// 采用动态规划的方式，增加了一个冷冻状态
/*
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1)  return 0;
    // 多设置一个冷冻期状态
    vector<vector<int>> dp(n, vector<int>(3, 0));

    dp[0][0] = -prices[0];  // 当天结束手上持有股票
    dp[0][1] = 0;  // 当天结束手上不持有股票, 且处于冷冻期
    dp[0][2] = 0;  // 当天结束手上不持有股票, 且处于非冷冻期

    for (int i = 1; i < n; i++) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
      dp[i][1] = dp[i - 1][0] + prices[i];
      dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
    }
    return max(dp[n - 1][1], dp[n - 1][2]);
  }
};  */

// 动态规划的空间优化
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty())  return 0;
    int n = prices.size();

    int dp0 = -prices[0];  // 当天结束手上持有股票
    int dp1 = 0;  // 当天结束手上不持有股票, 且处于冷冻期
    int dp2 = 0;  // 当天结束手上不持有股票, 且处于非冷冻期

    vector<int> dp(3, 0);
    for (int i = 1; i < n; i++) {
      dp[0] = max(dp0, dp2 - prices[i]);
      dp[1] = dp0 + prices[i];
      dp[2] = max(dp1, dp2);

      // 前一天的状态更新
      dp0 = dp[0];
      dp1 = dp[1];
      dp2 = dp[2];
    }

    return max(dp[1], dp[2]);
  }
};

int main() {
  return 0;
}