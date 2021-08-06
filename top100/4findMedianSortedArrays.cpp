#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int totalLength = nums1.size() + nums2.size();
    if (totalLength % 2 == 0)
      return (getKthnum(nums1, nums2, totalLength / 2) + getKthnum(nums1, nums2, totalLength / 2 + 1)) / 2.0;
    else return getKthnum(nums1, nums2, (totalLength + 1) / 2);
  }

  int getKthnum(vector<int>& nums1, vector<int>& nums2, int k) {
    int m = nums1.size();
    int n = nums2.size();
    int index1 = 0, index2 = 0;
    
    /*
      index1 : nums1数组开始位置
      index2 : nums2数组开始元素
    */
    while (true) {
      // 判断边界情况
      if (index1 == m)
        return nums2[index2 + k - 1];
      if (index2 == n)
        return nums1[index1 + k - 1];
      if (k == 1)  return min(nums1[index1], nums2[index2]);

      // 正常情况
      int newIndex1 = min(index1 + k / 2 - 1, m - 1);
      int newIndex2 = min(index2 + k / 2 - 1, n - 1);
      int pivot1 = nums1[newIndex1];
      int pivot2 = nums2[newIndex2];
      // 第1和3种情况,排除nums1种的前k/2个元素
      if (pivot1 <= pivot2) {
        k -= (newIndex1 - index1 + 1);
        index1 = newIndex1 + 1;
      } else {  // 第3种情况
        k -= (newIndex2 - index2 + 1);
        index2 = newIndex2 + 1;
      }
    }
  }
};

// 优化二分查找，时间复杂度为O(log(min(m, n)))
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size())
      return findMedianSortedArrays(nums2, nums1);
    int m = nums1.size(), n = nums2.size();
    // 在nums1的[0, m]区间内找合适的分割线,使得nums[i - 1] <= nums[]
    int left = 0, right = m;

    int median1 = 0, median2 = 0;
    // 分割线左边的元素个数需要满足m + (n - m + 1) / 2;
    int totalLeft = (m + n + 1) / 2;
    // i 和 j 其实是划分长度m，n的位置
    while (left < right) {
      /* 前一部分包含 nums1[0 .. i-1] 和 nums2[0 .. j-1]
         后一部分包含 nums1[i .. m-1] 和 nums2[j .. n-1]
         m为奇，i在第二个数组的第一个位置，且前后比后长度多一个
         m为偶，i在第二个数组的第一个位置，且前后长度一样
      */
      int i = left + (right - left + 1) / 2;  // i = (left + right + 1) / 2
      int j = totalLeft - i;
      if (nums1[i - 1] > nums2[j]) {
        // 下一轮的搜索区间[left, i]
        right = i - 1;  // right刚好为超过边界的那个位置
      }
      else {
        // 下一轮的搜索区间[i + 1, right];
        left = i;  // left刚好为第一个开始的位置
      }

    }
    int i = left, j = (m + n + 1) / 2 - i;
    /* 
      nums_iml : nums[i - 1]
      nums_i : nums1[i]
      nums_jml : nums2[j - 1]
      nums_j : nums2[j]
    */
    int nums_iml = i == 0 ? INT32_MIN : nums1[i - 1];
    int nums_i = i == m ? INT32_MAX : nums1[i];
    int nums_jml = j == 0 ? INT32_MIN : nums2[j - 1];
    int nums_j = j == n ? INT32_MAX : nums2[j];
    return (m + n) % 2 == 0 ? (max(nums_iml, nums_jml) + min(nums_i, nums_j)) / 2.0 : max(nums_iml, nums_jml);
  }
};

int main() {
  vector<int> nums1 = {1,3};
  vector<int> nums2 = {2};
  Solution ss;
  cout << ss.findMedianSortedArrays(nums1, nums2);
}