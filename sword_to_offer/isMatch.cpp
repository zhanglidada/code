#include <iostream>
#include <vector>
using namespace std;

/* 采用递归的方式
class Solution {
 public:
  bool isMatch(string s, string p) {
    // string的尾字符为'\0'
    if (s[0] == '\0' && p[0] == '\0')
      return true;
    if (s[0] != '\0' && p[0] == '\0')
      return false;
    // s为空，p不为空  ---> s="", p="a*"

    if (p[1] != '*') {  // 匹配当前字符串，若匹配成功就继续向下匹配，否则返回false
      if (s[0] == p[0] || (s[0] != '\0' && p[0] == '.'))
        return isMatch(s.substr(1), p.substr(1));
      else
        return false;
    } else {  // 此时p的第二位为*，那么
      if (s[0] == p[0] || (s[0] != '\0' && p[0] == '.')) {
        // 表示匹配0个字符的情况 || s已经匹配了一位，但是p保持必变 ： s = aab, p = a*b
        return isMatch(s, p.substr(2)) || isMatch(s.substr(1), p);
      }
      else {  // 比如 aa 和 c*aa
        return isMatch(s, p.substr(2));
      }
    }
    return false;
  }
};  */

/* 动态规划的方式
class Solution {
 public:
  bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        // 分成空正则和非空正则两种
        if (j == 0)
          // 空串和空正则匹配，非空串和空正则不匹配
          dp[i][j] = i == 0;
        else {  // 此时j > 0
          // 非空正则分为* 和 非* 两种情况
          if (p[j - 1] != '*') {  // 最后一位不为*，则匹配最后一位，并将s和p前移比较
            if (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.'))
              dp[i][j] = dp[i - 1][j - 1];
          } else {
            // p的最后一位为*,分为看和不看两种

            // 看
            if (i >= 1 && j >= 2 && (p[j - 2] == s[i - 1] || p[j - 2] == '.'))
              dp[i][j] = dp[i - 1][j];
            // 不看
            if (j >= 2)
              dp[i][j] = dp[i][j] || dp[i][j - 2];
          }
        }
      }
    }
    return dp[n][m];
  }
};  */
class Solution {
 public:
  // 采用动态规划的方式,从前往后依次修改前置数组
  bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<int>> dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= n; j++) {
        if (j == 0)  dp[i][j] = i == 0 ? 1 : 0;
        else if (j > 0) {
          if (p[j - 1] != '*'){
            if (i >= 1 && (p[j - 1] == s[i - 1] || p[j - 1] == '.'))
              dp[i][j] = dp[i - 1][j - 1];
          }
          else if (p[j - 1] == '*') {
            // 不匹配
            if (j >= 2)  dp[i][j] |= dp[i][j - 2];
            // 匹配一次或者多次
            if (j >= 2 && i >= 1 && (p[j - 2] == s[i - 1] || p[j - 2] == '.'))
              dp[i][j] |= dp[i - 1][j];
          }
        }
      }
    }
    return dp[m][n];
  }
};
int main() {
  Solution ss;
  cout << ss.isMatch("ab", ".*");
  return 0;
}