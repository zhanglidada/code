#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给一个整数数组nums，找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * Notes:
 * 1. 首先想到滑动窗口方法
 * 2. 其次是动态规划解决问题
 * 3. 之后还可以采用分治法解决
********************************************************************************************/

/*******************************************************************************************
 * Purpose:
 * 使用了贪心算法
 * Notes:
 * 从前向后添加元素，若当前指针之前的元素和 < 0 则丢弃当前元素之前的数列，并从下一个元素重新开始
********************************************************************************************/
class Solution {
  public:
    int maxSubArray(vector<int>& nums) {
      int n = nums.size();
      int maxval = INT32_MIN;  // 保存增益中的最大值
      int current_val = 0;  // 当前元素为止的序列可以向后提供的增益
      for (int i = 0; i < n; i++) {
        current_val += nums[i];
        maxval = max(maxval, current_val);
        current_val = current_val < 0 ? 0 : current_val;  // 当前元素之和是否对后续元素有增益
      }
      return maxval;
    }
};


/*******************************************************************************************
 * Purpose:
 * 使用动态规划解决问题
 * Notes:
 * 1. 使用f(i)代表第i个元素结尾的数组中，最大的连续子数组和
 * 2. 若前一个元素f(i - 1) > 0, 将其加到当前元素上作为f(i)值;否则f(i)值为当前元素值
 * 3. f(i) = max(f(i - 1) + nums[i], nums[i])
 * 
********************************************************************************************/
class Solution {
  public:
    int maxSubArray(vector<int>& nums) {
      int pre = 0;  // 当前元素之前的增益
      int max_val = nums[0];  // 初始化为首元素的值
      for (auto num : nums) {
        pre = max(pre + num, num);
        max_val = max(pre, max_val);
      }
      return max_val;
    }
};

/*******************************************************************************************
 * Purpose:
 * 使用分治算法解决问题
 * Notes:
 * 1. 类似于求解线段树的最长公共子序列问题
 * 2. 定义函数get(a, l, r) 表示查询a序列[l, r]区间的最大子段和
 * 3. 维护四个量：
 * lSum: [l, r]区间内以l为左端点的最大子段和
 * rSum: [l, r]区间内以r为右端点的最大子段和
 * mSum: [l, r]区间内的最大子段和
 * iSum: [l, r]的区间和
********************************************************************************************/
class Solution {
  public:
    // 保存区间的值信息
    struct status_val{
      int lSum;
      int rSum;
      int mSum;
      int iSum;
    };

    int maxSubArray(vector<int>& nums) {
      return get(nums, 0, nums.size() - 1).mSum;
    }
    
    // 计算l区间和r区间合并起来的最大连续子段和
    status_val push_up(status_val l, status_val r) {
      int iSum = l.iSum + r.iSum;
      int lSum = max(l.lSum, l.iSum + r.lSum);
      int rSum = max(r.rSum, r.iSum + l.rSum);
      // 需要判断是否在中间位置进行连接
      int mSum = max(max(r.mSum, l.mSum), l.rSum + r.lSum);
      return (status_val) {lSum, rSum, mSum, iSum};
    }

    // 查询a序列[l, r]区间的最大子段和
    status_val get(vector<int>& a, int l, int r) {
      // 最小子问题
      if (l == r) return (status_val){a[l], a[l], a[l], a[l]};
      int m = (l + r) / 2;
      status_val lsub = get(a, l, m);
      status_val rsub = get(a, m + 1, r);
      return push_up(lsub, rsub);
    }
};