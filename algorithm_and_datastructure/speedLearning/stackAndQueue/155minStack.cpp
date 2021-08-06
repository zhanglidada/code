#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 利用两个栈来实现
class MinStack {
 public:
  /** initialize your data structure here. */
  MinStack() {
    stack2.push(INT32_MAX);
  }
  
  void push(int x) {
    stack1.push(x);
    stack2.push(min(stack2.top(), x));
  }
  
  void pop() {
    stack1.pop();
    stack2.pop();
  }
  
  int top() {
    return stack1.top();
  }
  
  int getMin() {
    return stack2.top();
  }
 private:
  stack<int> stack1, stack2;
};

// 利用一个栈来实现
class MinStack {
 public:
  /** initialize your data structure here. */
  MinStack() {
    
  }
  
  void push(int x) {
    // 初始判断入栈
    if (stack1.size() == 0) {
      stack1.push({x, x});
    } else {
      stack1.push({x, min(stack1.top().second, x)});
    }
  }
  
  void pop() {
    stack1.pop();
  }
  
  int top() {
    return stack1.top().first;
  }
  
  int getMin() {
    return stack1.top().second;
  }
 private:
  stack<pair<int, int>> stack1;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main() {

}