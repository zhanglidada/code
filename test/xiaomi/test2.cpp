#include <iostream>
#include <vector>
#include <string>
using namespace std;
class solution {
 public:
  solution(vector<vector<char>>& matrix, string s) {
    visit = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 1));
    target = s;
  }
  int func1(vector<vector<char>>& matrix, int rows, int cols, int pos) {
    for (int i = rows; i < matrix.size(); i++) {
      for (int j = cols; j < matrix[0].size(); j++) {

      }
    }
  }
  int func2(vector<vector<char>>& matrix, int rows, int cols, int pos) {
    if (visit[i][j] == 1 && matrix[i][j] == target[pos]) {
      visit[i][j] = 0;
      pos ++;
      if (j < matrix[0].size() - 1 && visit[i][j + 1]) func(matrix, i, j + 1, pos);
      if (j > 0 && visit[i][j - 1]) func(matrix, i, j - 1, pos);
      if (i < matrix.size() - 1 && visit[i + 1][j]) func(matrix, i + 1, j, pos);
      if (i > 0 && visit[i - 1][j]) func(matrix, i - 1, j, pos);
      visit[i][j] = 1;
      pos --;
    }
  }
 private:
  vector<vector<int>> visit;
  string target;
};
int main() {
  string s;
  cin >> s;
  vector<vector<char>> matrix = {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
  };
  solution ss(matrix, s);
  int res = ss.func(matrix, 0, 0, 0);
  if (res == 1)  cout << true;
  else cout << false;
  return 0;
}