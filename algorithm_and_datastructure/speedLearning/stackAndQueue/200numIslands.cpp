#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
class Solution {
 public:
  // 可以用一个深度优先遍历来访问二维数组中的所有节点
  int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    visited.resize(m, vector<bool>(n, false));
    // 对每个节点采取深度优先遍历的方式,并记录根节点的数量
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!visited[i][j] && grid[i][j] == '1') {
          // 进入的根节点
          numsIsland++;
          dfs(grid, {i, j});
        }
      }
    }
    return numsIsland;
  }
  // 从一个根节点开始进入深度优先遍历后，对访问过的节点需要修改
  void dfs(vector<vector<char>>& grid, pair<int, int> pos) {
    int m = grid.size(), n = grid[0].size();
    int x = pos.first, y = pos.second;
    // 如果当前节点访问过或者节点值未0，表示走不通；直接返回
    if (visited[x][y] || grid[x][y] == '0')  return;
    visited[x][y] = true;
    if (x + 1 < m) dfs(grid, {x + 1, y});
    if (y + 1 < n) dfs(grid, {x, y + 1});
    if (x - 1 >= 0)  dfs(grid, {x - 1, y});
    if (y - 1 >= 0)  dfs(grid, {x, y - 1});
    return;
  }
 private:
  // 利用一个数组保存节点是否被遍历过
  vector<vector<bool>> visited;
  int numsIsland = 0;
};  */

/*
class Solution {
 public:
  // 采取广度优先的方式对其进行遍历
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty())  return 0;
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        // 从根节点开始进入遍历
        if (grid[i][j] == '1') {
          numsIsland ++;
          neighbours.push({i, j});
          grid[i][j] = '0';  // 在进入之后就要将其置0,防止重复进入队列中
          while (!neighbours.empty()) {
            auto [x, y] = neighbours.front();
            neighbours.pop();
            if (x + 1 < m && grid[x + 1][y] == '1')  neighbours.push({x + 1, y}), grid[x + 1][y] = '0';
            if (x - 1 >= 0 && grid[x - 1][y] == '1')  neighbours.push({x - 1, y}), grid[x - 1][y] = '0';
            if (y + 1 < n && grid[x][y + 1] == '1')  neighbours.push({x, y + 1}), grid[x][y + 1] = '0';
            if (y - 1 >= 0 && grid[x][y - 1] == '1')  neighbours.push({x, y - 1}), grid[x][y - 1] = '0';
          }
        }
      }
    }
    return numsIsland;
  }
 private:
   // queue中保存的是邻居节点的位置信息
   queue<pair<int, int>> neighbours;
   int numsIsland = 0;
}; */

// 还可以采取并查集的方式
class UnionFind {
 public:
  UnionFind(vector<vector<char>>& grid) {
    count = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          // 表示当前为陆地，且count增加(后面会根据联通减去)
          parent.push_back(i * n + j);  // 初始化并查集，每个存在的节点父亲都是自己
          count++;
        }
        else {
          parent.push_back(-1);
        }
        rank.push_back(0);  // 初始每个节点的秩都为0
      }
    }
  }
  // 查找节点的父亲，并进行路径压缩
  int find(int x) {
    // 如果当前节点不为根节点，那么递归向上查找并跟新当前节点的父节点为根节点
    if (x != parent[x]) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }
  // 对x和y所在的并查集进行合并
  void unite(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty) {
      if (rank[rootx] < rank[rooty]) {
        swap(rootx, rooty);  // rooty始终指向有较小秩的根节点
      }
      parent[rooty] = rootx;
      if (rank[rootx] == rank[rooty]) rank[rootx]++;
      --count;
    }
    return;  // 当rootx == rooty的时候直接返回
  }
  int getCount() {
    return count;
  }
 private:
  vector<int> parent;
  vector<int> rank;  // 保存节点的秩
  int count = 0;
};
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty())  return 0;
    int m = grid.size();
    int n = grid[0].size();
    UnionFind UF(grid);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          //grid[i][j] = '0';  // 将当前节点置0表示访问过,防止后续节点遍历过程中重复合并并查集
          if (i - 1 >= 0 && grid[i - 1][j] == '1') UF.unite(i * n + j, (i - 1) * n + j);
          if (i + 1 < m && grid[i + 1][j] == '1')  UF.unite(i * n + j, (i + 1) * n + j);
          if (j - 1 >= 0 && grid[i][j - 1] == '1')  UF.unite(i * n + j, i * n + (j - 1));
          if (j + 1 < n && grid[i][j + 1] == '1')  UF.unite(i * n + j, i * n + (j + 1));
        }
      }
    }
    return UF.getCount();
  }
};