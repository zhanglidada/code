#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class CQueue {
  public:
    CQueue() {
    }
    
    void appendTail(int value) {
      st1.push(value);
    }
    
    int deleteHead() {
      res = -1;

      if (!st2.empty()) {
        res = st2.top();
        st2.pop();
        return res;
      }
      else if (!st1.empty()) {
        while (!st1.empty()) {
          st2.push(st1.top());
          st1.pop();
        }
        res = st2.top();
        st2.pop();
        return res;
      }

      return res;
    }

  private:
    stack<int> st1;
    stack<int> st2;
    int res = -1;
};