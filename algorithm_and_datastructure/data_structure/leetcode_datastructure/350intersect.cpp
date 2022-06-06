#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给定两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，
 * 应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
 * ********************************************************************************************/


/*******************************************************************************************
 * Purpose:
 * 求解两个数组的交集
 * Notes:
 * 可以使用hash表的方式，存储两个元素中的每个元素及其对应的出现次数
 * 对于返回结果不需要排序
 * ********************************************************************************************/
class Solution {
  public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      for (auto num : nums1) {
        hash_map.count(num) == 0 ? hash_map[num] = 1 : hash_map[num] += 1;
      }

      for (auto num : nums2) {
        // 仅当前元素在nums1中存在
        if (hash_map.count(num)) {
          // 当前元素在hashmap中value为0
          if (hash_map[num] == 0)
            hash_map.erase(num);
          else {
            res.push_back(num);
            hash_map[num]--;
          }
        }
      }
      return res;
    }
  private:
    vector<int> res;
    unordered_map<int, int> hash_map;
};

/*******************************************************************************************
 * Purpose:
 * 求解两个数组的交集
 * Notes:
 * 先排序，之后使用双指针遍历两个数组
 * ********************************************************************************************/
class Solution {
  public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      int posx = 0;
      int posy = 0;
      sort(nums1.begin(), nums1.end(), [](int a, int b){
        return a < b;
      });
      sort(nums2.begin(), nums2.end(), [](int a, int b){
        return a < b;
      });
      while (posx < nums1.size() && posy < nums2.size()) {
        if (nums1[posx] == nums2[posy]) {
          res.emplace_back(nums1[posx]);
          posx++;
          posy++;
        } else if (nums1[posx] < nums2[posy]) {
          posx++;
        } else {
          posy++;
        }
      }
      return res;
    }
  private:
    vector<int> res;
};