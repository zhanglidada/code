#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
      int n = cost.size();
      if (n <= 1)  return n == 0 ? 0 : cost[0];
      vector<int> dp(n, 0);
      // 初始化dp数组
      dp[0] = cost[0];
      dp[1] = cost[1];
      for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
      }
      return min(dp[n - 1], dp[n - 2]);
    }
};


int main() {
  return 0;
}