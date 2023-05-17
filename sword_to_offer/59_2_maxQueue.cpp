#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * @brief 
 * 利用一个单调递减的双端队列
 */
class MaxQueue {
 public:
  MaxQueue() {
  }

  int max_value() {
    // 获取deque的头元素
    if (!deq.empty())
      return deq.front();
    
    return -1;
  }

  void push_back(int value) {
    que.push(value);

    // 在单调递减的deque中插入当前元素
    while (!deq.empty() && deq.back() < value)
    {
      deq.pop_back();
    }
    deq.push_back(value);
  }

  int pop_front() {
    int ans = 0;

    if (que.empty())
      return -1;

    ans = que.front();
    que.pop();

    // 当前出栈的元素为deque中最大元素
    if (deq.front() == ans)
      deq.pop_front();
    
    return ans;
  }
 private:
  queue<int> que;
  deque<int> deq;  // 保存到当前插入元素为止的单调递减序列
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */