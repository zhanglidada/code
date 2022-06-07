#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给你一个整数数组nums, 如果任一值在数组中出现至少两次返回 true
 * 如果数组中每个元素互不相同，返回false
 * Notes:
 * 可以使用hah或者对数组进行排序
********************************************************************************************/

/*******************************************************************************************
 * 先排序，再计算重复
********************************************************************************************/
class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
      sort(nums.begin(), nums.end(), [](int a, int b) {
        return a < b;
      });
      for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] == nums[i + 1])
          return true;
      }
      return false;
    }
};


/*******************************************************************************************
 * hash计算重复元素
********************************************************************************************/
class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
      unordered_set<int> hash_set;
      for (auto num : nums) {
        if (!hash_set.count(num))
          hash_set.insert(num);
        else
          return true;
      }
      return false;
    }
};




int main() {
  return 0;
}