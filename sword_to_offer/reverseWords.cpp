#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;

// 双指针
class Solution {
 public:
  string reverseWords(string s) {
    int j = s.size() - 1, i = j;
    int flag = 1;
    string res;
    while (i >= 0) {
      // 跳过结尾的空字符
      while (i >= 0 && s[i] == ' ')  i--;
      if (i < 0)  break;
      j = i;  // j指向字符的结尾位置
      // i指向字符开始位置
      while (i >= 0 && s[i] != ' ')  i--;
      if (!flag)  res.append(" ");
      res.append(s.substr(i + 1, j - i));
      flag = 0;
    }
    return res;
  }
};

// 利用栈和isstringstream，其实就分割加倒序列
class Solution {
 public:
  string reverseWords(string s) {
    istringstream ss(s);
    stack<string> stk;
    string res, str;
    while (ss >> str)  stk.push(str), stk.push(" ");
    if (!stk.empty())  stk.pop();
    while (!stk.empty()) res.append(stk.top()), stk.pop();
    return res;
  }
};

// 不用栈实现
class Solution {
public:
  string reverseWords(string s) {
    istringstream ss(s);
    string res, str;
    while(ss >> str)
      res = str.append(" ").append(res);
    return res.substr(0, res.size() - 1);
  }
};

