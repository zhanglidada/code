#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxValue (vector<vector<int>>& inputs, int m) {
  int n = inputs.size();
  vector<int> weights(n + 1, 0);
  vector<int> value(n + 1, 0);
  for (int i = 0; i < n; i++) {
    weights[i + 1] = inputs[i][0];
    value[i + 1] = inputs[i][0];
  }
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (weights[i] > j)  dp[i][j] = dp[i - 1][j];
      else 
        dp[i][j] = dp[i - 1][j] > dp[i - 1][j - weights[i]] + value[i] ? dp[i - 1][j] : dp[i - 1][j - weights[i]] + value[i];
    }
  }
  return dp[n][m];
}
int main() {
  int n ,m;
  cin >> n >> m;
  vector<vector<int>> cv;
  vector<int> tmp;
  while (n) {
    tmp.clear();
    int c,v;
    cin >> c >> v;
    tmp.push_back(c);
    tmp.push_back(v);
    cv.push_back(tmp);
    n--;
  }
  cout << maxValue(cv, m);
}