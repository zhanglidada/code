#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * @brief 
 * propose：
 *    根据栈的压入序列，判断另一个序列是否为栈的出栈序列
 * notes:
 *    栈中不存在重复数字
 */
class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;  // 使用一个栈模拟出栈序列
    int i = 0;  // poped栈中访问元素位置
    for (auto num : pushed) {
      st.push(num);
      while (!st.empty() && st.top() == popped[i]) {
        st.pop();
        i++;
      }
    }
    return st.empty();
  }
};