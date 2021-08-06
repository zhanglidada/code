#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    vector<int> counts(32, 0);
    for (auto num : nums) {
      for (int i = 0; i < 32; i++) {
        counts[i] += num & 1;
        num >>= 1;
      }
    }
    int res = 0, m = 3;
    for (int i = 0; i < 32; i++) {
      res <<= 1;
      res |= (counts[31 - i] % m);
    }
    return res;
  }
};
int main() {
  vector<int> nums = {3,4,3,3};
  Solution ss;
  cout << ss.singleNumber(nums);
}