#include <iostream>
#include <vector>
using namespace std;

// 循环位移求1的个数
class Solution {
public:
  int hammingWeight(uint32_t n) {
    unsigned int mask = 1;
    int bits = 0;
    for (int i = 0; i < 32; i++) {
      if ((n & mask) != 0)  bits++;
      mask <<= 1;
    }
    return bits;
  }
};

// 优化，由于n&(n-1)可以将n的最后一位的1化为0
class Solution {
public:
  int hammingWeight(uint32_t n) {
    int bits = 0;
    while (n) {
      n &= (n - 1);
      bits ++;
    }
    return bits;
  }
};
