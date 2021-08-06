#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int countDigitOne(int n) {
    long long int digit = 1;
    int res = 0;
    int high = n / 10, cur = n % 10, low = 0;
    while (high || cur) {
      if (cur == 0)  res += high * digit;
      else if (cur == 1) res += high * digit + low + 1;
      else res += (high + 1) * digit;
      low = low  + cur * digit;
      cur = high % 10;
      digit *= 10;
      high /= 10;
    }
    return res;
  }
};