#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxScoreSightseeingPair(vector<int>& A) {
    int maxValue = 0;
    int mxt = A[0] + 0;
    for (int j = 1; j < A.size(); j ++) {
      // 统计景点j的时候，将其与之前节点(A[i] + i)的最大值相加;同时设一个值保存在A[j]节点可以得到的最大值
      maxValue = max(maxValue, mxt + A[j] - j);
      // 保存遍历过程中的A[i] + i的最大值
      mxt = max(mxt, A[j] + j);
    }
    return maxValue;
  }
};

int main() {
  vector<int> test = {8,1,5,2,6};
  Solution ss;
  cout << ss.maxScoreSightseeingPair(test);
  return 0;
}