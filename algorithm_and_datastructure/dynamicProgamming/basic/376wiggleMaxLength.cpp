#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// 采用动态规划的思想
/*  纯自己的思路
class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    if (n == 0 || n == 1)  return n;

    vector<vector<int>> dp(n, vector<int>(2, 0));

    for (int i = 0; i < n; i++) {
      dp[i][0] = 1;   // 以当前元素截止的子序列中最长摆动序列长度
      dp[i][1] = -1;  // 从当前位置起始
    }
    
    int longestLength = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        int res = nums[i] - nums[j];
        // 差值为0，不具有可比性
        if (res == 0)  continue;

        if (dp[j][1] >= 0) {
        // j为非起始位置
          if (dp[j][1] == 0) {
            if (res > 0) {
              dp[i][0] = max(dp[i][0], dp[j][0] + 1);
              dp[i][1] = 1;
            }
          } else {
            if (res < 0) {
              dp[i][0] = max(dp[i][0], dp[j][0] + 1);
              dp[i][1] = 0;
            }
          }
        } else {
        // 当前元素为起始序列
          dp[i][0] = 2;
          dp[i][1] = res > 0 ? 1 : 0;
        }
      }
      longestLength = max(longestLength, dp[i][0]);
    }
    return longestLength;
  }
}; */

// 采用动态规划的方式，利用最长上升序列和最长下降序列进行递归
/*
class Solution {
  public:
    int wiggleMaxLength(vector<int>& nums) {
      int n = nums.size();
      vector<int> up(n);
      vector<int> down(n);
      
      // 初始化
      up[0] = 1;
      down[0] = 1;
      for (int i = 1; i < n; i++) {
        // 需要判断三种情况
        if (nums[i] > nums[i - 1]) {
          up[i] = max(up[i - 1], down[i - 1] + 1);
          down[i] = down[i - 1];
        } else if (nums[i] < nums[i - 1]) {
          up[i] = up[i - 1];
          down[i] = max(down[i - 1], up[i - 1] + 1);
        } else {
          // 和前一个元素相等时视为过度元素
          up[i] = up[i - 1];
          down[i] = down[i - 1];
        }
      }
      return max(down[n - 1], up[n - 1]);
    }
};  */

// 优化动态规划的空间复杂度
/*
class Solution {
  public:
    int wiggleMaxLength(vector<int>& nums) {
      int n = nums.size();
      // 初始的上升和下降摆动序列长度均为1
      int up = 1, down = 1;
      
      // 初始化
      for (int i = 1; i < n; i++) {
        // 需要判断三种情况
        if (nums[i] > nums[i - 1]) {
          up = max(up, down + 1);
        } else if (nums[i] < nums[i - 1]) {
          down = max(down, up + 1);
        }
        // 相等时不需要进行转移，直接默认为上一个下标的值
      }
      return max(down, up);
    }
};  */

// 使用贪心算法
class Solution {
  public:
    int wiggleMaxLength(vector<int>& nums) {
      int n = nums.size();
      if (n < 2)  return n;
      // 计算初始的摆动序列为上升或者下降
      int prediff = nums[1] - nums[0];
      // 去除相等元素的影响
      int  res = prediff != 0 ? 2 : 1;

      for (int i = 2; i < n; i++) {
        int diff = nums[i] - nums[i - 1];
        // 去除相等元素的干扰, prediff == 0 只有在开始元素中才可能出现
        if ((diff > 0 && prediff <= 0) || (diff < 0 && prediff >= 0)) {
          res ++;
          prediff = diff;
        }
      }
      return res;
    }
};

int main() {
  vector<int> nums = {3,3,3,5,1,1,1,4,2,2,2,0};
  vector<int> nums1 = {1,17,5,10,13,15,10,5,16,8};
  Solution ss;
  cout << ss.wiggleMaxLength(nums);
  return 0;
}