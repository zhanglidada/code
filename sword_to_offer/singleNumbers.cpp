#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> singleNumbers(vector<int>& nums) {
    int res = 0, lowbit = 1;
    for (auto num : nums) {
      res ^= num;
    }
    // 获得a异或b的最低位1
    while ((res & lowbit) == 0)
      lowbit <<= 1;
    int a = 0, b = 0;
    for (auto num : nums) {
      if (num & lowbit)  a ^= num;
      else  b ^= num;
    }
    return vector<int>({a, b});
  }
};