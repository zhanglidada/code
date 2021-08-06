#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 利用内置sort函数
class Solution {
 public:
  string minNumber(vector<int>& nums) {
    vector<string> numstr;
    for (auto num : nums) {
      numstr.push_back(to_string(num));
    }
    // 需要将其升序排序
    sort(numstr.begin(), numstr.end(), [](string x, string y){
      return x + y < y + x;
    });
    string res;
    for (auto num : numstr) {
      res += num;
    }
    return res;
  }
};
int main() {
  Solution ss;
  vector<int> nums = {10,2};
  string res = ss.minNumber(nums);
  cout << res;
}