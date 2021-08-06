#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 去除string的首尾空格 *************************************************************************************
//1.此时是截取第一个有效的
void rmvSpace1(string& s) {
  int start = 0, end = 0;
  for (start = 0; start < s.size(); start++) {
    if (s[start] != ' ')  break;
  }
  for (int j = start; j < s.size(); j++) {
    if (s[j] == ' ') {
      end = j;
      break;
    }
  }
  s = s.substr(start, end - start);
}
// 2.获得第一个连续字符串
void rmvSpace2(string& s) {
  int st = s.find_first_not_of(' ');
  int end = s.find_first_of(' ', st);  // 从st位置开始查找位置
  s = s.substr(st, end - st);
}
// 3.只将首尾空格取消
void rmvSpac3(string& s) {
  // 分别找到第一个和最后一个非空格字符
  int st = s.find_first_not_of(' ');
  int en = s.find_last_not_of(' ');
  s = s.substr(st, en - st + 1);
}


int main() {
  string s = "   abcdafda fdsfssf s d    fdgf ";
  rmvSpace2(s);
  cout << s;
  return 0;
}