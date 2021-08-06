#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// bool compare(vector<int>a, vector<int> b) {
//   // w相等的时候进行降序
//   if (a[0] == b[0]) {
//     return a[1] > b[1];
//   }
//   // 正常的情况就是升序
//   return a[0] < b[0];
// }

/* 改为lambda表达式传入sort函数中内存消耗减少很多 
class Solution {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    if (envelopes.empty())  return 0;
    sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, vector<int>& b) {
      return a[0] < b[0] || (a[0]==b[0] && a[1] > b[1]);
    });
    vector<int> dp(envelopes.size(), 1);
    int maxSubsize = 0;
    for (int i = 0; i < envelopes.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (envelopes[i][1] > envelopes[j][1])
        dp[i] = max(dp[j] + 1, dp[i]);
      }
      maxSubsize = max(maxSubsize, dp[i]);
    }
    return maxSubsize;
  }
};  */


int main() {
  vector<vector<int>> envelpoes = {{5,4}, {6,4}, {6,7}, {2,3}};
  sort(envelpoes.begin(),envelpoes.end(), compare);
  for(int i = 0; i < envelpoes.size(); i++) {
    cout << envelpoes[i][0] << "," << envelpoes[i][1] << " ";
  }
  //Solution ss;

}