#include <iostream>
#include <vector>
#include <string>

// 利用KMP算法，因为
class Solution
{
  public:
    int strStr(string str, string needle) {
      int n = str.size();
      int m = needle.size();
      string s = needle + '#' + str;
      vector<int> pi(s.size(), 0);

      for (int i = 1; i < s.size(); i++) {
        // 前一个子串的前缀函数值
        int len = pi[i - 1];

        // 当前位置的字符和前一个子串中最长真前后缀匹配串长度的下一个字符不一致
        // 继续查找第二长的
        while (len != 0 && s[i] != s[len])
          len = pi[len - 1];

        // 当前位置的字符同 前一个子串中前缀函数值所代表的串所在结尾的后一个字符 相同
        if (s[i] == s[len]) {
          pi[i] = len + 1;

          if (pi[i] == m)
            return i - m * 2;
        }
      }
      return -1;
    }    
};


int main (int argc, char* argv[])
{

}