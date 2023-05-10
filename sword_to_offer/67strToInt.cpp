#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*
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

*/

/**
 * @brief 
 * 同样使用有限状态自动机
 * 
 * 
 * @return int 
 */

class Automaton {
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    // 判断字符类型在状态数组中的位置
    int get_col(char c) {
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = table[state][get_col(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT32_MAX ) : min(ans, -(long long)INT32_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};

class Solution {
public:
    int strToInt(string str) {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};


int main() {
  Solution ss;
  cout << ss.strToInt("  42  ");
}