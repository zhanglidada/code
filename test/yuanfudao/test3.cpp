#include <iostream>
#include <vector>
using namespace std;

int func (int n, int k) {
  int res = 0;
  vector<int> spent;
  int value = (n + 1) / 2;
  spent.push_back(value);
  while (value < n - 1) {
    value = (value + n + 1) / 2;
    spent.push_back(value);
  }
  while (k && !spent.empty()) {
    spent.pop_back();
    k--;
  }
  for (auto num : spent) {
    res += num;
  }
  return res;
}
int main() {
  int n, k;
  cin >> n;
  cin >> k;
  cout << func(n, k);
}