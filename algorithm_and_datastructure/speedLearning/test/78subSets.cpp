#include <iostream>
#include <vector>
using namespace std;

// 用迭代法实现子集枚举
class Solution {
 public:
  // 还有一种巧妙的方法，即利用一个mask来判断当前元素是否应该插入
  vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    // 因为mask属于 [0-2^n)
    for (int mask = 0; mask < (1 << n); mask ++) {
      path.clear();
      for (int i = 0; i < n; i++) {
        // 对每一个数，判断它的第i位是否位1，即nums中的元素ai是否在当前path中
        if (mask & (1 << i))  path.push_back(nums[i]);
      }
      res.push_back(path);
    }
    return res;
  }
 private:
  vector<int> path;
  vector<vector<int>> res;
};

// 用递归实现子集枚举
class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    dfs(0, nums);
    return ans;
  }
  void dfs(int cur, vector<int>& nums) {
    /* 
      递归到最后一个元素，返回
      在cur之前的元素选或者不选都已经确定，
      递归到当前cur状态，有两种选择
    */
    if (cur == nums.size()) {
      ans.push_back(path);
      return;
    }
    // 当前元素加入
    path.push_back(nums[cur]);
    dfs(cur + 1, nums);
    // 对当前元素进行回溯，排除
    path.pop_back();
    // 当前元素不选择
    dfs(cur + 1, nums);
  }
 private:
  vector<int> path;
  vector<vector<int>> ans;
};