#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <string>
using namespace std;

/**
 * @brief 
 * 输入一个字符串，打印出该字符串中字符的所有排列。
 * 
 */


/***************************************************************************
 * 1. 使用回溯法，从头到尾依次填充
 * 
 * 填入每个空位的时候保证重复字符只会被填入一次，防止重复排列生成
 * 1）先对原始字符串排序，保证重复的字符相邻
 * 2）递归函数中，限制当前位置每次填入的字符一定是这个字符所在重复字符集合中
 * 从左往右第一个出现的字符
****************************************************************************/
class Solution {
 public:
  vector<string> permutation(string s) {
    vector<string> res;
    string track;  // 一次递归结果串

    // 空串直接返回
    if (s.empty())  return {};

    // 排序，将重复的字符相邻
    sort(s.begin(), s.end());

    // 字符访问数组
    vector<bool> visited(s.size(), false);

    // 穷举所有可能的排序，去除重复字符
    backtrack(res, s, visited, track);
    
    return res;
  }

  // 回溯串
  void backtrack(vector<string>& res, string& s, vector<bool>& visited, string& track) {

    // 回溯结束条件
    if (track.size() == s.size()) {
      // 结果集中push当前遍历串
      res.push_back(track);
      return;
    }

    // 每次递归时，从排序后串s的第一个字符开始遍历
    for (int i = 0; i < s.size(); i++) {
      // 第i个位置的字符已被使用过，即当前的track串中存在vis[i]
      if (visited[i])
        continue;
      
      // 当前位置每次填入的字符一定是这个字符所在重复字符集合中从左往右第一个出现的字符
      // 如果 i>0, 当前字符未被访问过，且当前字符和前一个字符相同，跳过
      if (i > 0 && !visited[i-1] && s[i - 1] == s[i])
        continue;

      // 设置第i个位置的字符访问标志
      visited[i] = true;

      // 当前字符push
      track.push_back(s[i]);
      
      // 设置track串下一个位置的字符
      backtrack(res, s, visited, track);
      
      // pop最后一个字符
      track.pop_back();
      
      // 当前遍历过程中访问重置
      visited[i] = false;
    }
  }
};


/***************************************************************************
 * 2. 下一个排列
 * 已知当前一个排列，快速得到字典序中下一个更大的排列
 * 
 * 1）对给定字符串中的字符排序，得到当前字符串的第一个序列
 * 2）计算当前字符串在字典序中下一个更大的排列，直到不存在为止
 * 
 * 优点：
 * 1）所有排列都不可能重复，无需去重
 * 2）无需回溯，不用栈的开销，空间复杂度小
****************************************************************************/
class Solution {
  public:
    vector<string> permutation(string s) {
      vector<string> res;
      
      // 当前字符排序(默认升序)
      sort(s.begin(), s.end());

      do {
        res.push_back(s);
      } while (nextPermutation(s));

      return res;
    }

  // 获取当前字符串在字典序中下一个排序
  bool nextPermutation(string& s) {
    int i = s.size() - 2;

    // i 指向从后往前第一个非递增的位置之前的位置
    while (i >= 0 && s[i] >= s[i + 1]) {
      i--;
    }

    if (i < 0)
      return false;

    int j = s.size() - 1;

    while (j >= 0 && s[i] >= s[j]) {
      j--;
    }

    swap(s[i], s[j]);

    reverse(s.begin() + i + 1, s.end());

    return true;
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