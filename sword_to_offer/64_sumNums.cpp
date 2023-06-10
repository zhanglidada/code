#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 
 * 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
 * 
 */
class Solution {
 public:
  int sumNums(int n) {
    // 利用&&的短路特性,只要n>0, 就会递归计算n+sum(n - 1)
    n && (n += sumNums(n - 1));
    return n;
  }
};
