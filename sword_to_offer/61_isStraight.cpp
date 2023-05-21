#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// 使用一个集合
class Solution {
 public:
  bool isStraight(vector<int>& nums) {
    unordered_set<int> sets;
    int ma = 0, mi = 14;
    for (auto num : nums) {
      if (num == 0)  continue;
      if (sets.count(num))  return false;
      ma = max(ma, num);
      mi = min(mi, num);
      sets.insert(num);
    }
    return ma - mi < 5;
  }
};

// 排序
class Solution {
 public:
  bool isStraight(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int joker = 0;  // 存放大小王的数量
    for (int i = 0; i < 4; i++) {
      if (nums[i] == 0)  joker ++;
      else if (nums[i] == nums[i + 1])  return false;
    }
    return nums[4] - nums[joker] < 5;
  }
};
int main () {
  Solution ss;
  vector<int> nums = {1,2,3,4,5};
  cout << ss.isStraight(nums);
}