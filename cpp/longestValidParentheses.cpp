#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
// 采用暴力解法，利用栈来实现；注意有效括号字串的长度为偶数
class Solution {
 public:
  int longestValidParentheses(string s) {
    // 有效字串的长度一定为偶数
    int subStrLen = s.size() % 2 == 0 ? s.size() : s.size() - 1;
    // 不同长度的子串,判断是否有满足长度的字串
    for (int i = subStrLen; i >= 2; i -= 2) {
      isvalid(s, i);
    }
    return maxLen;
  }
  // 根据指定的字串长度判断有效字串是否存在
  void isvalid(string s, int sublen) {
    for (int i = 0; i <= s.size() - sublen; i++) {
      // 不同位置开始的substr
      string substr = s.substr(i, sublen);
      stack<char> stack_tmp;
      for (int j = 0; j < substr.size(); j++) {
        char cr = substr.at(j);
        if (stack_tmp.empty()) {
          // 不管是否匹配，均入栈
          stack_tmp.push(cr);
        } else {
          if (cr == '(')
            stack_tmp.push(cr);
          else {
            if (stack_tmp.top() == '(')
              stack_tmp.pop();
            else
              stack_tmp.push(')');
          }
        }
      }
      maxLen = stack_tmp.empty() ? max(maxLen, sublen) : maxLen;
    }
  }
  int maxLen = 0;
};  */


/*
// 动态规划的方式
class Solution {
 public:
  int longestValidParentheses(string s) {
    vector<int> dp(s.size(), 0);
    int maxLen = 0;
    for (int i = 1; i < dp.size(); i++) {
      if (s[i] == ')' && (i - dp[i - 1] - 1) >= 0 && s[i - dp[i - 1] - 1] == '(') {
        dp[i] = 2 + dp[i - 1];
        // 外部还存在连在一起的有效括号
        if (i - dp[i - 1] - 2 > 0)
          dp[i] += dp[i - dp[i - 1] - 2];
      }
      maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
  }
};  */

/*
// 用栈
class Solution {
 public:
  int longestValidParentheses(string s) {
    stack<int> stack_tmp;
    stack_tmp.push(-1);
    int length = 0, max_length = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(')
        stack_tmp.push(i);
      else {
        stack_tmp.pop();
        if (stack_tmp.empty())
          stack_tmp.push(i);
        else {
          length = i - stack_tmp.top();
          max_length = max(max_length, length);
        }
      }
    }
    return max_length;
  }
};  */

// 正逆向结合法，O(n)时间复杂度，O(1)空间复杂度
class Solution {
 public:
  int longestValidParentheses(string s) {
    int left = 0, right = 0, maxLength = 0;
    // 正向判断
    for (int i = 0; i < s.size(); i++) {
      if (s.at(i) == '(')
        left ++;
      else if (s.at(i) == ')')
        right ++;

      if (left == right)
        maxLength = max(2 * right, maxLength);
      else if (right > left)
        left = right = 0;
    }
    left = right = 0;
    // 逆向判断
    for (int j = s.size() - 1; j >= 0; j--) {
      if (s.at(j) == '(')
        left ++;
      else if (s.at(j) == ')')
        right ++;

      if (left == right)
        maxLength = max(maxLength, 2 * left);
      else if (left > right)
        left = right = 0;
    }
    return maxLength;
  }
};
int main() {
  string s = "())(())";
  Solution ss;
  cout << ss.longestValidParentheses(s);
  return 0;
}