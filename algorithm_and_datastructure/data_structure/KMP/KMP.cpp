#include <iostream>
#include <string>
#include <vector>

using namespace std;

class KMP{
  public:
    // 初始化状态转移数组
    KMP(string pat) {
      PAT = pat;
      int M = pat.size();
      dp = vector<vector<char>>(M, vector<char>(256, 0));

      // 初始化状态0
      dp[0][pat[0]] = 1;
      x = 0;  // 影子从状态0开始

      for (int i = 1; i < M; i++) {  // M+1个状态
        for (int j = 0; j < 256; j++) {  // 所有256个字符
          if (pat[i] == j)
            dp[i][j] = i + 1;
          else
            dp[i][j] = dp[x][j];
        }
        // 更新当前状态i的影子状态x
        x = dp[x][pat[i]];
      }
    }

  int search(string txt) {
    int M = PAT.size();
    int N = txt.size();

    int j = 0;
    for (int i = 0; i < N; i++) {
      j = dp[j][txt[i]];  // 当前状态j遇见txt中的字符，转移到新位置

      // 状态转移到了结束位置，字符串匹配成功
      if (j == M) {
        return i - M + 1;
      }
    }

    // 没有匹配成功
    return -1;
  }
  private:
    vector<vector<char>> dp;  // pat串的状态转移数组
    int x = 0;
    string PAT;  // 模式匹配字符串
};

class Solution {
  public:
    int strStr(string haystack, string needle) {
      if (haystack.empty())  return needle.empty() ? 0 : -1;
      if (needle.empty())  return 0;
      pat = needle;
      dp = vector<vector<int>>(pat.size(), vector<int>(256, 0));
      dfs_gen(haystack.size());
      return search(haystack);
    }

    void dfs_gen(int txt_len) {
      int M = pat.size();
      int N = txt_len;
      
      // 状态初始化
      x = 0;  // 前缀状态，初始为0
      dp[0][pat[0]] = 1;
      for (int i = 1; i < M; i++) {
        // j此时表示值 从0到256 的字符
        for (int j = 0; j < 256; j++) {
          if (pat[i] == j)
            dp[i][j] = i + 1;
          else {
            // 重置为前缀状态x
            dp[i][j] = dp[x][j];
          }
        }
        x = dp[x][pat[i]];  // 更新前缀状态x
      }
    }
    
    // 查找字符串
    int search(string txt) {
      int N = txt.size();
      int M = pat.size();

      if (M > N)  return -1;

      int next = 0;  // pat串中匹配的位置
      for (int i = 0; i <= N; i++) {
        next = dp[next][txt[i]];

        if (next == M)
          return i - M + 1;
      }
      
      return -1;
    }
  
  private:
    vector<vector<int>> dp;  // pat串的状态转移数组
    string pat;
    int x = 0;
};

int main() {
  string pat = "aabbc";
  Solution s;
  string txt = "icjgkaabbcgh";
  cout << s.strStr(txt, pat);
  return 0;
}