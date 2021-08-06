#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> func(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  int len = nums.size();
  vector<vector<int>> res;
  for (int i = 0; i < len - 2; i++) {
    if (2*nums[len - 1] < nums[i]) i++;
    if (nums[i] > 0)  break;
    if (i > 0 && nums[i] == nums[i -1])  continue;
    int left = i + 1, right = nums.size() - 1, target = 0 - nums[i];
    while (left < right) {
      if ((nums[left] + nums[right]) < target)  left ++;
      else if ((nums[left] + nums[right]) > target)  right --;
      else {
        vector<int> tmp = {nums[i], nums[left], nums[right]};
        res.push_back(tmp);
        left ++;
        right --;
      }
    }
  }
  return res;
}
int main() {
  int n;
  vector<int> nums;
  while (cin >> n) {
    nums.push_back(n);
    if (cin.get() == '\n')  break;
  }
  vector<vector<int>> res = func(nums);
  for (int i = 0; i < res.size(); i++) {
    for (auto num : res[i])
      cout << num << " ";
    cout << endl;
  }
}