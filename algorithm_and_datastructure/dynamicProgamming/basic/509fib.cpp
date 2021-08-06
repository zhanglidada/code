#include <iostream>
#include <vector>
using namespace std;

// 动态规划的优化
class Solution {
  public:
    int fib(int n) {
      if (n <= 1)  return n;
      int sum = 0;
      vector<int> dp(2);
      dp[0] = 0;
      dp[1] = 1;
      for (int i = 2; i <= n; i++) {
        sum = dp[0] + dp[1];
        dp[0] = dp[1];
        dp[1] = sum;
      }
      return sum;
    }
};

// 递归方法，时间复杂度以及空间复杂度过高
class Solution {
  public:
    int fib(int n) {
      if (n <= 1)  return n;
      return fib(n - 1) + fib(n - 2);
    }
};

int main() {

}