#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

void calcMinrows(vector<int>& frame, vector<int>& brick) {
  int n = frame.size(), m = brick.size();
  int fmi = INT32_MAX, bma = INT32_MIN;
  vector<int> brickre(frame.size(), 0);
  for (int i = 0; i < n; i++) {
    fmi = min(fmi, frame[i]);
  }
  for (int j = 0; j < m; j++) {
    bma = max(bma, brick[j]);
  }
  if (fmi > bma && (m-1-bma) <= (n-1-fmi)) {

  }
  if (fmi < bma && (bma) >= )
}
int main() {
  string frame, brick;
  cin >> frame;
  cin >> brick;
  vector<int> bottom, input;
  for (int i = 0; i< frame.size(); i++) {
    bottom.push_back(frame[i] - 48);
  }
  for (int i = 0; i< brick.size(); i++) {
    input.push_back(brick[i] - 48);
  }
  calcMinrows(bottom, input);
}