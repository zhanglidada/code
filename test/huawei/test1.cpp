#include <iostream>
#include <vector>
using namespace std;

class Sloution{
 public:
  void printRes() {
    cout << "[";
    for (int i = 0; i< res.size(); i++) {
      if (i == res.size() - 1) {
        cout << "[" << res[i][0] << "," << res[i][1] << "]";
      } else {
        cout << "[" << res[i][0] << "," << res[i][1] << "],";
      }
      cout << "]" << endl;
    }
  }
  void getLenupdown(vector<vector<int>> array, int n, int m) {
    int tR = 0; // 行
    int tC = 0;
    int dR = n-1;
    int dC = m-1;
    int cur = 1;
    while (tR <= dR && tC <= dC) {
      getEdge(array, tR++, tC++, dR--, dC--, cur);
    }
  }
  void getEdge(vector<vector<int>> m, int tR, int tC, int dR, int dC, int& cur_num) {
    // 边界情况
    if (tR == dR) {
      for (int i = tC; i <= dC; i++) {
        if (cur_num % 10 == 7 && (cur_num / 10 % 10) % 2 == 1) {
          res.push_back({tR, i});
        }
        cur_num ++;
      }
    } else if (tC == dC){
      for (int i = tR; i <= dR; i++) {
        if (cur_num % 10 == 7 && (cur_num / 10 % 10) % 2 == 1) {
          res.push_back({i, tC});
        }
        cur_num ++;
      }
    } else {
      int curC = tC;
      int curR = tR;
      while (curC != dC) {
        if (cur_num % 10 == 7 && (cur_num / 10 % 10) % 2 == 1) {
          res.push_back({tR, curC});
        }
        cur_num ++;
        curC ++;
      }
      while (curR != dR) {
        if (cur_num % 10 == 7 && (cur_num / 10 % 10) % 2 == 1) {
          res.push_back({curR, dC});
        }
        cur_num ++;
        curR ++;
      }
      while (curC != tC) {
        if (cur_num % 10 == 7 && (cur_num / 10 % 10) % 2 == 1) {
          res.push_back({dR, curC});
        }
        cur_num ++;
        curC --;
      }
      while (curR != tR) {
        if (cur_num % 10 == 7 && (cur_num / 10 % 10) % 2 == 1) {
          res.push_back({curR, tC});
        }
        cur_num ++;
        curR --;
      }
    }
  }
 private:
  vector<vector<int>> res;
};

int main() {
  int n,m;
  cin >> n >> m;
  if (n < 10 || n > 1000 || m < 10 || m > 1000) {
    cout << "[]" << endl;
    return 0;
  }
  vector<vector<int>> arr(n, vector<int>(m, 0));
  Sloution ss;
  ss.getLenupdown(arr, n,m);
  ss.printRes();
  return 0;
}