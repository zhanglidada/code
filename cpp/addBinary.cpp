#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
// 采用模拟的方法
class Solution {
 public:
  string addBinary(string a, string b) {
    string ans;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0;
    int maxSize = max(a.size(), b.size());
    for (int i = 0; i < maxSize; i++) {
      carry += (i < a.size()) ? (a.at(i) == '1') : 0;
      carry += (i < b.size()) ? (b.at(i) == '1') : 0;
      ans.push_back((carry % 2) == 0 ? '0' : '1');
      carry = carry / 2;
    }
    // 最后产生了进位
    if (carry)
      ans.push_back('1');
    reverse(ans.begin(), ans.end());
    return ans;
  }
};  */
// 采用位运算的方式
class Solution {
 public:
  string addBinary(string a, string b) {
    int value_a = string_to_int(a), value_b = string_to_int(b);
    while (value_b) {
      int carry = value_a & value_b;
      value_a = value_a ^ value_b;
      value_b = carry << 1;
    }
    return int_to_string(value_a);
  }
  // 总是爆内存错误，烦
  int string_to_int(string str) {
    int sum = 0;
    reverse(str.begin(), str.end());
    for (int i = str.size() - 1; i >= 0; i--) {
      sum = sum * 2 + (str.at(i) - '0');
    }
    return sum;
  }
  string int_to_string(int value) {
    if (value == 0)
      return "0";
    string ans;
    while (value) {
      int tmp = value % 2;
      ans.push_back(('0' + tmp));
      value = value / 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
int main() {
  Solution ss;
  cout << ss.string_to_int("1010") << endl;
  cout << ss.addBinary("0", "0");
  return 0;
}