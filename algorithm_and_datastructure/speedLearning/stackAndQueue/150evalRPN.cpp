#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 逆波兰式s
class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    if (tokens.empty())  return 0;
    stack<int> st;
    for (auto str : tokens) {
      if (str == "+" || str == "-" || str == "*" || str == "/") {
        int num1 = st.top();
        st.pop();
        int num2 = st.top();
        st.pop();
        if (str == "+") st.push(num2 + num1);
        if (str == "-") st.push(num2 - num1);
        if (str == "*") st.push(num2 * num1);
        if (str == "/") st.push(num2 / num1);
      } else {
        st.push(stoi(str));
      }
    }
    int res = st.top();
    st.pop();  // 将最后的结果弹出
    return res;
  }
};