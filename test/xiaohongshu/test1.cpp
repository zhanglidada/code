#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <sstream>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
vector < string > splitMsg(vector<string>& input) {
  vector<string> tmp;
  int flag = 1;
  for (auto str : input) {
    while (str != "\n") {
      int pos = str.find('.');
      string s = str.substr(0, pos);
      tmp.push_back(str + s);
      str = str.substr(pos + 1);
    }
  }
  vector<string> tmp1;
  vector<string> ans;
  for (int i = 0; i < tmp.size(); i++) {
    tmp1.clear();
    int size = tmp[i].size();
    tmp1.push_back(tmp[i]);
    while (size < 1024) {
      i++;
      size += tmp[i].size();
      tmp1.push_back(tmp[i]);
    }
    i--;
    tmp1.pop_back();
    string strtmp;
    strtmp.append("msg" + to_string(flag ++) + ":");
    for (auto str : tmp1) {
      strtmp.append(str);
    }
    ans.push_back(strtmp);
  }
  return ans;
}
/******************************结束写代码******************************/


int main() {
  vector < string > input;
  string str;
  while (cin >> str) {
    input.push_back(str);
  }
  vector<string> res = splitMsg(input);
  for(int res_i=0; res_i < res.size(); res_i++) {
    cout << res[res_i] << endl;;
  }
    
    return 0;

}
