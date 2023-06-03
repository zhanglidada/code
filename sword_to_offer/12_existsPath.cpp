#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 
 * 使用深度优先遍历查找字符串
 */
class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    // 设置二维数组行列信息
    rows = board.size();
    cols = board[0].size();

    // 特殊情况直接返回
    if (rows == 1 && cols == 1 && word.size() == 1)
    {
      if (board[0][0] == word[0])  
        return true;
      else  
        return false;
    }
      
    // 从起始节点分别开始dfs查找是否有单词匹配
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++)
        // 从字符矩阵的i，j位置开始，并从头查找字符串匹配
        if (dfs(board, word, i, j, 0))
          return true;
    }
    return false;
  }

  // 深度优先遍历数组
  bool dfs
  (
    vector<vector<char>>& board,  /*IN: 遍历数组*/
    string& word,                 /*IN: 查找字符串*/
    int x,                        /*IN: 当前行pos*/
    int y,                        /*IN: 当前列pos*/
    int strPos                    /*IN: 字符串在word中查找位置*/
  ) 
  {
    // 找到了字符串的尾后位置
    if (strPos == word.size())
      return true;
    
    // 当前字符不匹配，直接报错返回
    if (board[x][y] != word[strPos])
      return false;

    // 从矩阵的当前位置向四周开始进行深度优先遍历
    for (int i = 0; i < 4; i++) {
      // 下一步需要探测的位置
      int a = x + dx[i], b = y + dy[i];
      // 计算边界情况
      if (a >= 0 && a < rows && b >= 0 && b < cols) {
        // 直接在当前数组上修改，设置当前已经访问过的位置不允许dfs过程中重复访问
        char tmp = board[x][y];
        board[x][y] = '*';

        // 如果当前字符匹配，深度优先遍历下一个字符
        if (dfs(board, word, a, b, strPos + 1))
          return true;
        
        // 重置当前字符
        board[x][y] = tmp;
      }
    }
    return false;
  }
 private:
  // 用dx表示上下方向移动，dy表示左右方向移动
  vector<int> dx = {-1, 0, 1, 0};
  vector<int> dy = {0, 1, 0, -1};
  int rows = 0;  // 二维数组行数
  int cols = 0;  // 二维数组列数
};


int main()
{

}