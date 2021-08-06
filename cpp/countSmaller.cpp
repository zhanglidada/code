#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> result_list;
    Discretization(nums);
    init(nums.size() + 1);
    for (int i = nums.size() - 1; i >= 0; i--) {
      int id = getId(nums[i]);
      // 倒叙查找，在此元素之前有多少元素在其前序和中
      result_list.push_back(query(id));
      update(id);
    }
    reverse(result_list.begin(), result_list.end());
    return result_list;
  }
 private:
  vector<int> a, c;
  // 初始化前缀和数组
  void init(int length) {
    c.resize(length, 0);
  }
  // 传递给lowbit的其实是当前元素排序后的下标，所以总是为正
  int lowBit(int num) {
    return num & (-num);
  }
  //这里每次update其实都是将对应节点的值加1，并递归将父节点的值加1
  void update(int id) {
    while (id < c.size()) {
      c[id] += 1;
      // 更新指向父节点的位置
      id += lowBit(id);
    }
  }
  // 查询树状数组中的前缀和，即当前传入id序号的前一个id开始查询
  int query(int id) {
    id = id - 1;
    int ret = 0;
    while (id > 0) {
      ret += c[id];
      id -= lowBit(id);
    }
    return ret;
  }
  // 将nums数组去重后排序
  void Discretization(vector<int>& nums) {
    a.assign(nums.begin(), nums.end());
    sort(a.begin(), a.end());
    // unique返回不重复元素的最后元素的下一个位置
    a.erase(unique(a.begin(), a.end()), a.end());
    // cout << a.size() << endl;
  }
  // 获取当前元素在排序后数组里面的下标+1
  int getId(int& num) {
    return lower_bound(a.begin(), a.end(), num) - a.begin() + 1;
  }
}; */

// 从后往前进行二分查找，并维持一个sorted数组
class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> sorted;
    vector<int> count;
    for (int i = nums.size() - 1; i >= 0; i--) {
      // 查找nums[i]应该插入sorted数组的位置
      int lessNum = findIndex(sorted, nums[i]);
      // cout << lessNum << " ";
      count.push_back(lessNum);
      sorted.insert(sorted.begin() + lessNum, nums[i]);
    }
    reverse(count.begin(), count.end());
    return count;
  }
  // 二分查找元素在排序数组中应该的位置
  int findIndex(vector<int>& nums, int value) {
    if (nums.empty())
      return 0;
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      if (nums[mid] < value)
        left = mid + 1;
      else
        right = mid;
    }
    // 因为退出循环的条件是left >= right，所以left==right时候没有进行比较(其实这里不存在left > right的情况)
    return nums[left] < value ? left + 1 : left;
  }
};

// class Solution {
//  public:
//   vector<int> countSmaller(vector<int>& nums) {
    
//   }
// };
int main() {
  vector<int> nums = {5,2,6,1};
  Solution ss;
  vector<int> ans =  ss.countSmaller(nums);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}