#include <iostream>
#include <vector>
using namespace std;

long long int func(long long int n) {
  if (n < 2)
    return 0;
  if (n == 2 || n == 3)
    return 1;
  return n / 2;
}
int main() {
  long long int n;
  cin >> n;
  long long int ans = 0;
  while(n) {
    long long int number;
    cin >> number;
    ans += func(number);
    n--;
  }
  cout << ans;
}