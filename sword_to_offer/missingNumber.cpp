#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int i = 0, j = nums.size() - 1;
    while (i <= j) {
      int mid = i + (j - i) / 2;
      if (nums[mid] == mid)  i = mid + 1;
      else j = mid - 1;
    }
    return i;
  }
};