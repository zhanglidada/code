#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
int func(string& s1, string& s2) {
  vector<pair<char, queue<int>>> nums;
  unordered_map<char, int> visitedChar;
  int count = 0;
  for (int i = 0; i < s1.size(); i++) {
    if (visitedChar.find(s1[i]) != visitedChar.end())
      nums[visitedChar[s1[i]]].second.push(i);
  }
  for (int i = 1; i < s2.size(); i++) {
    if (visitedChar[s2[i]] != 0)
  }
}