#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * @brief 
 * 使用一个单调递减的双端队列，每次滑动窗口时和队尾元素比较
 * 当前新遍历元素大于队尾元素，将队尾元素出队并继续比较队尾
 * 
 */
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k)
  {

    // 特殊情况直接返回
    if (nums.empty() || k == 0)  return res;
    
    // 未形成窗口
    for (int i = 0; i < k; i++)
    {
      while (!deq.empty() && deq.back() < nums[i])
      {
        deq.pop_back();
      }

      deq.push_back(nums[i]);
    }

    // 当前窗口的队头元素为最大元素
    res.push_back(deq.front());

    for (int i = k; i < nums.size(); i++)
    {
      // 当前队列头元素就是前一个窗口的首元素
      if (deq.front() == nums[i - k])
         deq.pop_front();

      while (!deq.empty() && deq.back() < nums[i])
      {
        deq.pop_back();
      }

      deq.push_back(nums[i]);

      res.push_back(deq.front());
    }
    return res;
  }

  private:
    vector<int> res; // 最终的返回数组
    deque<int> deq;
    int resx = INT32_MIN;
};
