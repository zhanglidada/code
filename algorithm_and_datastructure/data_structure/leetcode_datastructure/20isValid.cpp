#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <stack>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * Notes:
 * 1.左括号必须用相同类型的右括号闭合。
 * 2.左括号必须以正确的顺序闭合。
********************************************************************************************/


/*******************************************************************************************
 * Notes:
 * 很容易就想到使用栈检测括号的出现顺序。新的括号入栈，配对的括号出栈
********************************************************************************************/
class Solution {
  public:
    bool isValid(string s) {
      for (auto c : s) {
        // 左括号一律进栈
        if (c == '(' || c == '[' || c == '{')
          st.push(c);
        // 右括号进行判断，匹配出栈，不匹配报错
        else {
          // 右括号出现时栈为空，返回false
          if (st.empty()) return false;

          // 判断右括号是否和左括号匹配
          if (is_match(c))
            st.pop();
          else
            return false;
        }
      }

      // 匹配结束后栈中仍有元素未配对，返回false
      if (!st.empty())
        return false;

      return true;
    }

    // 当前字符是否与栈顶字符匹配
    bool is_match(char c) {
      if ((st.top() == '(' && c == ')')
          || (st.top() == '[' && c == ']') 
          || (st.top() == '{' && c == '}'))
        return true;
      return false;
    }
  private:
    stack<char> st;
};