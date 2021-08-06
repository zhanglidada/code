#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// 采用动态规划方式
/*
class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = 0, dp[0][1] = -prices[0];
    for (int i = 1; i < n; ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[n - 1][0];
  }
};  */

// 动态规划的空间优化
class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    int sell = 0, buy = -prices[0];
    for (int i = 1; i < n; ++i) {
      // 考虑到sell以及buy均由前一天的状态转移得到，且仅仅与前一天的状态有关
      sell = max(sell, buy + prices[i] - fee);
      
      /* 这里存在两种情况：
         1. sell仍为sell，即sell的值在上面代码中未改变，不影响对buy的计算
         2. sell为buy + prices[i] - fee。 即buy + prices[i] - fee > sell, 那么
            buy = max(buy, buy + prices[i] - fee - prices[i])  ==> buy = max(buy, buy - fee) 
            所以上面的计算对buy的结果没有影响
       */
      buy = max(buy, sell - prices[i]);
    }

    return sell;
  }
};