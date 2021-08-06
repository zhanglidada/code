#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
// 采用排序的方式，超时
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size())
      return false;
    sort(s1.begin(), s1.end());
    string subStr2;
    for (int i = 0; i <= s2.size() - s1.size(); i++) {
      subStr2 = s2.substr(i, s1.size());
      sort(subStr2.begin(), subStr2.end());
      if (s1 == subStr2)
        return true;
    }
    return false;
  }
};  */

/*
// 和上面的方式类似，但是使用hash表存储s1中每个字符，并计算s1中每个字符存在的频率
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size())
      return false;
    for (int i = 0; i < s1.size(); i++) {
      charFrequency[s1.at(i)] ++;
    }
    for (int i = 0; i <= s2.size() - s1.size(); i++) {
      string substr2 = s2.substr(i, s1.size());
      if(strEqual(substr2, charFrequency))
        return true;
    }
    return false;
  }
  // 对hashmap采用传递值方式，不会对全局变量进行修改
  bool strEqual(string& str, unordered_map<char, int> charFrequency) {
    for (int i = 0; i < str.size(); i++) {
      if (charFrequency[str.at(i)] == 0 || charFrequency.find(str.at(i)) == charFrequency.end())
        return false;
      else {
        charFrequency[str.at(i)] --;
      }
    }
    return true;
  }
  unordered_map<char, int> charFrequency;
};  */

/*
// 使用数组代替hashmap
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size())
      return false;
    auto slamp1 = new int[26];
    for (int i = 0; i < s1.size(); i++)
      slamp1[s1.at(i) - 'a'] ++;
    for (int i = 0; i <= s2.size() - s1.size(); i++) {
      auto slamp2 = new int[26];
      // string substr2 = s2.substr(i, s1.size());
      for (int j = i; j < i + s1.size(); j++)
        slamp2[s2.at(j) - 'a'] ++;
      if (matchStr(slamp1, slamp2))
        return true;
    }
    return false;
  }
  bool matchStr(int slamp1[26], int slamp2[26]) {
    for (int i = 0; i < 26; i ++)
      if (slamp1[i] != slamp2[i])
        return false;
    return true;
  }
};  */

/*
// 采用滑动窗口的方式
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size())
      return false;
    auto slamp1 = new int[26];
    auto slamp2 = new int[26];
    for (int i = 0; i < s1.size(); i++) {
      slamp1[s1.at(i) - 'a'] ++;
      slamp2[s2.at(i) - 'a'] ++;
    }
    for (int i = 0; i < s2.size() - s1.size(); i++) {
      if (matchStr(slamp1, slamp2))
        return true;
      // 进行滑动的处理，前一个开始的位置处字符减一，下一个结束处字符加一
      slamp2[s2.at(i) - 'a'] --;
      slamp2[s2.at(i + s1.size()) - 'a'] ++;
    }
    // 最后一次还需要比较
    return matchStr(slamp1, slamp2);
  }
  bool matchStr(int slamp1[26], int slamp2[26]) {
    for (int i = 0; i < 26; i ++)
      if (slamp1[i] != slamp2[i])
        return false;
    return true;
  }
};  */

// 滑动窗口改进
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> mp;
    for (auto &c: s1) mp[c]++;  // 记录 出现次数的差值

    int left = 0, right = 0;
    while (right < s2.size()){
      char c = s2[right++];  // 先获得r，再将r+1
      mp[c]--;
      while (left < right && mp[c] < 0){  // 此时已经不能满足匹配条件,窗口左移
        mp[s2[left++]] ++;
      }
      if (right - left == s1.size()) return true;
    }
    return false;
  }
};
int main() {
  Solution ss;
  if (ss.checkInclusion("adc", "dcda"))
    cout << "true";
  else
    cout << "false";
  return 0;
}