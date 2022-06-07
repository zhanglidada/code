#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给定两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
 * 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
 * Notes:
 * 1.合并后数组不应由函数返回，而是存储在数组 nums1 中。
 * 2.nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 应忽略。
 * 3.nums2 的长度为 n 。
********************************************************************************************/

/*******************************************************************************************
 * Purpose:
 * 合并两个数组，且按照非递减顺序排列，
 * Notes:
 * 1.首先想到的就是双指针方法
 * 2.使用冗余数组存储排序后的位置
 * ********************************************************************************************/
class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int posx = 0;
      int posy = 0;
      while (posx < m && posy < n) {
        if (nums1[posx] < nums2[posy]) {
          sorted.emplace_back(nums1[posx++]);
        } else {
          sorted.emplace_back(nums2[posy++]);
        }
      }

      while (posx < m) {
        sorted.emplace_back(nums1[posx++]);
      }
      while (posy < n) {
        sorted.emplace_back(nums2[posy++]);
      }

      // 重新拷贝
      for (int i = 0; i < n + m; i++) {
        nums1[i] = sorted[i];
      }
    }
  private:
    vector<int> sorted;
};

/*******************************************************************************************
 * Purpose:
 * 合并两个数组，且按照非递减顺序排列，
 * Notes:
 * 1.使用逆向双指针法，比较两个数组，并将最大的元素放在nums1最后，逆向排序
 * ********************************************************************************************/
class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int posx = m - 1, posy = n - 1;
      int last_pos = m + n - 1;
      while (posx >= 0 && posy >= 0) {
        if (nums1[posx] > nums2[posy]) {
          nums1[last_pos--] = nums1[posx--];
        } else {
          nums1[last_pos--] = nums2[posy--];
        }
      }

      while (posy >= 0) {
        nums1[last_pos--] = nums2[posy--];
      }
    }
};