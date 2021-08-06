#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool patternMatching(string pattern, string value) {
    int ca = 0, cb = 0;
    // 统计ca和cb的个数
    for (char ch : pattern) {
      if (ch == 'a')
        ca++;
      else
        cb++;
    }
    // 如果ca < cb,交换a和b,保证a为pattern中出现多的字符
    if (ca < cb) {
      swap(ca, cb);
      for (char& ch : pattern)
        ch = (ch == 'a') ? 'b' : 'a';
    }
    // value为空，若只有a，则true，因为a可以为""
    if (value.empty()) {
      return cb == 0;
    }
    // 此时value不为空，若pattern为空则false
    if (pattern.empty())
      return false;
    int valueSize = value.size();
    for (int lena = 0; lena * ca <= valueSize; lena ++) {
      int rest = valueSize - lena * ca;
      if ((cb == 0 && rest == 0) || (cb != 0 && rest % cb == 0)) {
        int lenb = (cb == 0) ? 0 : rest / cb;
        // 定位当前搜索到的位置
        int pos = 0;
        bool correct = true;
        string value_a, value_b;
        for (char ch : pattern) {
          if (ch == 'a') {
            string sub = value.substr(pos, lena);
            // 第一次进入a
            if (!value_a.size()) {
              value_a = move(sub);
            } else if (value_a != sub) {
              // 此次循环的lena不是正确的长度
              correct = false;
              break;
            }
            pos += lena;
          } else {
            string sub = value.substr(pos, lenb);
            if (!value_b.size()) {
              value_b = move(sub);
            } else if (value_b != sub) {
              correct = false;
              break;
            }
            pos += lenb;
          }
        }
        if (correct && value_a != value_b)
          return true;
      }
    }
    // 当所有的lena都不符合的时候
    return false;
  }
};
int main() {
  return 0;
}