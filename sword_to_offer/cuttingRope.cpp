#include <iostream>
#include <vector>
using namespace std;

/* 这个其实是找规律
class Solution {
 public:
  int cuttingRope(int n) {
    if (n <= 3)
      return n - 1;
    int res = 1;
    // 本身长度为4或者可以分成长度为4的子绳子
    if (n % 3 == 1)  res *= 4, n -= 4;
    // 本身长度为5或者可以分成长度为5的子绳子
    else if (n % 3 == 2)  res *= 2, n -= 2;
    // 子串或者本身长度为3的倍数
    while (n) {
      res *= 3;
      n -= 3;
    }
    return res;
  }
};  */

// 动态规划的方式,时间复杂度高了一点
class Solution {
 public:
  int cuttingRope(int n) {
    if (n <= 3)
      return n - 1;
    vector<int> dp;
    dp.resize(n + 1);
    // 初始化值
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= n; i++) {
      int res = 0;
      for (int j = 1; j <= i / 2; j++) {
        res = max(res, dp[j] * dp[i - j]);
      }
      dp[i] = res;
    }
    return dp[n];
  }
};
int main() {
  return 0;
}