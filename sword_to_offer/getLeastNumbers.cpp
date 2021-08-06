#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <ctime>
using namespace std;

// 排序，并取出前k个数字
class Solution {
 public:
  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    vector<int> res;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < k; i++) {
      res.push_back(arr[i]);
    }
    return res;
  }
};

// 利用大根堆来实现
class Solution {
 public:
  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    vector<int> res;
    if (k == 0)
      return res;
    priority_queue<int> heap;
    for (int i = 0; i < k; i++) {
      heap.push(arr[i]);
    }
    for (int i = k; i < arr.size(); i++) {
      if (heap.top() > arr[i]) {
        heap.pop();
        heap.push(arr[i]);
      }
    }
    for (int i = 0; i < k; i++) {
      res.push_back(heap.top());
      heap.pop();
    }
    return res;
  }
};

class Solution {
 public:
  int partition(vector<int>& nums, int l, int r) {
    int pivort = nums[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; j++) {
      if (nums[j] <= pivort){
        i++;
        swap(nums[i], nums[j]);
      }
    }
    swap(nums[i + 1], nums[r]);
    return i + 1;
  }
  // 基于随机的划分
  int randompartition(vector<int>& nums, int l, int r) {
    int i = rand() % (r - l + 1) + l;
    // 被选中的随机数放在排序的最后一位
    swap(nums[i], nums[r]);
    return partition(nums, l, r);
  }
  void randomselected(vector<int>& nums, int l, int r, int k) {
    if (l >= r)  return;
    // pos的位置是nums中pos+1个最小的元素
    int pos = randompartition(nums, l, r);
    int len = pos - l + 1;
    if (len == k)  return;
    else if (k < len)  randomselected(nums, l, pos - 1, k);
    else randomselected(nums, pos + 1, r, k - len);
  }
  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    // 利用srand产生随机数的种子
    srand((unsigned)time(NULL));
    randomselected(arr, 0, arr.size() - 1, k);
    vector<int> res;
    for (int i = 0; i < k; i++)
      res.push_back(arr[i]);
    return res;
  }
};