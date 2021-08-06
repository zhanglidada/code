#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int GetFragment(string str) {
      // write code here
    vector<int> lens;
    for (int i = 1; i <= str.size();) {
      int size = 1;
      while (i < str.size() && str[i] == str[i - 1]) {
        size++;
        i++;
      }
      lens.push_back(size);
      i++;
    }
    int sum = 0;
    for (auto num : lens) {
      sum += num;
    }
    return sum / lens.size();
  }
};