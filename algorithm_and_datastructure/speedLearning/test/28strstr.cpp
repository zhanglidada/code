#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/* 暴力方法，逐一比较字符串
class Solution {
 public:
  int strStr(string haystack, string needle) {
    int len = haystack.size(), sublen = needle.size();
    for (int i = 0; i <= len - sublen; i++) {
      if (haystack.substr(i, sublen) == needle)  return i;
    }
    return -1;
  }
};  */

/*
class Solution {
 public:
  int strStr(string haystack, string needle) {
    int len = haystack.size(), sublen = needle.size();
    if (sublen == 0)  return 0;
    int ph = 0, pn = 0;
    for (int i = 0; i <= len - sublen; i++) {
      if (haystack[i] == needle[0]) {
        ph = i, pn = 0;
        // ph开始的位置最大为len - sublen
        while (ph < len && pn < sublen) {
          if (haystack[ph] != needle[pn])  break;
          ph++;
          pn++;
        }
        if (pn == sublen) return i;
      } 
      else  continue;
    }
    return -1;
  }
};  */

// 使用Rabin Karp算法
class Solution {
 public:
  int strStr(string haystack, string needle) {
    int len = haystack.size(), sublen = needle.size();
    if (sublen > len)  return -1;
    int a = 26;
    long long int h = 0, nh = 0;
    for (int i = 0; i < sublen; i++) {
      // 为了提高速度，头部设为最低位
      nh = (nh * a + charToInt(needle[i])) % modules;
      h = (h * a + charToInt(haystack[i])) % modules;
    }
    // 取模存在hash冲突问题，需要判断
    if (nh == h) {
      return compare(haystack.substr(0, sublen), needle) == true ? 0 : -1;
    }
    long long int aL = 1;
    for (int i = 0; i < sublen; i++)  aL = (aL * a) % modules;
    for (int i = sublen; i < len; i++) {
      h = (h * a - charToInt(haystack[i - sublen]) * aL + charToInt(haystack[i])) % modules;
      if (h == nh)  return compare(haystack.substr(i - sublen + 1, sublen), needle) == true ? i - sublen + 1 : -1;
    }
    return -1;
  }
  int charToInt(char a) {
    return (int)(a - 'a');
  }
  bool compare(string s1, string s2) {
    for (int i = 0; i < s1.size(); i++)
      if (s1[i] != s2[i])  return false;
    return true;
  }
 private:
  long long modules = pow(2, 31);
};

/*
class Solution {
 public:
  // 和传统的kmp算法还是有点区别,
  void KMP(string& neddle) {
    pat = neddle;
    int M = pat.size();
    dp = vector<vector<int>>(M, vector<int>(256, 0));
    // 影子状态X初始化为0
    int X = 0;
    // 状态0只有遇到pat[0]才会移动到状态1，遇到其他字符仍然自旋
    dp[0][pat[0]] = 1;
    for (int j = 1; j < M; j++) {
      for (int c = 0; c < 256; c++) {
        if (pat[j] == c)
          dp[j][c] = j + 1;
        else dp[j][c] = dp[X][c];
      }
      // 更新影子状态:当前是状态X,遇到字符pat[j]，应该转移到的状态
      X = dp[X][pat[j]];
      // cout << X << " ";
    }
  }
  int strStr(string haystack, string needle) {
    if (needle.empty())  return 0;
    txt = haystack;
    KMP(needle);
    int M = pat.size(), N = txt.size();
    int j = 0;  // pat字符开始匹配的位置
    for (int i = 0; i < N; i++) {
      // 当前是状态j，遇到字符txt[i],pat应该转移到哪个状态
      j = dp[j][txt[i]];
      if (j == M)  return i - M + 1;
    }
    return -1;
  }
 private:
  string pat, txt;
  vector<vector<int>> dp;
};  */

int main() {
  Solution ss;
  string haystack = "baaaaaaaa", neddle = "bagytisyy";
  cout << ss.strStr(haystack, neddle);
}