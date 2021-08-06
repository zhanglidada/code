#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int reversePairs(vector<int>& nums) {
    int len = nums.size();
    if (len < 2)  return 0;
    vector<int> tmp;
    tmp.resize(len, 0);
    return binarySort(0, len - 1, nums, tmp);
  }
  // 计算nums[left...right]逆序对个数
  int binarySort(int left, int right, vector<int>& nums, vector<int>& tmp) {
    if (left == right)  return 0;
    int mid = left + (right - left) / 2;
    int leftcounts = binarySort(left, mid, nums, tmp);
    int rightcounts = binarySort(mid + 1, right, nums, tmp);  // 因为mid是下取整，所以不会越界
    if (nums[mid] <= nums[mid + 1])
      return leftcounts + rightcounts;
    int crosscounts = mergePairs(left, right, nums, tmp);
    return leftcounts + rightcounts + crosscounts;
  }
  // nums[left...mid]有序并且nums[mid + 1...right]有序
  int mergePairs(int left, int right, vector<int>& nums, vector<int>& tmp) {
    for (int i = left; i <= right; i++)
      tmp[i] = nums[i];  // tmp 用于存放在nums中归并排序之前的区间数组
    int mid = left + (right - left) / 2;
    int count = 0;
    // i和j分别指向两个待排序的有序数列的第一个位置
    int i = left, j = mid + 1;
    for (int k = left; k <= right; k++) {
      // 在遍历过程中需要先判断i和j的边界
      if (i == mid + 1) {
        nums[k] = tmp[j];
        j++;
      } else if (j == right + 1) {
        nums[k] = tmp[i];
        i++;
      } else if (tmp[i] <= tmp[j]) {
        // 注意当tmp[i] == tmp[j]的时候，先将左边的插入,保证排序的稳定
        nums[k] = tmp[i];
        i++;
      } else {
        nums[k] = tmp[j];
        j++;
        count += (mid - i + 1);
      }
    }
    return count;
  }
};

int main() {
  vector<int> input = {7,5,6,4};
  Solution ss;
  cout << ss.reversePairs(input);
}