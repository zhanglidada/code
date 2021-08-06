#include <iostream>
#include <iostream>
using namespace std;

class Solution {
 public:
  // 这个方法太厉害了
  int fib(int n) {
    int arr[2] = {0, 1};
    for (int i = 2; i <= n; i++) {
      arr[i & 1] = (arr[0] + arr[1]) % (int)(1e9 + 7);
    }
    return arr[n & 1];
  }
};
int main() {
  Solution ss;
  cout << ss.fib(45);
  return 0;
}