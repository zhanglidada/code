#include <iostream>
#include <vector>
#include <set>
using namespace std;

int func(string s) {
  set<char> sets;
  int left = 0, right = 0;
  int maxLen = 0;
  while (right < s.size()) {
    if (sets.find(s[right]) == sets.end()) {
      sets.insert(s[right]);
      maxLen = max(maxLen, right - left + 1);
      right ++;
    } else {
      sets.erase(s[left++]);
    }
  }
  return maxLen;
}
int main() {
  string s;
  cin >> s;
  cout << func(s);
}