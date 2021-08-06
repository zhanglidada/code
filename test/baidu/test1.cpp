#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> func(int len, vector<vector<int>>& input) {
  vector<int> res(len + 1, 0);
  for (int i = 0; i < input.size(); i++) {
    for (int le = input[i][0]; le <= input[i][1]; le++) {
      res[le] ++;
    }
  }
  return res;
}
int main () {
  int t;
  cin >> t;
  vector<vector<int>> outputs;
  while (t) {
    int L, n;
    cin >> L >> n;
    vector<vector<int>> tmp;
    while (n) {
      int a, b;
      cin >> a >> b;
      tmp.push_back({a, b});
      n--;
    }
    outputs.push_back(func(L, tmp));
    t--;
  }
  for (int i = 0; i < outputs.size(); i++) {
    for (int st = 1; st < outputs[i].size(); st++) {
      cout << outputs[i][st] << " ";
    }
    cout << endl;
  }
}