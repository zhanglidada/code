#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int sumNums(int n) {
    // 利用&&的短路特性
    n && (n += sumNums(n - 1));
    return n;
  }
};
