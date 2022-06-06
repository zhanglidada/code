#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;
/*******************************************************************************************
Purpose:
  将所有被X包围的O都变为X
Notes:
  1.本题有三种解法，深度优先，广度优先以及并查集三种
  2.由于任何边界上的O都不会被填充为X，所以不被包围的O都直接或者间接和边界上的O相连
  3.对于每个边界上的O，以它为起点，标记所有与其直接或者间接接触的点
  并最后对矩阵进行遍历，非标记的O节点修改为X
********************************************************************************************/

/*******************************************************************************************
Purpose:
  1. 深度优先dfs,采用递归方式
Notes:
  将标记过的字母O改为字母A
********************************************************************************************/
// class Solution {
//   public:
//     void solve(vector<vector<char>>& board) {
//       n = board.size();
//       if (n == 0) return;

//       m = board[0].size();
//       // 左右边界dfs
//       for (int i = 0; i < n; i++) {
//         dfs(board, i, 0);
//         dfs(board, i, m - 1);
//       }

//       // 上下边界dfs
//       for (int i = 1; i < m - 1; i++) {
//         dfs(board, 0, i);
//         dfs(board, n - 1, i);
//       }

//       // 将dfs后的矩阵中A替换为O，O替换为X
//       for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//           if (board[i][j] == 'A')
//             board[i][j] = 'O';
//           else if (board[i][j] == 'O')
//             board[i][j] = 'X';
//         }
//       }
//     }

//     void dfs(vector<vector<char>>& board, int row, int col) {
//       // 边际条件
//       if (row < 0 || row >= n || col < 0 || col >= m || board[row][col] != 'O')
//         return;
      
//       board[row][col] = 'A';  // 修改O为A
//       dfs(board, row + 1, col);
//       dfs(board, row - 1, col);
//       dfs(board, row, col + 1);
//       dfs(board, row, col - 1);
//     }
//   private:
//     int n = 0;  // 行
//     int m = 0;  // 列
// };

/*******************************************************************************************
Purpose:
  2. 深度优先dfs，采用非递归方式
Notes:
  非递归的方式需要记录每一次访问过的位置，使用stack记录
  每次查看栈顶，并访问其上下左右四个位置，直到都访问结束才pop栈顶
********************************************************************************************/
// class Solution {
//   public:
//     void solve(vector<vector<char>>& board) {
//       if (board.empty()) return;
//       n = board.size();
//       m = board[0].size();

//       // 第一列和最后一列边界元素判断
//       for (int i = 0; i < n; i++) {
//         if (board[i][0] == 'O') dfs(board, i, 0);
//         if (board[i][m - 1] == 'O') dfs(board, i, m - 1);
//       }
//       // 第一行和最后一行剩余边界元素判断
//       for (int j = 1; j < m - 1; j++) {
//         if (board[0][j] == 'O')  dfs(board, 0, j);
//         if (board[n - 1][j] == 'O') dfs(board, n - 1, j);
//       }

//       // 最后对矩阵进行处理，替换非边界O节点为X节点
//       for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//           if (board[i][j] == 'A')
//             board[i][j] = 'O';
//           else if (board[i][j] == 'O')
//             board[i][j] = 'X';
//         }
//       }

//     }
//     void dfs(vector<vector<char>>& board, int pos_x, int pos_y) {
//       st.emplace(pos_x, pos_y);
//       board[pos_x][pos_y] = 'A';
      
//       while (!st.empty()) {
//         // 获取栈顶元素
//         auto [current_x, current_y] = st.top();
//         // 边际条件判断，非递归方式
//         if (current_x - 1 >= 0 && board[current_x - 1][current_y] == 'O') {
//           st.emplace(current_x - 1, current_y);
//           board[current_x - 1][current_y] = 'A';
//           continue;
//         }
//         if (current_x + 1 < n && board[current_x + 1][current_y] == 'O') {
//           st.emplace(current_x + 1, current_y);
//           board[current_x + 1][current_y] = 'A';
//           continue;
//         }
//         if (current_y - 1 >= 0 && board[current_x][current_y - 1] == 'O') {
//           st.emplace(current_x, current_y - 1);
//           board[current_x][current_y - 1] = 'A';
//           continue;
//         }
//         if (current_y + 1 < m && board[current_x][current_y + 1] == 'O') {
//           st.emplace(current_x, current_y + 1);
//           board[current_x][current_y + 1] = 'A';
//           continue;
//         }
//         st.pop();  // 四个方向搜索完毕，找不到出栈当前元素
//       }
//     }
//   private:
//     stack<pair<int, int>> st;
//     int n, m;
// };


/*******************************************************************************************
Purpose:
  3. 广度优先,非递归方法：
  将边界上的O全部入队，采用队列保存信息
Notes:

********************************************************************************************/
// class Solution {
//   public:
//     void solve(vector<vector<char>>& board) {
//       n = board.size();
//       if (n == 0) return;

//       m = board[0].size();
//       // 边界的O元素下标入队
//       for (int i = 0; i < n; i++) {
//         if (board[i][0] == 'O') {
//           que.emplace(i, 0);
//           board[i][0] = 'A';
//         }
//         if (board[i][m - 1] == 'O') {
//           que.emplace(i, m - 1);
//           board[i][m - 1] = 'A';
//         }
//       }

//       for (int j = 1; j < m - 1; j++) {
//         if (board[0][j] == 'O') {
//           que.emplace(0, j);
//           board[0][j] = 'A';
//         }
//         if (board[n - 1][j] == 'O') {
//           que.emplace(n - 1, j);
//           board[n - 1][j] = 'A';
//         }
//       }
//       // 广度优先遍历O节点
//       while (!que.empty()) {
//         // 取出队首节点
//         auto [x, y] = que.front();
//         que.pop();

//         for (int i = 0; i < 4; i++) {
//           int new_x = x + dx[i];
//           int new_y = y + dy[i];
//           if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m || board[new_x][new_y] != 'O')
//             continue;
          
//           que.emplace(new_x, new_y);
//           board[new_x][new_y] = 'A';
//         }
//       }

//       // 将bfs后的矩阵中A替换为O，O替换为X
//       for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//           if (board[i][j] == 'A')
//             board[i][j] = 'O';
//           else if (board[i][j] == 'O')
//             board[i][j] = 'X';
//         }
//       }
//     }
//   private:
//     // 广度优先遍历方向
//     const int dx[4] = {1, -1, 0, 0};
//     const int dy[4] = {0, 0, 1, -1};
//     int n = 0;
//     int m = 0;
//     queue<pair<int, int>> que;  // 边界O节点队列
// };

/*******************************************************************************************
Purpose:
  并查集
Notes:
  将所有边界上的O节点视为一个集合
********************************************************************************************/
class Solution {
  public:
    void solve(vector<vector<char>>& board) {
      if (board.empty())  return;
      n = board.size();
      m = board[0].size();

      int dummy_node = n * m;  // 所有边界O节点的根节点
      make_set(dummy_node + 1);  // 初始化parent
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          // 仅对值为O的节点进行并查处理
          if (board[i][j] == 'O') {
            // 边界节点处理
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
              union_set(node(i, j), dummy_node);
            }
            else {
              // 将当前O节点和周围O节点进行合并
              if (i > 0 && board[i - 1][j] == 'O') {
                union_set(node(i, j), node(i - 1, j));
              }
              if (i < n - 1 && board[i + 1][j] == 'O') {
                union_set(node(i, j), node(i + 1, j));
              }
              if (j > 0 && board[i][j - 1] == 'O') {
                union_set(node(i, j), node(i, j - 1));
              }
              if (j < m - 1 && board[i][j + 1] == 'O') {
                union_set(node(i, j), node(i, j + 1));
              }
            }  // if (board[i][j] == 'O')
          }  // if (board[i][j] == 'O')
        }  // for (int j = 0; j < m; j++)
      }  // for (int i = 0; i < n; i++)

      // for (int i = 0; i < n; i++) {
      //   for (int j = 0; j < m; j++) {
      //     cout << find(i * m + j) << " ";
      //   }
      //   cout << endl;
      // }

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          // 判断当前节点和边界O集合的关系
          if (is_connected(node(i, j), dummy_node))
            board[i][j] = 'O';
          else
            board[i][j] = 'X';
        }
      }
    }
  
  private:
    vector<int> parents;
    
    // 初始化所有节点的根节点
    void make_set(int total_nodes) {
      parents = vector<int>(total_nodes, 0);
      for (int i = 0; i < total_nodes; i++) {
        parents[i] = i;
      }
    }
    // 合并两个并查集
    void union_set(int node1, int node2) {
      int root1 = find(node1);
      int root2 = find(node2);
      if (root1 != root2) {
        parents[root2] = root1;
      }
    }
    // 查找集合的根
    int find(int node) {
      if (parents[node] == node)  return node;
      parents[node] = find(parents[node]);  // 压缩路径
      return parents[node];  // 递归返回最终的根节点
    }

    // 判断两个节点是否为一个集合
    bool is_connected(int node1, int node2) {
      return find(node1) == find(node2);
    }
    // 将二维坐标转换为1维值
    int node(int i, int j) {
      return i * m + j;  // 注意，乘的是列个数
    }

    // 横纵坐标
    int n = 0;
    int m = 0;
};

int main() {
  vector<vector<char>> board = {
    {'X','O','X','O','X','O'},
    {'O','X','O','X','O','X'},
    {'X','O','X','O','X','O'},
    {'O','X','O','X','O','X'}
  };
  Solution ss;
  ss.solve(board);
}