#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int x = 0, votes = 0;
    for (auto num : nums) {
      if (votes == 0)  x = num;  // 最后一次重新开始时候x肯定为众数
      votes += x == num ? 1 : -1;
    }
    return x;
  }
};