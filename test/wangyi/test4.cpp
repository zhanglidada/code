#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
void func(vector<int>& list1) {
  int val1 = 0, val2 = 0;
  stack<int> st1, st2;
  int maxValue = INT32_MIN;
  int start = 0;
  while (start < list1.size() - 2) {
    int len = (list1.size() - start);
    int n = len % 2 == 0 ? list1.size() : list1.size() - 1;
    for (int i = start; i < n;) {
      st1.push(list1[i]);
      val1 += list1[i++];
      st2.push(list1[i]);
      val2 += list1[i++];
    }
    while (val1 != val2) {
      
    }
  }
}
int main() {
  int n;
  cin >> n;
  while (n) {
    int count;
    cin >> count;
    vector<int> input;
    while (count) {
      int value;
      cin >> value;
      input.push_back(value);
    }
    sort(input.begin(), input.end());
  }
  return 0;
}