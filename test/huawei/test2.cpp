#include <iostream>
#include <map>
using namespace std;

int func(int a, int b) {
  if(b == 0)
    return 1;
  int suma = 1;
  int sumb = 1;
  for(int i = 1; i<= a; i++) {
    suma*=i;
  }
  for (int j = 1; j<= b; j++) {
    sumb*= j;
  }
  return suma/sumb;
}
int main() {
  int n;
  cin >> n;
  map<int, int> map_;
  for (int i = 0; i < n; i++) {
    cin >> n;
    if (map_.find(n) == map_.end()) {
      map_[n] = 1;
    } else {
      map_[n] ++;
    }
  }
  int res = 1;
  int size = map_.size();
  cout << size << endl;
  for (int i = 0; i < size - 1; i++) {
    int count = func(map_[i+1], map_[i+1]- map_[i]);
    res*=count;
  }
  cout <<res;
}