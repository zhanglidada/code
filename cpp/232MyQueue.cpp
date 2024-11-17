#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>

class MyQueue {
  public:
    MyQueue() {
      s_in = stack<int>();
      s_out = stack<int>();
    }
    
    void push(int x) {
      s_in.push(x);
    }
    
    int pop() {
      // 二者均空返回-1（不可能存在）
      if (s_out.empty() && s_in.empty()) {
          return -1;
      }

      // 输出栈为空，则将输入栈全部弹出并填充到输出栈中
      if (s_out.empty()) {
        while (!s_in.empty()) {
          s_out.push(s_in.top());
          s_in.pop();
        }
      }

      auto res = s_out.top();
      s_out.pop();

      return res;
    }
    
    int peek() {
      if (s_out.empty() && s_in.empty()) {
        return -1;
      }

      // 输出栈为空，将输入栈压到输出栈中
      if (s_out.empty()) {
        while (!s_in.empty()) {
          s_out.push(s_in.top());
          s_in.pop();
        }
      }

      return s_out.top();
    }
    
    bool empty() {
      return s_in.empty() && s_out.empty();
    }

  private:
    stack<int> s_in;
    stack<int> s_out;
};
