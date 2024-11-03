#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// 不考虑空间复杂度的情况下，使用hashset保存所有存在的元素
// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         unordered_set<int> set;
//         vector<int> res;

//         for (auto num : nums) {
//           set.insert(num);
//         }

//         for (int i = 1; i <= nums.size(); i++) {
//           if (set.find(i) == set.end())
//             res.emplace_back(i);
//         }

//         return res;
//     }
// };


// 考虑到空间复杂度，不使用额外的空间
// 用下标i表示每个元素，下标i中的值表示元素的访问情况
class Solution {
  public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int tmp;

        if (nums.empty())
          return res;

        for (auto num : nums) {
          // 当前位置的值需要mod size，防止之前被修改过,
          // 获取取模后的值，表示其所指向的下标位置
          tmp = (num - 1) % nums.size();

          if (nums[tmp] <= nums.size()) {
            nums[tmp] = nums[tmp] + nums.size();
          }
        }

        for (int i = 0; i < n; i++) {
          if (nums[i] <= n)
            res.emplace_back(i + 1);
        }

        return res;
    }
};
