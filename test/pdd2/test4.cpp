#include <iostream>
#include <vector>
using namespace std;

int func(int N, int M) {
  vector<vector<int>> dp(N, vector<int>(M, 0));
  
}
int main() {
  int N, M;
  cin >> N >> M;
  cout << func(N, M);
  return 0;
}