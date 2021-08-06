#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianFinder {
 public:
  /** initialize your data structure here. */
  MedianFinder() {
    maxheap = new priority_queue<int>();
    minheap = new priority_queue<int, vector<int>, greater<int>>();
  }
  
  void addNum(int num) {
    int m = minheap->size(), n = maxheap->size();
    if (m == n) {
      maxheap->push(num);
      minheap->push(maxheap->top());
      maxheap->pop();
    } else {
      minheap->push(num);
      maxheap->push(minheap->top());
      minheap->pop();
    }
  }
  
  double findMedian() {
    int m = minheap->size(), n = maxheap->size();
    return m == n ? (minheap->top() + maxheap->top()) / 2.0 : minheap->top();
  }
 private:
  priority_queue<int>* maxheap;
  priority_queue<int, vector<int>, greater<int>>* minheap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */