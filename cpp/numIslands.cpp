#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty())  return 0;
    int numIsland = 0;
    int nr = grid.size();
    int nc = grid[0].size();
    for (int i = 0; i < nr; i++) {
      for (int j = 0; j < nc; j++) {
        if (grid[i][j] == '1') {
          numIsland++;
          dfs(grid, i, j);
        }
      }
    }
    return numIsland;
  }
  // 其实每次每个节点
  void dfs(vector<vector<char>>& grid, int r, int c) {
    int nr = grid.size();
    int nc = grid[0].size();
    // 每次在深度优先过程中遍历过的节点就不会在其他深度优先遍历的过程中继续访问
    grid[r][c] = '0';
    if (r - 1 >= 0 && grid[r - 1][c] == '1')  dfs(grid, r - 1, c);
    if (c - 1 >= 0 && grid[r][c - 1] == '1')  dfs(grid, r, c - 1);
    if (r + 1 < nr && grid[r + 1][c] == '1')  dfs(grid, r + 1, c);
    if (c + 1 < nc && grid[r][c + 1] == '1')  dfs(grid, r, c + 1);
  }
};