#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int dp1 = 0, dp2 = 0, maxSub = INT32_MIN;
    for (int i = 0; i < nums.size(); i++) {
      if (dp1 <= 0)
        dp2 = nums[i];
      else {
        dp2 = dp1 + nums[i];
      }
      maxSub = max(maxSub, dp2);
      dp1 = dp2;
    }
    return maxSub;
  }
};