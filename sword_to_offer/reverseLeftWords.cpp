#include <iostream>
#include <vector>
using namespace std;
// 字符串拼接
class Solution {
 public:
  string reverseLeftWords(string s, int n) {
    int len = s.size();
    return s.substr(n, len - 2) + s.substr(0, n);
  }
};

// 列表遍历拼接
class Solution {
 public:
  string reverseLeftWords(string s, int n) {
    string res;
    for (int i = n; i < n + s.size(); i++) {
      res.push_back(s[i % s.size()]);
    }
    return res;
  }
};