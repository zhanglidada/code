#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int numWays(int n) {
    int arr[3] = {1, 2, 0};
    if (n == 0)
      return 1;
    for (int i = 3; i <= n; i++) {
      arr[2] = (arr[0] + arr[1]) % (int)(1e9 + 7);
      arr[0] = arr[1];
      arr[1] = arr[2];
    }
    return arr[2];
  }
};
int main() {
  return 0;
}