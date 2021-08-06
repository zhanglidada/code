#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int climbStairs(int n) {
    vector<vector<int>> q = {{1, 1}, {1, 0}};
    return pow(q, n);
  }
  int pow(vector<vector<int>>& a, int n) {
    // 初始为单位矩阵
    vector<vector<int>> ret = {{1, 0}, {0, 1}};
    while (n) {
      if (n & 1) {
        ret = multiply(ret, a);
      }
      a = multiply(a, a);
      n = n >> 1;
    }
    return ret[0][0];
  }
  vector<vector<int>> multiply(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> c = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
      }
    }
    return c;
  }
};
int main() {
  return 0;
}