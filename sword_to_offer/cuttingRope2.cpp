#include <iostream>
#include <vector>
using namespace std;

// 数学方法，因为最接近e的整数是3
class Solution {
 public:
  int cuttingRope(int n) {
    if (n <= 3)
      return n - 1;
    int res = 1;
    int mod = 1e9 + 7;
    int a = n / 3;  // 多少阶
    int b = n % 3;  // 余数
    if (b == 0)  return pow(3, a, mod, 1);
    if (b == 1)  return pow(3, a - 1, mod, 4);
    return pow(3, a, mod, 2);
  }
 private:
  // 使用快速幂的方法
  long long pow(long long base, long long level, long long mod, int mul) {
    long long res = 1;
    while (level) {
      if (level & 1)
        res = (res * base) % mod;
      base = (base * base) % mod;
      level >>= 1;  // 右移，即除2
    }
    res = (res * mul) % mod;
    return (int)res;
  }
};

int main() {
  Solution ss;
  ss.cuttingRope(13);
  return 0;
}