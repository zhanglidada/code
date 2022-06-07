#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <stack>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）
 * Notes:
 * 所有的操作均为有效操作
********************************************************************************************/


/*******************************************************************************************
 * Notes:
 * 队列的结构为先进先出
 * 只能使用栈的标准操作，即push to, top, peek, pop from top, size, is empty
********************************************************************************************/
class MyQueue {
  public:
    MyQueue() {
      
    }
    
    void push(int x) {
      // 新增队列元素统一push入st1中
      st1.push(x);
    }

    int pop() {
      int res = 0;
      // 首先判断st2是否为空
      if (st2.empty()) {
        while (!st1.empty()) {
          st2.push(st1.top());
          st1.pop();
        }
      }
      res = st2.top();
      st2.pop();
      return res;
    }
    
    // 获取队列头元素
    int peek() {
      // 当前元素全部在st1中
      if (st2.empty()) {
        while (!st1.empty()) {
          st2.push(st1.top());
          st1.pop();
        }
      }
      return st2.top();
    }
    
    bool empty() {
      return st1.empty() && st2.empty();
    }
  private:
    stack<int> st1;
    stack<int> st2;
};