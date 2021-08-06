#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;


int func(vector<int>& nums,int k) {
  priority_queue<int, vector<int>, greater<int>> heap;
  unordered_set<int> visited;
  int flag = 0;
  int pos = 0;
  for (pos = 0; pos < nums.size(); pos++) {
    if (visited.count(nums[pos]) == 0) {
      visited.insert(nums[pos]);
      if (flag < k) {
        heap.push(nums[pos]);
        flag++;
      } else {
        if (nums[pos] > heap.top()) {
          heap.pop();
          heap.push(nums[pos]);
        }
      }
    }
  }
  return heap.top();
}
int main() {
  int k;
  cin >> k;
  int value;
  vector<int> nums;
  while (cin >> value) {
    nums.push_back(value);
    if (cin.get() == '\n')  break;
  }
  cout << func(nums, k);
}