#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*******************************************************************************************
 * Purpose: 
 * 参照matlab中的reshape函数，将一个 m x n 矩阵重塑为另一个大小不同（r x c）的新矩阵，但保留其原始数据。
 * Notes:
 * 1. 给定一个由二维数组 mat 表示的 m x n 矩阵，以及两个正整数 r 和 c ，分别表示重构的矩阵的行数和列数。
 * 2. 重构后的矩阵需要将原始矩阵的所有元素以相同的 行遍历顺序 填充。
 * 3. 如果具有给定参数的 reshape 操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。
********************************************************************************************/

/*******************************************************************************************
 * Notes: 
 * 其实就是二维数组的一维化
********************************************************************************************/
class Solution {
  public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
      int rows = mat.size();
      int cols = mat[0].size();
      if (r * c != rows * cols)  return mat;
      res = vector<vector<int>>(r, vector<int>(c, 0));

      for (int i = 0; i < rows * cols; i++) {
        res[i / c][i % c] = mat[i / cols][i % cols];
      }
      return res;
    }
  private:
    vector<vector<int>> res;
};