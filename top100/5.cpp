#include <iostream>
#include <vector>
using namespace std;

/* 暴力解法
class Solution {
 public:
  string longestPalindrome(string s) {
    int len = s.size();
    int maxLen = 1, begin = 0;
    if (len < 2)  return s;
    for (int i = 0; i < len - 1; i++) {
      for (int j = i + 1; j < len; j++) {
        if (j - i + 1 > maxLen && isPalindromic(s, i, j)) {
          maxLen = j - i + 1;
          begin = i;
        }
      }
    }
    return s.substr(begin, maxLen);
  }
 private:
  bool isPalindromic(string s, int st, int en) {
    while (st <= en) {
      if (s[st] != s[en]) return false;
      st++;
      en--;
    }
    return true;
  }
};  */

/* 中心扩散法
class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.size() < 2)  return s;
    int begin = 0, maxLen = 0;
    // 其实i最多到size - 2位置即可
    for (int i = 0; i < s.size() - 1; i++) {
      // 奇数的情况
      auto res1 = expandAroundCenter(s, i, i);
      int left1 = res1.first, right1 = res1.second;
      auto res2 = expandAroundCenter(s, i, i + 1);
      int left2 = res2.first, right2 = res2.second;
      if (right1 - left1 + 1 > maxLen) {
        maxLen = right1 - left1 + 1;
        begin = i - (maxLen - 1) / 2;
      }
      if (right2 - left2 + 1 > maxLen) {
        maxLen = right2 - left2 + 1;
        begin = i - (maxLen - 1) / 2;
      }
    }
    return s.substr(begin, maxLen);
  }
  pair<int, int> expandAroundCenter(string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      left--;
      right++;
    }
    return pair<int, int>({left + 1, right - 1});
  }
};  */

// 动态规划算法
class Solution {
 public:
  string longestPalindrome(string s) {
    int maxLen = 1, begin = 0;
    int len = s.size();
    if (len < 2)  return s;
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    for (int i = 0; i < len; i++)  dp[i][i] = true;
    // 按列遍历，且由于子串s[i][j]中i位置肯定小于j
    for (int j = 1; j < len; j++) {
      for (int i = 0; i < j; i++) {
        if (s[i] != s[j])  dp[i][j] = false;
        else {
          if (j - i < 3)  dp[i][j] = true;
          else  dp[i][j] = dp[i + 1][j - 1];
        }
        // 只要dp[i][j] = true, 即字串s[i][j]是回文字串，那么判断长度
        if (dp[i][j] && (j - i + 1) > maxLen) {
          maxLen = j - i + 1;
          begin = i;
        }
      }
    }
    return s.substr(begin, maxLen);
  }
};

int main() {
  string s = "a";
  Solution ss;
  cout << ss.longestPalindrome(s);
}