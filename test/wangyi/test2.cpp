#include <iostream>
#include <vector>
#include <string>
using namespace std;

void add(string& s, int pos) {
  for (int i = pos; i >= 0; i--)
    s += s[i];
  // cout << s;
}
void func(string& s) {
  int len = s.size();
  int i = 0, j = len - 1;
  int start = 0;
  while (i < j) {
    if (s[i] == s[j]) {
      i++;
      j--;
    } else {
      start ++;
      i = start;
      j = len - 1;
    }
  }
  // 此时有部分匹配
  if (j != (len - 1)) {
    // 刚好为回文字符串
    if ((len - 1 - j) == i)
      return;
  }
  add(s, j - 1);
  return;
}

int main() {
  string s;
  cin >> s;
  int len = s.size();
  // for (int i = 0; i < len; i++) {
  //   if (s[i] >= 'A' && s[i] <= 'Z')
  //     s[i] = s[i] + 32;
  // }
  func(s);
  cout << s;
  return 0;
}