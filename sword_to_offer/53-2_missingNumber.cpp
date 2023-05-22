#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 二分查找，值从0开始，到nums.size()截至
class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    // 数组中的首尾位置
    int i = 0, j = nums.size() - 1;
    while (i <= j) {
      // mid的值和nums[mid] 保持一致
      int mid = i + (j - i) / 2;
      // 前面全部匹配，需要向后查找
      if (nums[mid] == mid)
        i = mid + 1;
      // 前面存在不匹配的情况，向前查找
      else
        j = mid - 1;
    }
    return i;
  }
};

// 使用一个辅助set进行遍历
class Solution {
  public:
    int missingNumber(vector<int>& nums) {
        // 遍历所有元素并插入visited
        for (auto num : nums)
        {
            visited.insert(num);
        }

        // 0 - n 遍历计数
        for (int i = 0; i <= visited.size() ; i++)
        {
            if (!visited.count(i))
                return i;
        }
        return 0;
    }
private:
    unordered_set<int> visited;
};