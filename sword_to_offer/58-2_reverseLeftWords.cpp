#include <iostream>
#include <vector>
using namespace std;
// 字符串拼接
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        for (int i = n; i < s.size(); i++)
        {
            res += s[i];
        }

        for (int i = 0; i < n; i++)
        {
            res += s[i];
        }

        return res;
    }
private:
    string res;
};

// 字符串拼接
class Solution {
public:
  string reverseLeftWords(string s, int n) {
      // 特殊情况提前返回
      if (s.empty() || n > s.size())
        return nullptr;
      
      // 拼接子串
      res += s.substr(n);
      for (int i = 0; i < n; i++)
      {
        res.push_back(s[i]);
      }

      return res;
  }
private:
    string res;    
};