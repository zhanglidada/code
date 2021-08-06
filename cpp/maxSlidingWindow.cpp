#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 采用双端队列的方法
// class Solution {
//  public:
//   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     vector<int> res;
//     if (nums.size() * k == 0)  return res;
//     if (k == 1)  return nums;
//     this->nums = nums;
//     deque<int> deq;  // 存放的是nums中数字的索引
//     // 初始化队列
//     for (int i = 0; i < k; i ++) {
//       clean_deque(deq, i, k);
//       deq.push_back(i);
//     }
//     res.push_back(nums[deq.front()]);
//     for (int i = k; i < nums.size(); i++) {
//       clean_deque(deq, i, k);
//       deq.push_back(i);
//       res.push_back(nums[deq.front()]);
//     }
//     return res;
//   }
//   // i是当前要插入元素的下标，k为窗口大小
//   void clean_deque(deque<int>& deq, int i, int k) {
//     // 如果当前元素插入之前，deq中包含了k个元素(其实就是deq中元素严格递减)，则删除队头
//     if (!deq.empty() && deq.front() == i - k)  deq.pop_front();
//     while (!deq.empty() && nums[deq.back()] < nums[i])  deq.pop_back();
//   }
//   vector<int> nums;
// };

// 采用dp方式
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    if (nums.size() * k == 0)  return res;
    if (k == 1)  return nums;
    int len = nums.size();
    vector<int> left(len, 0), right(len, 0);
    left[0] = nums[0], right[len - 1] = nums[len - 1];
    for (int i = 1; i < len; i++) {
      // from left to right
      if (i % k == 0)  left[i] = nums[i];  // 一个块的开始
      else left[i] = max(left[i - 1], nums[i]);
      // from right to left
      int j = len - i - 1;
      if ((j + 1) % k == 0)  right[j] = nums[j];  // 一个块的结束位置
      else  right[j] = max(right[j + 1], nums[j]);
    }
    for (int i = 0; i < len - k + 1; i++) {
      res.push_back(max(right[i], left[i + k - 1]));
    }
    return res;
  }
};
int main() {
  vector<int> input = {-6,-10,-7,-1,-9,9,-8,-4,10,-5,2,9,0,-7,7,4,-2,-10,8,7};
  Solution ss;
  vector<int> res = ss.maxSlidingWindow(input, 7);
  for (auto num : res) {
    cout << num << " ";
  }

}