#include <iostream>
#include <vector>
using namespace std;

/* 采用动态规划的方式
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty())
      return 0;
    vector<int> dp(nums.size(), 1);
    int maxSublen = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j])
          dp[i] = max(dp[i], dp[j] + 1);
      }
      maxSublen = max(maxSublen, dp[i]);
    }
    return maxSublen;
  }
};  */

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty())
      return 0;
    int len = 1, n = nums.size();
    vector<int> dp(n + 1, 0);
    dp[1] = nums[0];
    // 针对nums中的每个数组进行遍历
    for (int i = 1; i < n; i++) {
      if (nums[i] > dp[len]) {
        len++;
        dp[len] = nums[i];
      } else {
        binarySort(dp, 1, len, nums[i]);
      }
    }
    return len;
  }
  void binarySort(vector<int>& nums, int left, int right, int value) {
    int pos = 0;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] < value) {
        // pos 是第一个小于value的位置
        pos = mid;
        left = mid + 1;
      }
      else
        right = mid - 1;
    } 
    nums[pos + 1] = value;
  }
};

int main() {
  Solution ss;
  vector<int> nums = {3,5,6,2,5,4,19,5,6,7,12};
  cout << ss.lengthOfLIS(nums);
}