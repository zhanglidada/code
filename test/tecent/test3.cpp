#include <iostream>
#include <vector>
using namespace std;
int calc(long long int value) {
  int res = 0;
  while (value) {
    res += (value % 10);
    value /= 10;
  }
  return res;
}
int func(long long int n) {
  int res;
  int digit;
  int inputval = n;
  while (inputval) {
    inputval /= 10;
    digit++;
  }
  if (digit == 1)  return n;
  int resvalue1 = 0;
  digit --;
  while (digit) {
    resvalue1 *= 10;
    resvalue1 += 9;
    digit --;
  }
  int resvalue2 = n - resvalue1;
  res = calc(resvalue1) + calc(resvalue2);
  return res;
}
int main() {
  int n;
  cin >> n;
  vector<long long int> input;
  while (n) {
    long long int value;
    cin >> value;
    input.push_back(value);
    n--;
  }
  for (int i = 0; i < input.size(); i++) {
    int res = func(input[i]);
    cout << res << " ";
  }
  return 0;
}