#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  string replaceSpace(string s) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ')
        count ++;
    }
    int prelength = s.size();
    s.resize(s.size() + count * 2);
    for (int i = prelength - 1; i >= 0; i--) {
      if (s[i] != ' ')
        s[i + count * 2] = s[i];
      else {
        count --;
        s[i + count * 2] = '%';
        s[i + count * 2 + 1] = '2';
        s[i + count * 2 + 2] = '0';
      }
    }
    return s;
  }
};
int main() {
  string s = "we are happy";
  Solution ss;
  cout << ss.replaceSpace(s);
  return 0;
}