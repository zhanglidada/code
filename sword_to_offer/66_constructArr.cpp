#include <iostream>
#include <vector>
using namespace std;

// 利用两个dp数组分别存放i位置左边的乘积和i右边的乘积
class Solution {
 public:
  vector<int> constructArr(vector<int>& a) {
    int len = a.size();
    vector<int> dpl(len, 1);
    vector<int> dpr(len, 1);
    vector<int> res;
    for (int i = 1, j = len - 2; i < len && j >= 0; i++, j--) {
      dpl[i] = dpl[i - 1] * a[i - 1];
      dpr[j] = dpr[j + 1] * a[j + 1];
    }
    for (int i = 0; i < len; i++) {
      res.push_back(dpl[i] * dpr[i]);
    }
    return res;
  }
};

class Solution {
 public:
  vector<int> constructArr(vector<int>& a) {
    int len = a.size();
    vector<int> res(len, 1);
    int tmp = 1;
    for (int i = 1; i < len; i++) {
      res[i] = res[i - 1] * a[i - 1];
    }
    for (int i = len - 2; i >= 0; i--) {
      tmp *= a[i + 1];
      res[i] *= tmp;
    }
    return res;
  }
};