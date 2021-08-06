#include <iostream>
#include <vector>
using namespace std;

void reverse(string& s) {
  int len = s.size();
  for (int i = 0, j = len - 1; i < j;) {
    swap(s[i++], s[j--]);
  }
  int start = 0, end = 0;
  for (int i = 0; i < len; i++) {
    if (s[i] != ' ') {
      start = i;
      while (i < len) {
        i++;
        if(s[i] == ' ') {
          end = i - 1;
          for (int j = start, k = end; j < k;) {
            swap(s[j++], s[k--]);
          }
        }
      }
    }
  }
}