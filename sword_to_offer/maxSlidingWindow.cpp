#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 利用一个单调递减的双端队列
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    if (nums.empty() || k == 0)  return res;
    deque<int> deq;
    int resx = INT32_MIN;
    // 未形成窗口
    for (int i = 0; i < k; i++) {
      while (!deq.empty() && deq.back() < nums[i])
        deq.pop_back();
      deq.push_back(nums[i]);
    }
    res.push_back(deq.front());
    for (int i = k; i < nums.size(); i++) {
      if (deq.front() == nums[i - k])  deq.pop_front();
      while (!deq.empty() && deq.back() < nums[i])  deq.pop_back();
      deq.push_back(nums[i]);
      res.push_back(deq.front());
    }
    return res;
  }
};