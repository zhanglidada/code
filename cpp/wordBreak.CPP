#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
// 采用动态规划的方式
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    // 建立一个字典hash表
    auto dictTable = unordered_set<string>();
    for (auto word : wordDict) {
      dictTable.insert(word);
    }
    auto dp = vector<bool>(s.size() + 1);
    // 开始的
    dp[0] = true;
    // dp[i]为从0~i-1的字符串是否合法
    for (int i = 1; i <= s.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (dp[j] && dictTable.find(s.substr(j, i - j)) != dictTable.end()) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[s.size()];
  }
};  */

/*//优化之后的代码
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    if (s.size() == 0) return true;
    if (s.size() >= 151) return false;
    // 对于词典中的每个单词，如果在当前字符串的开始满足
    for (auto word : wordDict) {
      if (s.substr(0, word.size()) == word) {
        cout << word << " ";
        // 将字符串符合的开始字串去除，进行后面匹配
        if (wordBreak(s.substr(word.size(), s.size() - word.size()), wordDict))
          return true;
      }
    }
    return false;
  }
};  */


int main() {
  string s = "leetcode";
  vector<string> wordDict = {"leet", "code"};
  Solution ss;
  cout << ss.wordBreak(s,wordDict);
  return 0;
}