#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int add(int a, int b) {
    while (b != 0) {
      // c为进位,且c++不支持负数的左移，所以需要按照无符号数进行计算，且符号位并不影响结果
      int c = (unsigned int)(a & b) << 1;
      a ^= b;  // a 为非进位和
      b = c;  // b保存每一轮剩下的进位
    }
    return a;
  }
};