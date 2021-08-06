#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
      count ++;
      // 将最右侧的1消除
      n = n & (n - 1);
    }
    return count;
  }
};