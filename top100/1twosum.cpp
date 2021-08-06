#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* 两遍hash表
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashmap;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
      hashmap.insert({nums[i], i});
    for (int i = 0; i < nums.size(); i++) {
      int resv = target - nums[i];
      if (hashmap.count(resv) && hashmap[resv] != i) {
        ans = vector<int>({i, hashmap[resv]});
        break;
      }
    }
    return ans;
  }
};*/
// 一遍hash表
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashmap;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
      int resv = target - nums[i];
      if (hashmap.count(resv) && hashmap[resv] != i) {
        // 因为如果对于当前的nusm[i],resv存在于hash中，那么它的下标小于i
        ans = vector<int>({hashmap[resv], i});
        break;
      }
      hashmap.insert({nums[i], i});
    }
    return ans;
  }
};
int main() {
  Solution ss;
  vector<int> nums = {2,7,11,15,19};
  vector<int> res = ss.twoSum(nums, 9);
  for (auto num : res)
    cout << num << " ";
}