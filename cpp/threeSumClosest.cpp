#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 其实还是类似于三数之和
class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    // 先将数组元素进行排序，进行类似三数之和的查找
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
      // 保证这次的开始元素和上次的开始元素不同，避免再找一次子集
      if (i > 0 && nums[i] == nums[i-1])
        continue;
      twoSumCloset(nums, i + 1, target - nums[i], nums[i]);
    }
    return closet;
  }
  void twoSumCloset(vector<int>& nums, int start, int subTarget, int value) {
    int second = start;
    int end = nums.size() - 1;
    int third = end;
    int sum = 0;
    // second为第二个元素开始位置, third为第三个元素开始位置
    while (second < third) {
      sum = nums.at(second) + nums.at(third);
      if (sum == subTarget) {
        closet = subTarget + value;
        return;
      } else if (sum < subTarget){
        closet = abs(sum - subTarget) < abs(closet - value - subTarget) ? sum + value : closet;
        second ++;
        while (second != start && nums[second] == nums[second - 1]) {
          if (second < third)
            second ++;
          else
            break;
        }
      } else {
        closet = abs(sum - subTarget) < abs(closet - value - subTarget) ? sum + value : closet;
        third --;
        while (third != end && nums[third] == nums[third + 1]) {
          if (second < third)
            third --;
          else
            break;
        }
      }
    }
    return;
  }
  int closet = 1e6;
};
int main() {
  vector<int> nums = {1,1,1,0};
  int target = 100;
  Solution ss;
  cout << ss.threeSumClosest(nums, target);
  return 0;
}