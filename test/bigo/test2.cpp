#include <iostream>
#include <vector>
using namespace std;

int uniquepathWithObstacles(vector<vector<int>>& obstaclesGrid) {
  int n = obstaclesGrid.size(), m = obstaclesGrid[0].size();
  vector<vector<int>> dp(n, vector<int>(m, 0));
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 && j == 0) {
        dp[i][j] = 1;
        continue;
      }
      if (obstaclesGrid[i][j] == 0) {
        if (i != 0 && j != 0)
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        else if (i == 0)
          dp[i][j] = dp[i][j - 1];
        else if (j == 0)
          dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[n - 1][m - 1];
}