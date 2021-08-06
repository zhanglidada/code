#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> func(vector<string>& password) {
  vector<int> res;
  for (auto pass : password) {
    bool numf = false;
    bool charSf = false;
    bool charBf = false;
    bool singf = false;
    if (pass.size() < 8 || pass.size() > 120) {
      res.push_back(1);
      continue;
    }
    for (auto c : pass) {
      if (c <= '9' && c >= '0') numf = true;
      else if (c <= 'z' && c >= 'a') charSf = true;
      else if (c <= 'Z' && c >= 'A')  charBf = true;
      else if (c >= 33 && c <= 126) singf = true;
    }
    if (numf && charSf && charBf && singf) {
      res.push_back(0);
      continue;
    }
    res.push_back(2);
  }
  return res;
}
int main() {
  string str;
  vector<string> password;
  while (getline(cin, str)) {
    if (str.empty())  break;
    password.push_back(str);
  }
  vector<int> res = func(password);
  for (auto num : res)
    cout << num << endl;
  return 0;
}