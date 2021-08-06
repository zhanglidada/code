#include <iostream>
#include <vector>
#include <set>
using namespace std;
int func(vector<int>& nums) {
  int x = 0, votes = 0;
  for (auto num : nums) {
    if (votes == 0) x = num;
    votes += num == x ? 1 : -1;
  }
  return x;
}
int main () {
  int n;
  vector<int> nums;
  while (cin >> n) {
    nums.push_back(n);
    if (cin.get() == '\n')  break;
  }
  cout << func(nums);
}