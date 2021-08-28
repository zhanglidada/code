#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool canPartition(vector<int>& nums) {
      int len = nums.size();
      int sum = 0, target = 0;
      if (len == 1)  return false;
      for (int i = 0; i < len; i++) {
        sum += nums[i];
      }
      if (sum % 2 != 0)  return false;
      target = sum / 2;

      // 初始化动态规划数组
      vector<int> dp(target + 1, 0);
      for (int i = 0; i < len; i++) {
        // 因为是一维数组，需要从后向前遍历，保存上一次遍历的状态不被破坏
        for (int j = target; j >= nums[i]; j--) {
          dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
      }
      return dp[target] == target;
    }
};

int main() {
  return 0;
}