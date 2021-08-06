#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
using namespace std;

// 深度优先遍历
class Solution {
 public:
  vector<string> permutation(string s) {
    vector<string> res;
    string track;
    if (s.empty())  return {};
    sort(s.begin(), s.end());  // 排序，将重复的字符相邻
    vector<bool> visited(s.size(), false);
    backtrack(res, s, visited, track);
    return res;
  }
  void backtrack(vector<string>& res, string& s, vector<bool>& visited, string& track) {
    // 回溯结束条件
    if (track.size() == s.size()) {
      res.push_back(track);
      //cout << track << endl;
      return;
    }
    // 选择列表
    for (int i = 0; i < s.size(); i++) {
      if (visited[i])
        continue;
      // 当有连续n个重复的字母时，从第一个开始到n-1个深度都是会失败，最终是从最后一个开始深度
      if (i > 0 && visited[i-1] && s[i - 1] == s[i])
        continue;
      visited[i] = true;
      track.push_back(s[i]);
      //cout << s[i];
      backtrack(res, s, visited, track);
      track.pop_back();
      visited[i] = false;
    }
  }
};

// 采用交换法
class Solution {
 public:
  vector<string> permutation(string s) {
    set<string> res;
    backTrack(s, 0, res);
    return vector<string>(res.begin(), res.end());
  }
  // 使用set对字符串进行去重，使用swap交换两个字符,但是没有进行剪枝
  void backTrack(string s, int start, set<string>& res) {
    // 回溯结束条件
    if (start == s.size()) {
      res.insert(s);
      return;
    }
    for (int i = start; i < s.size(); i++) {
      swap(s[i], s[start]);
      backTrack(s, start + 1, res);
      swap(s[i], s[start]);
    }
  }
};

class Solution {
 public:
  vector<string> permutation(string s) {
    dfs(s, 0);
    return res;
  }
  // 使用set对字符串进行去重，使用swap交换两个字符,但是没有进行剪枝
  void dfs(string& s, int start) {
    // 递归终止条件
    if (start == s.size() - 1) {
      res.push_back(s);
      return;
    }
    unordered_set<char> set;
    for (int i = start; i < s.size(); i++) {
      if (set.count(s[i]))  continue;
      set.insert(s[i]);
      swap(s[i], s[start]);
      dfs(s, start + 1);
      swap(s[i], s[start]);
    }
  }
 private:
  vector<string> res;
};
int main() {
  Solution ss;
  string s = "aab";
  ss.permutation(s);
}