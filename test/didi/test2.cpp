#include <iostream>
#include <vector>
using namespace std;

void func(int n, vector<vector<int>>& res) {
  int str = 0;
  int endr = n - 1;
  int stc = 0;
  int endc = n - 1;
  int startx, starty;
  int dp0 = 0, dp1 = 1;
  // 奇数
  if (n % 2 == 1) {
    startx = (n + 1) / 2;
    starty = startx;
    res[startx][starty] = 1;
    while (startx < endc) {
      startx++;
      res[startx][starty] = dp1;
      dp0 = dp1;
      dp1 += dp0;
    }
    while (starty > str) {
      starty--;
      res[startx][starty] = dp1;
      dp0 = dp1;
      dp1 += res[startx][starty];
    }
    while (startx > stc) {
      startx--;
      res[startx][starty] = dp1;
      dp0 = dp1;
      dp1 += res[startx][starty];
    }
    while (starty < endr) {
      starty++;
      res[startx][starty] = dp1;
      dp0 = dp1;
      dp1 += res[startx][starty];
    }
  } else {
    startx = n / 2 + 1;
    starty = n / 2;
    while (startx > stc) {
      startx--;
      res[startx][starty] = dp1;
      dp0 = dp1;
      dp1 += res[startx][starty];
    }
    while (starty < endr) {
      starty++;
      res[startx][starty] = dp1;
      dp0 = dp1;
      dp1 += res[startx][starty];
    }
    while (startx < endc) {
      startx++;
      res[startx][starty] = dp1;
      dp0 = dp1;
      dp1 += res[startx][starty];
    }
    while (starty > str) {
      starty--;
      res[startx][starty] = dp1;
      dp0 = dp1;
      dp1 += res[startx][starty];
    }
  }

}
int main() {
  int n;
  cin >> n;
  vector<vector<int>> res;
  func(n, res);
  for (int i = 0; i < n; i++) {
    for (int j = 0; i < n; i++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}