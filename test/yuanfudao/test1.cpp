#include <iostream>
#include <vector>
using namespace std;

vector<int> func(vector<int>& input) {
  vector<int> res;
  vector<vector<int>> nodeslevel;
  int level = 1;
  int i = 0;
  while (i < input.size()) {
    int count = 0;
    vector<int> tmp;
    while (count < level) {
      tmp.push_back(input[i++]);
      count++;
    }
    nodeslevel.push_back(tmp);
    level *= 2;
  }
  // 最左边的节点
  for (int i = 0; i < nodeslevel.size(); i++) {
    res.push_back(nodeslevel[i][0]);
  }
  // 下层的节点
  int height = nodeslevel.size();
  int lastlen = nodeslevel[height - 1].size();
  for (int i = 1; i < lastlen; i++) {
    res.push_back(nodeslevel[height - 1][i]);
  }
  // 右边的节点
  if (lastlen == 2^(height - 1)) {
    int start = height - 2;
    for (int i = start; i > 0; i--) {
      res.push_back(nodeslevel[i][nodeslevel[i].size() - 1]);
    }
  }else {
    for (int i = 1; i < nodeslevel[height - 2].size(); i++) {
      res.push_back(nodeslevel[height - 2][i]);
    }
    int start = height - 3;
    for (int i = start; i > 0; i--) {
      res.push_back(nodeslevel[i][nodeslevel[i].size() - 1]);
    }
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  vector<int> input;
  while (n) {
    int value;
    cin >> value;
    input.push_back(value);
    n--;
  }
  vector<int> res = func(input);
  for (auto num : input) {
    cout << num << " ";
  }
}