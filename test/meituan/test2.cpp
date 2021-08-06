#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int func(vector<int> A, vector<int> B, int n, int m) {
  unordered_map<int, int> numsA;
  unordered_map<int, int> numsB;
  int maxnum = 0;
  for (int i = 0; i < n; i++) {
    numsA[A[i]] = numsA.find(A[i]) == numsA.end() ? 1 : numsA[A[i]]++;
    numsB[B[i]] = numsB.find(B[i]) == numsB.end() ? 1 : numsB[B[i]]++;
    maxnum = max(maxnum, numsB[B[i]]);
  }
  int valA = 0, valB = 0;
  for (auto it : numsB) {
    if (it.second == maxnum) {
      valB = it.first;
      break;
    } 
  }
  for (auto it : numsA) {
    if (it.second == maxnum) {
      valA = it.first;
      break;
    }
  }
  if (valA > valB)  return m - valB;
  else return valB - valA;
}
int main() {
  int n,m;
  vector<int> A;
  vector<int> B;
  cin >> n >> m;
  int val;
  for (int i = 0; i < n; i++) {
    cin >> val;
    A.push_back(val); 
  }
  for (int i = 0; i < m; i++) {
    cin >> val;
    B.push_back(val);
  }
  cout << func(A, B, n, m);
}