#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
class MinStack {
 public:
    /** initialize your data structure here. */
  MinStack() {
    minStack1 = new stack<int>();
    minStack2 = new stack<int>();
  }
  
  void push(int x) {
    minStack1->push(x);
    if (minStack2->empty())
    {
      minStack2->push(x);
    }
    else if (x <= minStack2->top())
    {
      // 相等时也push
      minStack2->push(x);
    }
  }
  
  void pop() {
    // 先出栈常规栈
    int val = minStack1->top();
    minStack1->pop();
    // 当前值为栈中的最小值，stk2出栈
    if (val == minStack2->top())
      minStack2->pop();
  }
  
  int top() {
    return minStack1->top();
  }
  
  int min() {
    return minStack2->top();
  }
  stack<int> *minStack1;
  stack<int> *minStack2;  // 最小栈
};

int main () {
  vector<int> res;
  sort(res.begin(),res.end());
}