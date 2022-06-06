#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 判断一个 9 x 9 的数独是否有效。规则如下：
 * 1.数字 1-9 在每一行只能出现一次。
 * 2.数字 1-9 在每一列只能出现一次。
 * 3.数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 * Notes:
 * 1.一个有效的数独（部分已被填充）不一定是可解的。
 * 2.只需要根据以上规则，验证已经填入的数字是否有效即可。
 * 3.空白格用 '.' 表示。
********************************************************************************************/

/*******************************************************************************************
 * Notes:
 * 分别保存行，列以及每个九宫格的hash表，
 * 一次遍历并分别更新hash表的计数
********************************************************************************************/
class Solution {
  public:
    bool isValidSudoku(vector<vector<char>>& board) {
      // 分别保存行，列以及每个小的九宫格信息
      int rows[9][9] = {0};
      int cols[9][9] = {0};
      int sub_boxs[3][3][9] = {0};
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          c = board[i][j];
          if (c != '.') {
            index = c - '0' - 1;
            // 每个出现的index，同时更新对应的行列信息
            rows[i][index] += 1;
            cols[j][index] += 1;
            sub_boxs[i / 3][j / 3][index] += 1;
            // 不满足条件
            if (rows[i][index] > 1 || cols[j][index] > 1 || sub_boxs[i / 3][j / 3][index] > 1)
              return false;
          }
        }
      }
      return true;
    }
  private:
    char c;
    int index;
};