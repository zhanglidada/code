#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    if (matrix.empty())  return ans;
    int up = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
    while (true) {
      for (int i = left; i <= right; i++)  ans.push_back(matrix[up][i]);
      if (++ up > down) break;
      for (int i = up; i <= down; i++)  ans.push_back(matrix[i][right]);
      if (-- right < left) break;
      for (int i = right; i >= left; i--)  ans.push_back(matrix[down][i]);
      if (-- down < up) break;
      for (int i = down; i >= up; i--)  ans.push_back(matrix[i][left]);
      if (++ left > right) break;
    }
    return ans;
  }
};
int main() {
  vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
  Solution ss;
  vector<int> res = ss.spiralOrder(matrix);
  for (int i = 0; i < res.size(); i++)
    cout << res[i];
}