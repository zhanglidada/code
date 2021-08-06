#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int strToInt(string str) {
    int i = 0;
    for (i = 0; i < str.size(); i++)
      if (str[i] != ' ')  break;
    str = str.substr(i, str.size());
    int boundary = INT32_MAX / 10, res = 0;
    int st = 1;
    if (str[0] == '-')  sign = -1;
    else if (str[0] != '+')  st = 0;
    for (int j = st; j < str.size(); j++) {
      if (str[j] > '9' || str[j] < '0')  break;
      if (res > boundary || (res == boundary && str[j] > '7')) return sign == 1 ? INT32_MAX : INT32_MIN;
      res = res * 10 + (str[j] - '0');
    }
    return sign * res;
  }
 private:
  int sign = 1;
};

int main() {
  Solution ss;
  cout << ss.strToInt("  42  ");
}