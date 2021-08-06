#include <iostream>
#include <vector>
using namespace std;

// 利用动态规划
class Solution {
 public:
  int translateNum(int num) {
    string numstr = to_string(num);
    int len = numstr.size();
    if (len < 2)  return len;
    vector<int> dp(len + 1, 0);
    dp[0] = 1;
    dp[1] = 1;  // 以第一个字符结尾的个数
    for (int i = 1; i < len; i++) {
      int currentnum = 10 * (numstr[i - 1] - '0') + numstr[i] - '0';
      dp[i + 1] = dp[i];
      if (currentnum >= 10 && currentnum <= 25)
        dp[i + 1] += dp[i - 1];
    }
    return dp[len];
  }
};
// 优化空间复杂度
class Solution {
 public:
  int translateNum(int num) {
    string numstr = to_string(num);
    int len = numstr.size();
    if (len < 2)  return len;
    
    int dp0 = 1;  // 用以解决递归的初始问题
    int dp1 = 1;  // 以第一个字符结尾的个数
    int cur;
    for (int i = 1; i < len; i++) {
      int currentnum = 10 * (numstr[i - 1] - '0') + numstr[i] - '0';
      cur = dp1;
      if (currentnum >= 10 && currentnum <= 25)
        cur += dp0;
      dp0 = dp1;
      dp1 = cur;
    }
    return cur;
  }
};