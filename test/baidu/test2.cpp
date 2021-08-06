#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> func(vector<int>& tmp1, vector<int>& tmp2) {
  vector<int> res(tmp1.size() + 1, -1);
  // key 是值，value是下标
  unordered_map<int, int> map1, map2;
  for (int i = 0; i < tmp1.size(); i++) {
    map1[tmp1[i]] = i + 1;
  }
  for (int i = 0; i < tmp2.size(); i++) {
    map2[tmp2[i]] = i + 1;
  }
  sort(tmp1.begin(), tmp1.end());
  sort(tmp2.begin(), tmp2.end());
  for (int i =0, j = 0; i < tmp1.size() && j < tmp2.size();) {
    if (tmp1[i] <= tmp2[j]) {
      res[map1[tmp1[i]]] = map2[tmp2[j]];
      i++;
      j++;
    }
    else if (tmp1[i] > tmp2[j]) {
      j++;
    }
  }
  return res;
}
int main () {
  int t;
  cin >> t;
  vector<vector<int>> outputs;
  while (t) {
    int n, m;
    cin >> n >> m;
    vector<int> tmp1;
    vector<int> tmp2;
    while (n) {
      int value;
      cin >> value;
      tmp1.push_back(value);
      n--;
    }
    while (m) {
      int value;
      cin >> value;
      tmp2.push_back(value);
      m--;
    }
    vector<int> res = func(tmp1, tmp2);
    for (int i = 1; i< res.size(); i++)  cout << res[i] << " ";
    cout << endl;
    t--;
  }
}