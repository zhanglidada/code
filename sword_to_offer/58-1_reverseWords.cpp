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
    string res, str;
    stack<string> stk;

    // 初始化一个istringstream类，重新读取string串
    istringstream ss(s);

    // 依次添加字符串和空格
    while (ss >> str)  stk.push(str), stk.push(" ");
    // 去除栈顶空格
    if (!stk.empty())  stk.pop();
    // 依次出栈并添加
    while (!stk.empty()) res.append(stk.top()), stk.pop();
    return res;
  }
};

// 不用栈实现
class Solution {
public:
  string reverseWords(string s) {
    string res, str;

    // 初始化一个istringstream类，重新读取string串
    istringstream ss(s);
    
    while(ss >> str)
      res = str.append(" ").append(res);

    // 去除头空格
    return res.substr(0, res.size() - 1);
  }
};

