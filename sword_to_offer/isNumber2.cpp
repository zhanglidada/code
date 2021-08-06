#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 有限状态自动机
class Solution {
 public:
  bool isNumber(string s) {
    // 状态转移列表
    unordered_map<char, int> status[9] = {
      {{' ', 0}, {'s', 1}, {'d', 2}, {'.', 4}},  // 0
      {{'d', 2}, {'.', 4}},  // 1
      {{'d', 2}, {'.', 3}, {'e', 5}, {' ', 8}},  // 2
      {{'d', 3}, {'e', 5}, {' ', 8}},  // 3
      {{'d', 3}},  // 4
      {{'s', 6}, {'d', 7}},  // 5
      {{'d', 7}},  // 6
      {{'d', 7}, {' ', 8}},  // 7
      {{' ', 8}}  // 8
    };
    int p = 0;  // 开始状态
    char t;
    for (auto c : s) {
      if (c >= '0' && c <= '9')  t = 'd';
      else if (c == 'e' || c == 'E' || c == '.' || c == ' ')  t = c;
      else if (c == '+' || c == '-')  t = 's';
      else  t = '?';
      if (status[p].count(t) == 0)  return false;
      // at返回key对应的value
      p = (int) status[p].at(t);
    }
    return p == 2 || p == 3 || p == 7 || p == 8;
  }
};