#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int func(vector<vector<int>>& inputs, int p) {
  vector<vector<int>> nums;
  for (auto tmp : inputs) {
    int n = tmp[0];
    while (n) {
      nums.push_back({tmp[1], tmp[2]});
      n--;
    }
  }
  sort(nums.begin(), nums.end(), [](vector<int> num1, vector<int> num2){
    return num1[0] < num2[0];
  });
  // for (auto tmp : nums)
  //   cout << tmp[0] << " " << tmp[1] << endl;
  vector<int> dp(p + 1, 0);
  for (int i = 1; i <= p; i++) {
    for (int j = 0; j < nums.size(); j++) {
      int weight = nums[j][0];
      if (i - weight < 0)
        break;
      dp[i]= max(dp[i], (dp[i - weight] + nums[j][1]));
    }
    cout << dp[i] << " ";
  }
  cout << endl;
  return dp[p];
}
int main () {
  int n,p;
  cin >> n >> p;
  vector<vector<int>> inputs;
  while (n) {
    int num, weight, meili;
    cin >> num >> weight >> meili;
    inputs.push_back({num, weight, meili});
    n--;
  }
  cout << func(inputs, p);
}