#include <iostream>
#include <vector>
using namespace std;
int func1(int a, int b) {
  int res = 0;
  int flag = 1;
  for (int i = 0; i < 32; i++) {
    if (((a >> i) & 1) == 1) {
      res ^= (1 << i);
    }
    else if (((b >> i) & 1) == 1) {
      res ^= (1 << i);
    }
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  vector<int> input;
  int num;
  for (int i = 0; i < n; i++) {
    cin >> num;
    input.push_back(num); 
  }
  int sum = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      sum += func1(input[i], input[j]);
    }
  }
  for (int k = 0; k < n; k++) {
    sum += input[k];
  }
  cout << sum;
}