#include <iostream>
#include <cmath>
using namespace std;

int fast_multiply(int value1, int value2) {
  int ans = 0;
  // 快速乘法
  for (; value2; value2 >>= 1) {
    if (value2 & 1) {
      ans += value1;
    }
    value1 <<= 1;
  }

  return ans;
}

int fast_multiply1(int value1, int value2) {
  int ans = 0;
  // 快速乘法
  while (value2) {
    if (value2 & 1) {
      ans += value1;
    }
    value1 <<= 1;
    value2 >>= 1;
  }

  return ans;
}

int main() {
  int mul = fast_multiply(123, 456);
  int mul2 = fast_multiply1(123, 456);

  cout << mul << " " << mul2;
}