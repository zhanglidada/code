#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
bool compare(vector<int>a, vector<int> b) {
  if (a[0] == b[0]) {
    return a[1] > b[1];
  }
  // 正常的情况就是升序
  return a[0] < b[0];
}
int maxBoxes(vector<vector<int>>& boxes) {
  if (boxes.empty())  return 0;
  sort(boxes.begin(), boxes.end(), [](const vector<int>& a, vector<int>& b) {
    return a[0] < b[0] || (a[0]==b[0] && a[1] > b[1]);
  });
  vector<int> dp(boxes.size(), 1);
  int maxSubsize = 0;
  for (int i = 0; i < boxes.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (boxes[i][1] > boxes[j][1])
      dp[i] = max(dp[j] + 1, dp[i]);
    }
    maxSubsize = max(maxSubsize, dp[i]);
  }
  return maxSubsize;
}
/******************************结束写代码******************************/


int main() {
    int res;
    int _boxes_rows = 0;
    int _boxes_cols = 0;
    cin >> _boxes_rows >> _boxes_cols;
    vector<vector<int>> _boxes(_boxes_rows);
    for(int _boxes_i = 0; _boxes_i < _boxes_rows; _boxes_i++) {
        for(int _boxes_j = 0; _boxes_j < _boxes_cols; _boxes_j++) {
            int _boxes_tmp;
            cin >> _boxes_tmp;
            _boxes[_boxes_i].push_back(_boxes_tmp);
        }
    }
    res = maxBoxes(_boxes);
    cout << res << endl;
    
    return 0;

}
