#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* 采用深度优先的方式进行遍历
class Solution {
 public:
  int movingCount(int m, int n, int k) {
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    return dfs(0, 0, m, n, k, visited);
  }
  int dfs(int i, int j, int m, int n, int k, vector<vector<bool>>& visited) {
    // 递归的出口
    if (i >= m || j >= n || get(i) + get(j) > k || visited[i][j] == true)
      return 0;
    visited[i][j] = true;
    // 对深度优先遍历进行简化，每次只向下和右进行遍历
    // 注意，存在不可达的解，即满足要求但是机器人不可达
    return 1 + dfs(i + 1, j, m, n, k, visited) + dfs(i, j + 1, m, n, k, visited);
  }
 private:
  int get(int x) {
    int res = 0;
    while (x) {
      res += x % 10;
      x = x / 10;
    }
    return res;
  }
};  */

/* 采用广度优先遍历的方法，利用一个队列进行存储
class Solution {
 public:
  int movingCount(int m, int n, int k) {
    if (!k)
      return 1;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    // 向下和向右进行广度优先遍历
    vector<int> dx = {1, 0}, dy = {0, 1};
    queue<pair<int, int>> bfsqueue;
    bfsqueue.push({0, 0});
    visited[0][0] = true;
    int ans = 1;
    while (!bfsqueue.empty()) {
      auto x = bfsqueue.front().first;
      auto y = bfsqueue.front().second;
      bfsqueue.pop();
      for (int i = 0; i < 2; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        // 注意判断的先后顺序，非常重要，防止数组越界
        if (tx < m && ty < n && !visited[tx][ty] && (get(tx) + get(ty)) <= k) {
          visited[tx][ty] = true;
          bfsqueue.push({tx, ty});
          ans += 1;
        }
      }
    }
    return ans;
  }
 private:
  int get(int x) {
    int res = 0;
    while (x) {
      res += x % 10;
      x = x / 10;
    }
    return res;
  }
}; */

// 采用dp方法，遍历每个格子同时增加返回结果
class Solution {
 public:
  int movingCount(int m, int n, int k) {
    if (!k)
      return 1;
    vector<vector<int>> visited(m, vector<int>(n, 0));
    int ans = 1;
    visited[0][0] = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (get(i) + get(j) > k || (i == 0 && j == 0)) continue;
        if (i - 1 >= 0) visited[i][j] |= visited[i - 1][j];
        if (j - 1 >= 0) visited[i][j] |= visited[i][j - 1];
        ans += visited[i][j];  // 
      }
    }
    return ans;
  }
 private:
  int get(int x) {
    int res = 0;
    while (x) {
      res += x % 10;
      x = x / 10;
    }
    return res;
  }
};
int main() {
}