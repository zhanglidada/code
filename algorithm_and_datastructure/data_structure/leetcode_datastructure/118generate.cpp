#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
 * Notes: 
 * 在杨辉三脚中，每个数是其左上方和右上方数的和
********************************************************************************************/
class Solution {
  public:
    vector<vector<int>> generate(int numRows) {
      // 初始化ret数组
      vector<vector<int>> ret(numRows, vector<int>());
      for (int i = 0; i < numRows; ++i) {
          ret[i].resize(i + 1);
          ret[i][0] = ret[i][i] = 1;
          for (int j = 1; j < i; ++j) {
              ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
          }
      }
      return ret;
    }
};

int main() {
  Solution ss;
  int numrows = 5;
  vector<vector<int>> res = ss.generate(numrows);
  for (int i = 0; i < numrows; i++) {
    for (int j = 0; j <= i; j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
}
