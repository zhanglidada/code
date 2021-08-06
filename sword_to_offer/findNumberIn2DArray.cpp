#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty())
      return false;
    int i = 0, j = matrix[0].size() - 1;  // i行j列
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