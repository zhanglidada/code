#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
     quickSort(nums, 0, nums.size() - 1);

  }
  vector<vector<int>> twoSum() {
  }
  void quickSort(vector<int>& nums, int begin, int end) {
    int i = begin, j = end + 1;
    int key = nums[begin];
    while (true) {
      while (nums[++i] < key) {
        if (i == end)
          break;
      }
      while (nums[--j] > key) {
        if (j == begin)
          break;
      }
      if (i >= j)
        break;
      int tmp = nums[j];
      nums[j] = nums[i];
      nums[i] = tmp;
    }
    int tmp = nums[j];
    nums[j] = nums[begin];
    nums[begin] = tmp;
    quickSort(nums, begin, j - 1);
    quickSort(nums, j + 1, end);
  }
};

int main() {
  vector<int> nums = {5,2,-1,6,8,0,9};
  Solution ss;
  ss.quickSort(nums, 0, nums.size() - 1);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  return 0;
}
