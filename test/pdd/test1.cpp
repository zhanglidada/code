#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const vector<vector<int>>& func1(vector<vector<int>>& matrix, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // n为偶数
      if (n % 2 == 0) {
        if (i == j || (i + j) == n - 1)  matrix[i][j] = 0;
        else if (i < j && i + j < (n - 1)) {
          if (j >= n / 2)  matrix[i][j] = 1;
          else if (j < n / 2) matrix[i][j] = 2;
        }
        else if (i > j && i + j < (n - 1)) {
          if (i < n / 2)  matrix[i][j] = 3;
          else if (i >= n / 2)  matrix[i][j] = 4;
        }
        else if (i > j && (i + j) >= (n - 1)) {
          if (j < n / 2) matrix[i][j] = 5;
          else if (j >= n / 2) matrix[i][j] = 6;
        }
        else if (i < j && (i + j) >= (n - 1)) {
          if (i >= n / 2)  matrix[i][j] = 7;
          else if (i < n / 2) matrix[i][j] = 8;
        }
      } else {  // n为奇数
        if (i == j || (i + j) == n - 1 || (i == n / 2 || j == n / 2))
          matrix[i][j] = 0;
        else if (i < j && i + j < (n - 1)) {
          if (j > n / 2)  matrix[i][j] = 1;
          else if (j < n / 2) matrix[i][j] = 2;
        }
        else if (i > j && i + j < (n - 1)) {
          if (i < n / 2)  matrix[i][j] = 3;
          else if (i > n / 2)  matrix[i][j] = 4;
        }
        else if (i > j && (i + j) >= (n - 1)) {
          if (j < n / 2) matrix[i][j] = 5;
          else if (j > n / 2) matrix[i][j] = 6;
        }
        else if (i < j && (i + j) >= (n - 1)) {
          if (i > n / 2)  matrix[i][j] = 7;
          else if (i < n / 2) matrix[i][j] = 8;
        }
      }
    }
  }
  return matrix;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n, 0));
  func1(matrix, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}