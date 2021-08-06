#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty())  return 0;
    int len = prices.size();
    vector<int> dp(len, 0);
    int mi = prices[0];
    for (int i = 1; i < len; i++) {
      mi = min(mi, prices[i]);
      dp[i] = max(dp[i - 1], prices[i] - mi);
    }
    return dp[len - 1];
  }
};

// 优化一下动态规划的空间
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty())  return 0;
    int len = prices.size();
    int cost = 0;
    int mi = prices[0];
    for (int i = 1; i < len; i++) {
      mi = min(mi, prices[i]);
      cost = max(cost, prices[i] - mi);
    }
    return cost;
  }
};