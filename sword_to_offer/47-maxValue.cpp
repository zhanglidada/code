#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxValue(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    // 第一行的所有元素
    for (int i = 1; i < m; i++)
      grid[0][i] = grid[0][i - 1] + grid[0][i];
    // 第一列的所有元素
    for (int i = 1; i < n; i++) {
      grid[i][0] = grid[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        grid[i][j] = max(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
      }
    }
    return grid[n - 1][m - 1];
  }
};