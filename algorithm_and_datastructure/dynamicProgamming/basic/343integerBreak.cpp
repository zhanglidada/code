#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 采用动态规划的方式
/*
class Solution {
  public:
    int integerBreak(int n) {
      vector<int> dp(n + 1, 0);
      for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
          dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
        }
      }
      return dp[n];
    }
};  */

// 优化动态规划的方法，j最多只需要到 i / 2 即可
/*
class Solution {
  public:
    int integerBreak(int n) {
      vector<int> dp(n + 1, 0);
      for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i / 2; j++) {
          dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
        }
      }
      return dp[n];
    }
};  */

// 采用数学方法，将n尽可能拆分成3的倍数
class Solution {
  public:
    int integerBreak(int n) {
      // 此处是题目要求，因为n必须拆分为至少两个正整数
      if (n <= 3)  return n - 1;
      int a = n / 3;
      int b = n % 3;
      // cout << a << " " << b << endl;
      int res = 0;
      if (b == 0)  res = pow(3, a);
      else if (b == 1)  res = pow(3, a - 1) * 4;
      else if (b == 2)  res = pow(3, a) * 2;

      return res;
    }
};


int main() {
  Solution ss;
  int n = 10;
  cout << ss.integerBreak(n);
  
}