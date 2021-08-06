#include <iostream>
#include <vector>
using namespace std;
/*
// 采用动态规划的方式
class Solution {
 public:
  int findLength(vector<int>& A, vector<int>& B) {
    int n = A.size(), m = B.size();
    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        // 反向递归
        dp[i][j] = A[i] == B[j] ? dp[i + 1][j + 1] + 1 : 0;
        ans = max(ans, dp[i][j]);
      }
    }
    return ans;
  }
};  */

// 采用滑动窗口
class Solution {
 public:
  int findLength(vector<int>& A, vector<int>& B) {
    int n = A.size(), m = B.size();
    int ans = 0;
    for (int i = 0; i < n; i ++) {
      int len = min(m ,n - i);
      int maxLen = maxLength(A, B, i, 0, len);
      ans = max(ans, maxLen);
    }
    for (int j = 0; j < m; j++) {
      int len = min(n, m - j);
      int maxLen = maxLength(A, B, 0, j, len);
      ans = max(ans, maxLen);
    }
    return ans;
  }
  // A,B数组从指定窗口位置进行逐个匹配进行匹配
  int maxLength(vector<int>& A, vector<int>& B, int addA, int addB, int len) {
    int ans = 0;
    int k = 0;
    for (int i = 0; i < len; i ++) {
      if (A[addA + i] == B[addB + i])
        k ++;
      else
        k = 0;
      ans = max(ans, k);
    }
    return ans;
  }
};
int main() {
  vector<int> A = {1,2,3,2,1};
  vector<int> B = {3,2,1,4,7};
  Solution ss;
  cout << ss.findLength(A, B) << endl;
  return 0;
}