#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给定一个整数数组nums和一个整数目标值target，在该数组中找出和为目标值target的那两个整数，
 * 并返回它们的数组下标。
 * Notes:
 * 由于是求两数之和，且数组中不存在重复的数字，所以使用hash表即可
********************************************************************************************/
class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int n = nums.size();
      int res_num = 0;
      for (int i = 0; i < n; i++) {
        // 查找当前元素的配对元素是否存在于hash表中
        res_num = target - nums[i];
        if (hash_map.count(res_num)) {
          return {i, hash_map[res_num]};
        }
        // 当前元素的配对不存在于hash表中，需要将当前元素插入hash表
        hash_map[nums[i]] = i;
      }
      return res;
    }
  private:
    unordered_map<int, int>  hash_map;
    vector<int> res;
};