#include <iostream>
#include <vector>
using namespace std;

bool func1(string& s) {
  int i = 0, j = s.size() - 1;
  if (s.empty())  return false;
  if (s.size() == 1)  return true;
  while (i <= j) {
    if (s[i] == s[j]) {
      i++;
      j--;
    } else {
      break;
    }
  }
  if (i > j)
    return true;
  return false;
}
vector<int> func(string& s, vector<vector<int>>& nums) {
  int n = nums.size();
  vector<int> res;
  for (int i = 0; i < n ;i++) {
    string sub = s.substr(nums[i][0] - 1, nums[i][1] - nums[i][0] + 1);
    if (sub.size() == 1) {
      res.push_back(1);
      continue;
    }
    int less = 2;
    for (int j = 1; j < sub.size(); j++) {
      string sub1 = sub.substr(0, j);
      string sub2 = sub.substr(j+1, sub.size() - j);
      if (func1(sub1) && func1(sub2))
        less = 2;
      else if (func1(sub1) || func1(sub2)) {
        less = 1;
        break;
      }
    }
    if (func1(sub))
      less = 1;
    res.push_back(less);
  }
  return res;
}
int main() {
  string s;
  cin >> s;
  vector<vector<int>> inputs;
  int n;
  cin >> n;
  while (n) {
    int a,b;
    cin >> a >> b;
    inputs.push_back({a, b});
    n--;
  }
  vector<int> res = func(s, inputs);
  for (auto num : res) {
    cout << num << endl;
  }
  return 0;
}