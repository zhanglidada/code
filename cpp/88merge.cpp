#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>


// 最简单的方法，可以将nums2中的元素先写入nums1中，然后再将nums1排序
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//       for (int i = 0; i < n; i++)
//       {
//         nums1[m + i] = nums2[i];
//       }

//       sort(nums1.begin(), nums1.end());
//     }
// };

// 上面的算法中没有充分利用两个数组的有序性，这里可以使用双指针来充分利用连个数组的有序性
// 使用一个临时数组将排序的结果放入其中，之后再将临时数组中的数据拷贝回原来的nums1中
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//       int i = 0,j = 0,k = 0;
//       vector<int> temp(m + n, 0);

//       while (i < m && j < n)
//       {
//         if (nums1[i] <= nums2[j])
//           temp[k++] = nums1[i++];
//         else
//           temp[k++] = nums2[j++];
//       }

//       if (i < m)
//       {
//         while (i < m)
//         {
//           temp[k++] = nums1[i++];
//         }
//       }
//       else if (j < n)
//       {
//         while (j < n)
//         {
//           temp[k++] = nums2[j++];
//         }
//       }

//       for (i = 0; i < m + n; i++)
//       {
//         nums1[i] = temp[i];
//       }
//     }
// };

// 进一步，可以充分利用nums1中的空间，这样可以从后向前，按照从大到小进行排序
// 依然使用双指针，但是倒序处理，两个数组都从后向前进行遍历并依次将当前最大的元素放到nums1数组的最后位置
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
      int i = m - 1, j = n - 1, k = m + n - 1;

      // 先将nums1和nums2中较大的元素放入temp中
      while (i >= 0 && j >= 0)
      {
        if (nums1[i] > nums2[j])
          nums1[k--] = nums1[i--];
        else
          nums1[k--] = nums2[j--];
      }

      while(i >= 0)
        nums1[k--] = nums1[i--];

      while(j >= 0)
        nums1[k--] = nums2[j--];

    }
};