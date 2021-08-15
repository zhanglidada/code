#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int numTrees(int n) {
      if (n <= 1)  return 1;
      vector<int> dp(n + 1, 0);
      dp[0] = 1;
      dp[1] = 1;
      for (int i = 2; i <= n; i++) {
        // 从1为根到以i为根节点的二叉搜索树
        for (int j = 1; j <= i; j++) {
          dp[i] += dp[j - 1] * dp[i - j];
        }
      }
      return dp[n];
    }
};

int main() {

  return 0;
}