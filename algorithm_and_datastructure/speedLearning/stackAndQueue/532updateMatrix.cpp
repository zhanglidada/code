#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
class Solution {
 public:
  // 采用广度优先搜索的方法
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> visited;
    //vector<vector<int>> res;
    int m = matrix.size();
    int n = matrix[0].size();
    visited.resize(m, vector<int>(n, 0));
    //res.resize(m, vector<int>(n, 0));
    queue<pair<int, int>> list;
    // 首先需要将所有的0加入队列中
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          list.push({i, j});
          visited[i][j] = 1;
        }
        matrix[i][j] = 0;  // 置位
      }
    }
    // 从每个0开始依次广度优先遍历并将最近的1入队列，以此循环
    while (!list.empty()) {
      auto [x, y] = list.front();
      list.pop();
      for (int k = 0; k < 4; k++) {
        int rows = x + direction[k][0];
        int cols = y + direction[k][1];
        if (rows >= 0 && rows < m && cols >= 0 && cols < n && visited[rows][cols] == 0) {
          list.push({rows, cols});
          visited[rows][cols] = 1;
          // 因为从{x, y}位置遍历到当前节点
          // res[rows][cols] = res[x][y] + 1;
          matrix[rows][cols] = matrix[x][y] + 1;
        }
      }
    }
    return matrix;
  }
}; */

class Solution {
 public:
  // 可以采用动态规划的方法
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    // 设一个距离矩阵，首先将所有的距离设为最大
    vector<vector<int>> dist(m, vector<int>(n, INT32_MAX / 2));
    // 首先遍历一遍，将所有的0位置上的距离置为0
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0)
          dist[i][j] = 0;
      }
    }
    // 水平向右，竖直向上移动
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i - 1 >= 0)  dist[i][j] = min(dist[i - 1][j] + 1, dist[i][j]);
        if (j - 1 >= 0)  dist[i][j] = min(dist[i][ j - 1] + 1, dist[i][j]);
      }
    }
    // 水平向右，竖直向下
    // for (int i = m - 1; i >= 0; i--) {
    //   for (int j = 0; j < n; j++) {
    //     if (i + 1 < m)  dist[i][j] = min(dist[i + 1][j] + 1, dist[i][j]);
    //     if (j - 1 >= 0)  dist[i][j] = min(dist[i][ j - 1] + 1, dist[i][j]);
    //   }
    // }
    
    // 水平向左，竖直向下
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (i + 1 < m)  dist[i][j] = min(dist[i + 1][j] + 1, dist[i][j]);
        if (j + 1 < n) dist[i][j] = min(dist[i][j + 1] + 1, dist[i][j]);
      }
    }
    // // 水平向左，竖直向上
    // for (int i = 0; i < m; i++) {
    //   for (int j = n - 1; j >= 0; j--) {
    //     if (i - 1 >= 0)  dist[i][j] = min(dist[i - 1][j] + 1, dist[i][j]);
    //     if (j + 1 < n)  dist[i][j] = min(dist[i][j + 1] + 1, dist[i][j]);
    //   }
    // }
    return dist;
  }
};