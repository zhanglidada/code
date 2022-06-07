#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给定一个 m x n 的矩阵，如果一个元素为0,则将其所在行和列的所有元素都设为0。
 * Notes:
 * 请使用原地算法(空间复杂度为O(1)的算法)
********************************************************************************************/

/*******************************************************************************************
 * Notes:
 * 1.可以使用两个标记数组，分别记录行和列是否有0出现
********************************************************************************************/
class Solution {
  public:
    void setZeroes(vector<vector<int>>& matrix) {
      int row = matrix.size();
      int col = matrix[0].size();
      rows = vector<int>(row, 0);
      cols = vector<int>(col, 0);

      // 第一次遍历，找到每个0，获得其所在的行和列信息
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
          if (!matrix[i][j])
            rows[i] = cols[j] = 1;
        }
      }

      // 第二次遍历，根据rows以及col数组，重置矩阵元素值
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
          if (rows[i] || cols[j])
            matrix[i][j] = 0;
        }
      }
    }
  private:
    vector<int> rows;
    vector<int> cols;
};