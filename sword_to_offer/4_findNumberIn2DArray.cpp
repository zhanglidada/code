#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 
 * 将矩阵逆时针旋转45°，类似于二叉搜索树
 * 对于每个节点，其左孩子更小，右孩子更大
 */
class Solution {
 public:
  bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty())
      return false;
    
    // 从最右上方开始查找
    int i = 0, j = matrix[0].size() - 1;
    while (i <= matrix.size() - 1 && j >= 0) {
      if (matrix[i][j] == target)
        return true;
      else if (matrix[i][j] > target)
        j--;
      else
        i++;
    }
    return false;
  }
};
int main() {
  return 0;
}