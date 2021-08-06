#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    int rows = board.size(), cols = board[0].size();
    if (rows == 1 && cols == 1 && word.size() == 1)
      if (board[0][0] == word[0])  return true;
      else  return false;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++)
        // 从字符矩阵的i，j位置开始，并从头查找字符串匹配
        if (dfs(board, word, rows, cols, i, j, 0))
          return true;
    }
    return false;
  }
  bool dfs(vector<vector<char>>& board, string& word, int rows, int cols, int x, int y, int strPos /*字符串的查找位置*/) {
    // 找到了字符串的尾后位置
    if (strPos == word.size())
      return true;
    // 从矩阵的当前位置向四周开始进行深度优先遍历
    for (int i = 0; i < 4; i++) {
      int a = x + dx[i], b = y + dy[i];
      // 计算边界情况
      if (a >= 0 && a < rows && b >= 0 && b < cols && board[a][b] == word[strPos]) {
        char tmp = board[a][b];
        board[a][b] = '*';
        // 如果当前字符匹配，深度优先遍历下一个字符
        if (dfs(board, word, rows, cols, a, b, strPos + 1))
          return true;
        board[a][b] = tmp;
      }
    }
    return false;
  }
 private:
  // 用dx表示上下方向移动，dy表示左右方向移动
  vector<int> dx = {-1, 0, 1, 0};
  vector<int> dy = {0, 1, 0, -1};
};