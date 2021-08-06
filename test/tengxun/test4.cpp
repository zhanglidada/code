#include <iostream>
#include <vector>
using namespace std;

vector<int> func(vector<int>& inputs) {
  vector<int> res;
  if (inputs.empty())  return res;
  int len = inputs.size();
  int mid = len / 2;
  for (int i = 0; i < len / 2; i++)  res.push_back(inputs[mid]);
  for (int i = len / 2; i < len; i++)  res.push_back(inputs[mid - 1]);
  return res;
}
int main () {
  int n;
  cin >> n;
  vector<int> input;
  while (n) {
    int value;
    cin >> value;
    input.push_back(value);
    n--;
  }
  vector<int> res = func(input);
  for (auto num : res) {
    cout << num << endl;
  }
}