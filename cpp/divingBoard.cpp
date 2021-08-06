#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> divingBoard(int shorter, int longer, int k) {
    vector<int> ans;
    if (k == 0)
      return ans;
    if (shorter == longer) {
      ans.push_back(shorter * k);
      return ans;
    }
    for (int i = 0; i <=k; i++) {
      ans.push_back(i * longer + (k - i) * shorter);
    }
    return ans;
  }
};
int main() {
  return 0;
}