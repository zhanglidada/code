#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main() {
  int n,m,k;
  cin >> n >> m >> k;
  vector<int> value;
  vector<int> distance;
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a>> b;
    value.push_back(b);
    distance.push_back(a);
  }
  unordered_set<int> exists;
  for (int i = 0 ;i < n; i++) {
    exists.insert(distance[i]);
  }

  vector<int> dp(n + 1, 0);
  dp[0] = distance[0] == 0 ? value[0] : 0;
  vector<int> visit;
  for (int i = 1; i <= n; i++) {
    if (dp[i - 1] > 0) {

    } else {
      dp[i] = dp[]
    }
  }
  cout << dp[size];
}