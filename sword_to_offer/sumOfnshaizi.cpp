#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 动态规划方式
class Solution {
 public:
  vector<double> twoSum(int n) {
    // dp[n][s] 表示n个骰子，向上点数之和为s的次数
    vector<vector<int>> dp(n + 1, vector<int>(6 * n + 1, 0));
    for (int i = 1; i <= 6; i++)
      dp[1][i] = 1;
    for (int i = 2; i <= n; i++) {
      for (int s = i; s <= 6*i; s++) {
        // d为当前节点可以存在的点数
        for (int d = 1; d <= 6; d++) {
          if (s - d < i - 1)  break;
          dp[i][s] += dp[i - 1][s - d];
        }
      }
    }
    double total = pow(double(6), double(n));
    vector<double> res;
    for (int i = n; i <= 6*n; i++) {
      res.push_back((double)dp[n][i] / total);
    }
    return res;
  }
};

// 对动态规划的空间进行优化
class Solution {
 public:
  vector<double> twoSum(int n) {
    // dp[n][s] 表示n个骰子，向上点数之和为s的次数
    vector<int> dp(6 * n + 1, 0);
    for (int i = 1; i <= 6; i++)
      dp[i] = 1;
    for (int i = 2; i <= n; i++) {
      for (int s = 6*i; s >= i; s--) {
        // 从后往前遍历，且当前节点的值归零
        dp[s] = 0;
        // d为当前节点可以存在的点数
        for (int d = 1; d <= 6; d++) {
          if (s - d < i - 1)  break;
          dp[s] += dp[s - d];
        }
      }
    }
    double total = pow(double(6), double(n));
    vector<double> res;
    for (int i = n; i <= 6*n; i++) {
      res.push_back((double)dp[i] / total);
    }
    return res;
  }
};