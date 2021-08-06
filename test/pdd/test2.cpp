#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int func(vector<vector<int>>& mat) {
//   int n = mat.size();
//   int m = mat[0].size();
//   vector<vector<int>> dp(n, vector<int>(m, 0));
//   vector<vector<bool>> visit(n, vector<bool>(m, false));
//   int maxVal = INT32_MIN;
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < m; j++) {
//       if (i == 0 && j == 0)  dp[i][j] = mat[i][j];
//       else if (i == 0) dp[i][j] = dp[i][j - 1] + mat[i][j], maxVal = max(maxVal, dp[i][j]);
//       else if (j == 0) dp[i][j] = dp[i - 1][j] + mat[i][j], maxVal = max(maxVal, dp[i][j]);
//       else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1, maxVal = max(maxVal, dp[i][j]);
//     }
//   }
//   return maxVal;
// }
// 其实是深度优先搜索最大联通子图

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> input(n, vector<int>(m, 0));
  for (int i = 0; i< n; i++) {
    for (int j = 0; j < m; j++) {
      int value;
      cin >> value;
      input[i][j] = value;
    }
  }
  cout << func(input);
  return 0;
}