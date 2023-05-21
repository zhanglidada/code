#include <iostream>
#include <vector>
using namespace std;

// 递归方式
class Solution {
 public:
  int lastRemaining(int n, int m) {
    return f(n, m);
  }
  int f(int n, int m) {
    if (n == 1)  return 0;
    int x = f(n - 1, m);
    return (m + x) % n;
  }
};

// 循环右移也可以
class Solution {
 public:
  int lastRemaining(int n, int m) {
    int pos = 0;  // 最终活下来的人最终位置
    for (int i = 2; i <= n; i++) {
      pos = (pos + m) % i;  // 每次循环右移
    }
    return pos;
  }
};