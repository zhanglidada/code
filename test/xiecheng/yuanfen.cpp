#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <string>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
vector<string> split(string str) {
  vector<string> res;
  //cout << "test2" << endl;
  str = str.substr(str.find_first_not_of(' '), str.find_last_not_of(' ') - str.find_first_not_of(' ') + 1);
  int len = str.size();
  int start = 0;
  while (true) {
    string strtmp = str.substr(0, str.find_first_of(' '));
    // cout << strtmp << endl;
    res.push_back(strtmp);
    str = str.substr(strtmp.size());
    if (str.find_first_not_of(' ') == -1)  break;
    str = str.substr(str.find_first_not_of(' '));
  }
  return res;
}
// 比较一个单词
int getVal(string str1, string str2) {
  int len = min(str1.length(), str2.length());
  int ans = 0;
  int maxSimlar = 0;
  for (maxSimlar = 0; maxSimlar < len; maxSimlar++) {
    if (str1[maxSimlar] != str2[maxSimlar])  break;
  }
  for (int i = maxSimlar; i < str1.size(); i++) {
    ans += (str1[i] - 'A') + 65;
  }
  for (int i = maxSimlar; i < str2.size(); i++) {
    ans += (str2[i] - 'A') + 65;
  }
  return ans;
}
// 比较名字
int getnameVal(string name1, string name2) {
  int ans = 0;
  vector<string> name1str = split(name1);
  vector<string> name2str = split(name2);
  int len = min(name1str.size(), name2str.size());
  for (int i = 0; i < len; i++) {
    ans += getVal(name1str[i], name2str[i]);
  }
  return ans;
}
int calcSimilarity(vector<string> name1, vector<string> name2) {
  int res = 0;
  int len = name1.size();
  vector<string> name1Split;
  vector<string> name2Split;
  for (int i = 0; i < len; i++) {
    res = getnameVal(name1[i], name2[i]);
  }
  return res;
}

/******************************结束写代码******************************/


int main() {
    int res;
    int _name1_size = 0;
    cin >> _name1_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _name1;
    string _name1_item;
    for(int _name1_i = 0; _name1_i < _name1_size; _name1_i++) {
        getline(cin, _name1_item);
        _name1.push_back(_name1_item);
    }
    int _name2_size = 0;
    cin >> _name2_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _name2;
    string _name2_item;
    for(int _name2_i = 0; _name2_i < _name2_size; _name2_i++) {
        getline(cin, _name2_item);
        _name2.push_back(_name2_item);
    }
    // cout << "test1" << endl;
    res = calcSimilarity(_name1, _name2);
    cout << res << endl;
    
    return res;

}
