#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution{
  int func(vector<vector<int>>& inputs, int r, int c) {
    int m = inputs.size();
    int n = inputs[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    vector<vector<int>> calc = dp;
    vector<int> tmp(m, 0);
    int minVal = INT32_MAX;
    for (int i = 0; i <= m; i++) {
      for (int j = i + 1; j <= m; j++) {

      }
    }
  }
  void dfs(int dep, int s) {

  }
};


int main () {
  int m,n,r,c;
  vector<vector<int>> inputs;
  vector<int> tmp;
  cin >> m >> n >> r >> c;
  for (int i = 0; i < m; i++) {
    tmp.clear();
    int value;
    for (int j = 0; j < n; j++) {
      cin >> value;
      tmp.push_back(value);
    }
    inputs.push_back(tmp);
  }

}