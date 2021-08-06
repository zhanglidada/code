#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 采用动态规划的方式
/*
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len <= 1)  return 0;
    vector<vector<int>> dp(len, vector<int>(2, 0));

    dp[0][0] = 0;
    dp[0][1] = - prices[0];
    
    // 此处可以连续
    for (int i = 1; i < len; i++) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }

    // 最后一天肯定不持股
    return dp[len - 1][0];
  }
};  */

// 优化内存
/*
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len <= 1)  return 0;
    int dp[2] = {0};

    dp[0] = 0;
    dp[1] = - prices[0];
    
    // 此处可以连续
    for (int i = 1; i < len; i++) {
      dp[0] = max(dp[0], dp[1] + prices[i]);
      dp[1] = max(dp[1], dp[0] - prices[i]);
    }

    // 最后一天肯定不持股
    return dp[0];
  }
};  */

// 采用贪心算法
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len <= 1)  return 0;
    int ans = 0;
    for (int i = 1; i < len; i++) {
      ans += max(0, prices[i] - prices[i - 1]);
    }
    return ans;
  }
};

int main() {
  return 0;
}