#include <iostream>
#include <vector>
using namespace std;

/*
// 动态规划的方式
class Solution {
 public:
  bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    // 边界情况
    dp[0][0] = true;
    for (int j = 1; j <= m; j++) {
      if (p[j - 1] == '*')
        dp[0][j] = true;
      else
        break;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
          dp[i][j] = dp[i - 1][j - 1];
        else if (p[j - 1] == '*')
          dp[i][j] = (dp[i][j - 1] | dp[i - 1][j]);
      }
    }
    return dp[n][m];
  }
};  */

// 贪心算法
class Solution {
 public:
  bool isMatch(string s, string p) {
    auto allStars = [](string s, int left, int right) {
      for (int i = left; i < right; i++)
        if (s[i] != '*')
          return false;
      return true;
    };
    auto charMatch = [](char sChar, char pChar) {
      return sChar == pChar || pChar == '?';
    };
    // 先从最后开始匹配，直到满足p的末尾为*，即可以进行贪心
    while (p.size() && s.size() && p.back() != '*') {
      if (charMatch(s.back(), p.back())) {
        s.pop_back();
        p.pop_back();
      } else
        return false;
    }
    if (p.empty())
      return s.empty();
    /* 用sIndex和pIndex表示当前遍历到的位置
       在s中寻找某个字串u_i
       其在s和p中的起始位置为sRecord和pRecord
    */
    int sIndex = 0, pIndex = 0;
    int pRecord = -1, sRecord = -1;
    while (sIndex < s.size() && pIndex < p.size()) {
      // 重新始进行贪心计算
      if (p[pIndex] == '*') {
        // 说明p中的u_i的位置已经找到
        pIndex ++;
        // 记录搜索u_i+1的起始位置
        sRecord = sIndex;
        pRecord = pIndex;
      } else if (charMatch(s[sIndex], p[pIndex])) {
        ++sIndex;
        ++pIndex;
      } else if (sRecord != -1 && sRecord + 1 < s.size()) {
        /*
          字符不匹配，需要重新寻找u_i(此时pRecord-1的位置上元素为*)
          sRecord不为-1表示不是从s第一个字符开始的字串匹配
          枚举s的下一个起始位置
        */
        ++sRecord;
        sIndex = sRecord;
        pIndex = pRecord;
      } else {
        // 不匹配，即sRecord == -1,下一个起始位置不存在
        return false;
      }
    }
    // 用于保证p最后如果不为空，剩余的全是*
    return allStars(p, pIndex, p.size());
  }
};
int main() {
  Solution ss;
  string s = "ab", p = "?*";
  cout << ss.isMatch(s, p);
  return 0;
}