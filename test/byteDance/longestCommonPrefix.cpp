#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (!strs.size())
      return "";
    int minLength = min_of_str(strs);
    string subStr0 = strs.at(0).substr(0, minLength);
    // 从第i个字符开始循环
    for (int i = 0; i < minLength; i++) {
      for (int j = 1; j < strs.size(); j++) {
        if (strs.at(j).at(i) != subStr0.at(i))
          return subStr0.substr(0, i);
      }
    }
    return subStr0;
  }
  int min_of_str(vector<string>& strs) {
    int min_length = INT32_MIN;
    for (auto str : strs) {
      min_length = str.size() < min_length ? str.size() : min_length;
    }
    return min_length;
  }
};
int main() {
  return 0;
}