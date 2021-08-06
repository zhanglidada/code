#include <iostream>
#include <vector>
using namespace std;

// 采用动态规划的方式
class Solution {
  public:
    int uniquePaths(int m, int n) {
      vector<vector<int>> dp(m, vector<int>(n, 0));

      // 初始化边界条件
      for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
      }
      for (int j = 0; j < n; j++) {
        dp[0][j] = 1;
      }

      for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
      }

      return dp[m - 1][n - 1];
    }
};

// 进行空间的优化，因为当前状态只与左以及上方状态有关
class Solution {
  public:
    int uniquePaths(int m, int n) {
      // 第一行全部都初始化为1
      vector<int> dp(n, 1);
      for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
          // dp[0] 始终为1
          dp[j] = dp[j] + dp[j - 1];
        }
      }
      return dp[n - 1];
    }
};

int main() {
  return 0;
}