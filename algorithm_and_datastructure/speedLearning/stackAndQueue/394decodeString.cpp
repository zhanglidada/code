#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// class Solution {
//  public:
//   /* 
//     要想到这个问题可以分解为子问题的求解，因为存在嵌套的情况
//     注意传入的是string字符串
//    */
//   string decodeString(string s) {
//     if (s.empty())  return "";
//     // 用一个不定长数组模拟栈，最终保存的是所有非括号以及数字的子串栈
//     vector<string> st;
//     size_t ptr = 0;
//     while (ptr < s.size()) {
//       // 当前字母是数字
//       if (isdigit(s[ptr])) {
//         st.push_back(getDigits(s, ptr));
//       } else if (isalpha(s[ptr]) || s[ptr] == '['){
//         // 如果是字母或者左括号则先将单个字母转换为string再入栈
//         st.push_back(string(1, s[ptr++]));
//       } else {
//         // 此时是右括号，需要出栈并计算
//         ptr++;
//         vector<string> sub;
//         while (st.back() != "[") {
//           sub.push_back(st.back());
//           st.pop_back();
//         }
//         st.pop_back();  // 将栈中的"["出栈
//         reverse(sub.begin(), sub.end());
//         int num = stoi(st.back());
//         st.pop_back();
//         string tmp = getString(sub);
//         while (num) {
//           st.push_back(tmp);
//           num --;
//         }
//       }
//     }
//     return getString(st);
//   }
//   // 从当前位置开始，计算
//   string getDigits(string& s, size_t& ptr) {
//     string res = "";
//     while (isdigit(s[ptr])) {
//       res.push_back(s[ptr++]);
//     }
//     return res;
//   }
//   string getString(vector<string>& st) {
//     string res;
//     for (auto str : st) {
//       res += str;
//     }
//     return res;
//   }
// };  

class Solution {
 public:
  // 可以采取递归的方式,遇到左括号则递归解析，遇到右括号进行返回
  string decodeString(string s) {
    if (s.empty())  return "";
    size_t ptr = 0;
    return getString(s, ptr);
  }
  string getString(string& s, size_t& ptr) {
    if (ptr == s.size() || s[ptr] == ']')  return "";
    string res = "";
    // 遇到了第一个数字开始的位置
    if (isdigit(s[ptr])) {
      int repeatnum = getDigits(s, ptr);
      ptr ++;  // 跳过开始的"["
      string sub = getString(s, ptr);
      while (repeatnum) {
        res += sub;
        repeatnum--;
      }
      ptr++;  // 跳过结束的"]"
    } else if (isalpha(s[ptr])) {
      while (isalpha(s[ptr]))
        res += s[ptr++];
    }
    return res + getString(s, ptr);
  }
  int getDigits(string& s, size_t& ptr) {
    int res = 0;
    while (isdigit(s[ptr])) {
      res *= 10;
      res += s[ptr++] - '0';
    }
    return res;
  }
};

int main() {
  Solution ss;
  string s = "3[a2[c]]";
  string res = ss.decodeString(s);
  cout << res;
  return 0;
}