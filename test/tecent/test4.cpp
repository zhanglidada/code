#include <iostream>
#include <vector>
using namespace std;

int func(vector<int>& inputs) {
  int counts;
  for (int i = 0; i < inputs.size(); i++) {
    inputs[i] --;
  }
  counts++;
  int start, end;
  int i = 0;
  while (i < inputs.size()) {
    if (inputs[i] > 0)
      start = i++;
    while (i < inputs.size() && inputs[i++] > 0) ;
    end = i;
    if (end - start + 1 > 1)
      counts++;
  }
}
int main() {
  int n;
  cin >> n;
  vector<int> inputs;
  while (n) {
    int value;
    cin >> value;
    inputs.push_back(value);
    n--;
  }
  return 0;
}