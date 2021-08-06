#include <iostream>
#include <vector>
using namespace std;

vector<int> func(vector<int>& arr1, vector<int>& arr2) {
  vector<int> res;
  if (arr1.empty() || arr2.empty())
    return res;
  int i = 0, j = 0;
  while (i < arr1.size() && j < arr2.size()) {
    if (arr1[i] > arr2[j])  i++;
    else if (arr1[i] < arr2[j])  j++;
    else {
      res.push_back(arr1[i]);
      i++;
      j++;
    }
  }
  return res;
}
int main() {
  int n,m;
  cin >> n;
  vector<int> arr1, arr2;
  while (n) {
    int value;
    cin >> value;
    arr1.push_back(value);
    n--;
  }
  cin >> m;
  while (m) {
    int value;
    cin >> value;
    arr2.push_back(value);
    m--;
  }
  vector<int> res = func(arr1, arr2);
  for (auto num : res) {
    cout << num << " ";
  }
}