#include <iostream>
#include <vector>
using namespace std;

// 采用动态规划的方式
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
};



int main() {
  
}