#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int lastStoneWeightII(vector<int>& stones) {
      int len = stones.size();
      if (len == 1)  return stones[0];
      int sum = 0, target = 0;
      for (int i = 0; i < len; i++) {
        sum += stones[i];
      }
      // target 下取整
      target = sum / 2;

      // 初始化背包
      vector<int> dp(target + 1, 0);
      
      // 首先遍历stones，后遍历背包
      for (int i = 0; i < len; i++) {
        // 因为是一维数组，所以需要从后向前遍历，不破坏上次遍历结果
        for (int j = target; j >= stones[i]; j--) {
          dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
        }
      }
      return (sum - 2 * dp[target]);
    }
};