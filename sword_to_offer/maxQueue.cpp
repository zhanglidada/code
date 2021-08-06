#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MaxQueue {
 public:
  MaxQueue() {
  }
  int max_value() {
    if (!deq.empty())  return deq.front();
    return -1;
  }
  void push_back(int value) {
    que.push(value);
    while (!deq.empty() && deq.back() < value)
      deq.pop_back();
    deq.push_back(value);
  }
  int pop_front() {
    if (que.empty())  return -1;
    int ans = que.front();
    que.pop();
    if (deq.front() == ans)
      deq.pop_front();
    return ans;
  }
 private:
  queue<int> que;
  deque<int> deq;  // 单调递减
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */