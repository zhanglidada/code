#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>

/*
class Solution
{
  public:
    // 最简单的方法就是暴力穷举
    vector<int> twoSum(vector<int>& nums, int target)
    {
      for (int i = 0; i < nums.size(); i++)
      {
        // j从i+1开始，因为要保证两个数不相等。
        // 又因为i之前的数已经遍历过了, j再从0开始就没必要了
        for (int j = i + 1; j < nums.size(); j++)
        {
          if (nums[i] + nums[j] == target)
            return {i, j};
        }
      }

      return {}; 
    }
};
*/

class Solution
{
  public:
    // 使用hashmap，保存数组中元素和下标的对应关系
    vector<int> twoSum(vector<int>& nums, int target)
    {
      unordered_map<int, int> hash;
      // 从前向后遍历数组，并判断hash表中是否存在target-nums[i]的数
      for (int i = 0; i < nums.size(); i++)
      {
        if (hash.find(target - nums[i]) != hash.end())
          return {hash[target - nums[i]], i};
        else
          hash[nums[i]] = i;  // 对于重复的值能得到target时，当前位置因为还没插入则不会查到重复的位置
      }
      return {};
    }
};

int main(int argc, char *argv[])
{

}