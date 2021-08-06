#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  string multiply(string num1, string num2) {
    string ans;
    vector<int> a,b,c;
    c.resize(num1.size() + num2.size());
    // 先将其倒序进行插入
    for (int i = num1.size() - 1; i>= 0; i--)
      a.push_back(num1.at(i) - '0');
    for (int j = num2.size() - 1; j>=0; j--)
      b.push_back(num2.at(j) - '0');

    for (int i = 0; i< num1.size(); i++) {
      for (int j = 0; j < num2.size(); j++) {
        c[i + j] += a[i] * b [j];
      }
    }
    int k = 0;
    for (int i = 0; i < c.size() - 1; i++) {
      k += c.at(i);
      char c = k % 10 + '0';
      ans = c + ans;
      k = k / 10;
    }
    if (k) {
      char c = k + '0';
      ans = c + ans;
    }
    // 判断一个为乘数0的特殊情况
    while (ans.size() > 1 && ans.at(0) == '0')
      ans.erase(ans.begin());
    return ans;
  }
};

int main() {
  string s1 = "999", s2 = "0";
  Solution ss;
  cout << ss.multiply(s1, s2);
  return 0;
}