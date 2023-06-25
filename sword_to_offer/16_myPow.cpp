#include <iostream>
#include <vector>
using namespace std;

/***************************************************************************
 * 1. 快速幂 + 递归
 * 
 * 快速幂的本质就是分治算法
 * 
 * 计算x的n次幂，n分奇数偶数两种情况
 * 首先递归计算值Y，Y = X^[n/2], Y的幂为下取整的值
 * 1）n为偶数，X^n = Y^2
 * 2）n为奇数，X^n = Y^2 * x
 * 3）递归的边界为 n = 0, 任意数的0次方为1
***************************************************************************/
class Solution {
  public:
    double quickMul(double x, long long N) {
      if (N == 0) {
          return 1.0;
      }
      // 计算下取整的幂
      double y = quickMul(x, N / 2);
      return N % 2 == 0 ? y * y : y * y * x;
    }

    double myPow(double x, int n) {
      long long N = n;
      return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};

/***************************************************************************
 * 2. 快速幂 + 迭代
 * 
 * 根据幂的二进制值找规律
***************************************************************************/
class Solution {
public:
  double quickMul(double x, long long N) {
    double ans = 1.0;
    // 贡献的初始值为 x
    double x_contribute = x;

    // 在对 N 进行二进制拆分的同时计算答案
    while (N > 0) {
        if (N % 2 == 1) {
            // 如果 N 二进制表示的最低位为 1，那么需要计入贡献
            ans *= x_contribute;
        }

        // 将贡献不断地平方
        x_contribute *= x_contribute;
        
        // 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
        N /= 2;
    }
    return ans;
  }

  double myPow(double x, int n) {
    long long N = n;
    return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
  }
};