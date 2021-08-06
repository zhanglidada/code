#include <iostream>
#include <stack>
using namespace std;

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
class CQueue {
 public:
  CQueue() {
    while (!stack1.empty())
      stack1.pop();
    while (!stack2.empty())
      stack2.pop();
  }
  void appendTail(int value) {
    stack1.push(value);
  }
  int deleteHead() {
    while (!stack2.empty()) {
      int res = stack2.top();
      stack2.pop();
      return res;
    }
    if (!stack1.empty()) {
      while (!stack1.empty()) {
        stack2.push(stack1.top());
        stack1.pop();
      }
      int res = stack2.top();
      stack2.pop();
      return res;
    } else {
      return -1;
    }
  }
  stack<int> stack1, stack2;
};
int main() {
  return 0;
}