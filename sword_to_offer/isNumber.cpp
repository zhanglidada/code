#include <iostream>
#include <vector>
using namespace std;

// 空格的判断有问题
class Solution {
 public:
  bool isNumber(string s) {
    auto begin = s.begin();
    if (s.empty())  // 字符为空
      return false;
    // 如果开始字符为正负号
    if (*begin == '-' || *begin == '+') {
      begin ++;
      if (*begin == '-' || *begin == '+')
        return false;  // 连续两个正负号则返回false
      else if (*begin == ' ')
        return false;
    }
    // 符号之后需要判断是否还有数字
    if (*begin == '\0')
      return false;
    int e = 0, number = 0, dot = 0, consistence = 0;
    while (*begin != '\0') {  // 对之后的每个字符进行遍历
      // 数字
      if (*begin <= '9' && *begin >= '0') {
        begin ++;
        number ++;
      } 
      // 小数点
      else if (*begin == '.') {
        // 如果有两个小数点: 12..5  或者在e后面又小数点：12e3.4,false
        if (dot > 0 || e > 0)
          return false;
        begin ++;
        dot ++;
        if (number == 0 && *begin == '\0') {
          return false;
        }
      }
      // 空格
      else if (*begin == ' ') {
        if ((dot > 0 && number == 0) || e > 0)
          return false;
        begin ++;
        if (number > 0)
          consistence ++;
        if (consistence > 0 && (*begin >= '0' && *begin <= '9' || *begin == '.' || *begin == 'e' || *begin == 'E'))
          return false;
      }
      // e
      else if (*begin == 'e' || *begin == 'E') {
        if (number == 0 || e > 0)
          return false;
        begin++;
        e++;
        // e后面可以出现一次正负号
        if (*begin == '-' || *begin == '+') {
          begin ++;
          if (*begin == '-' || *begin == '+')
            return false;  // 连续两个正负号则返回false
          else if (*begin == ' ')
            return false;
        }
        if (*begin == '\0')  // 13e
          return false;
      }
      // 有其他字符的情况
      else {
        return false;
      }
    }
    if (number > 0)
      return true;
    return false;
  }
};
int main() {
  Solution ss;
  string s = " 96 e5  ";
  if (ss.isNumber(s))
    cout << "true";
  else
    cout << "false";
  return 0;
}