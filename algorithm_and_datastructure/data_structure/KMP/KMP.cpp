#include <iostream>
#include <string>
#include <vector>

using namespace std;

class KMP{
  public:
    // 初始化构造dp数组，保存状态转移条件
    KMP(string pat) {
      PAT = pat;
      int M = pat.size();
      dp = vector<vector<char>>(M, vector<char>(256, 0));

      // 初始化状态0
      dp[0][pat[0]] = 1;
      x = 0;

      for (int i = 1; i < M; i++) {
        for (int j = 0; j < 256; j++) {
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
    vector<vector<char>> dp;
    int x = 0;
    string PAT;
};

int main() {
  string pat = "aabbc";
  KMP kmp(pat);
  string txt = "icjgkaabbcgh";
  cout << kmp.search(txt);
  return 0;
}