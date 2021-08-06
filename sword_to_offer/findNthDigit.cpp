#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int findNthDigit(int n) {
    int digit = 1;
    long start = 1;
    long count = 9;
    while (n > count) {
      n -= count;
      start *= 10;
      digit++;
      count = 9*start*digit;
    }
    long num = start + (n - 1) / digit;  // 从下标0开始计数
    return to_string(num).at((n - 1)%digit) - '0';
  }
};