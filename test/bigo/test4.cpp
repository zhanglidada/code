#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <algorithm>
using namespace std;
int adds_num;
vector<int> weights;

void genAdvertiseitem(int& first, int& second) {
  sort(weights.begin(), weights.end());
  int sumWeight = 0;
  for (int i = 0; i < weights.size(); i ++) {
    sumWeight += weights[i];
  }
  int n = rand() % sumWeight;
  int i = 0;
  while (n > 0) {
    n -= weights[i];
    if (n < 0)
      first = i;
    i--;
  }
  n = rand() % sumWeight;
  i = 0;
  while (n > 0) {
    n -= weights[i];
    if (n < 0)
      second = i;
    i--;
  }
  while (first == second) {
    n = rand() % sumWeight;
    i = 0;
    while (n > 0) {
      n -= weights[i];
      if (n < 0)
        second = i;
      i--;
    }
  }
}
int main() {
  int first, second;
  int* counter = new int[adds_num];
  for (int i = 0; i < 10000000; i++) {
    genAdvertiseitem(first, second);
    counter[first] ++;
    counter[second] ++;
  }
  for (int i = 0; i < adds_num; i++) {
    cout << "ads no" << i << ": appears. " << counter[i] << endl;
  }
}