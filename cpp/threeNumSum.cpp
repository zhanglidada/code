#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 可以增加一些特定判断
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    // quickSort(nums, 0, nums.size() - 1);
    if (nums.empty() || nums.size() < 3)
      return answer;
    sort(nums.begin(), nums.end());
    int numSize = nums.size();
    for (int i = 0; i < numSize - 2; i ++) {
      // 第一个元素不能为排序数组中重复的元素，因为只是判断是否有满足条件的数字，位置并不关心
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      if (nums[i] > 0)
        return answer;
      auto result = twoSum(nums, i + 1, numSize - 1, -nums[i], nums[i]);
      answer.insert(answer.end(), result.begin(), result.end());
    }
    return answer;
  }
  vector<vector<int>> twoSum(vector<int>& nums, int start, int end, int target, int value) {
    // 对于每一个two sum 队列，都有很多种可能的结果，需要一个vector<vector<int>>来保存
    vector<vector<int>> result;
    while (start < end) {
      int sum = nums[start] + nums[end];
      if (sum == target) {
        vector<int> res;
        res.push_back(value);
        res.push_back(nums[start]);
        res.push_back(nums[end]);
        result.push_back(res);
        // 跳过排序数组相等的值，即下一个开始二元组的start不能为和上一个start值相同
        while(start < end && nums[start] == nums[start + 1]) {
          start ++;
        }
        start ++;
        // 下一个开始的end的值不能和上一个end的值相同
        while (start < end && nums[end] == nums[end - 1]) {
          end --;
        }
        end --;
      } else if (sum < target) {
        start ++;
      } else {
        end --;
      }
    }
    return result;
  }
  void quickSort(vector<int>& nums, int begin, int end) {
    if (begin >= end)
      return;
    int i = begin, j = end + 1;
    int key = nums[begin];
    while (true) {
      while (nums[++i] < key) {
        if (i == end)
          break;
      }
      while (nums[--j] > key) {
        if (j == begin)
          break;
      }
      if (i >= j)
        break;
      int tmp = nums[j];
      nums[j] = nums[i];
      nums[i] = tmp;
    }
    int tmp = nums[j];
    nums[j] = nums[begin];
    nums[begin] = tmp;
    quickSort(nums, begin, j - 1);
    quickSort(nums, j + 1, end);
  }
  vector<vector<int>> answer;
};

int main() {
  vector<int> nums = {5,2,-1,6,8,0,9};
  Solution ss;
  // ss.quickSort(nums, 0, nums.size() - 1);
  // for (int i = 0; i < nums.size(); i++) {
  //   cout << nums[i] << " ";
  // }
  return 0;
}