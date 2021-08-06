#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int func(int n, vector<vector<int>>& res) {
  unordered_set<int> set;
  int average = n / 2;
  int count = 0;
  while (average > 9) {
    average = average / 10;
  }
  int a = average;
  set.insert(a);
  int result = n - a * 100 * 2;
  int b,c;
  for (int i = 0; i <= 9; i++) {
    if (set.count(i) == 0) {
      b = i;
      set.insert(b);
      for (int j = 0; j <= 9; j++) {
        if (set.count(j) == 0) {
          c = j;
          set.insert(c);
          if ((b*10 + c + c * 10 + c) == result) {
            count++;
            res.push_back({a*100 + b * 10 + c, a*100 + c*10+c});
          }
          set.erase(c);
        }
      }
      set.erase(b);
    }
  }
  return count;
}
int main() {
  int n;
  cin >> n;
  vector<vector<int>> res;
  int count = func(n, res);
  cout << count << endl;
  for (int i = 0; i < res.size(); i++) {
    cout<< res[i][0] << " " << res[i][1] << endl;
  }
}