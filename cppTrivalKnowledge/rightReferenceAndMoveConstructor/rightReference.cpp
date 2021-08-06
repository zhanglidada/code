#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> doubleValues(const vector<int>& v) {
  vector<int> new_Values(v.size());
  for (auto itr = new_Values.begin(), end_itr = new_Values.end(); itr != end_itr; itr++) {
    new_Values.push_back(*itr * 2);
  }
  return new_Values;
}

int x = 9;
// 返回一个引用
int& getval() {
  return x;
}
int get() {
  return x;
}
class Solution {

};
int main() {
  vector<int> vec;
  for (int i = 0; i < 100; i++) {
    vec.push_back(i);
  }
  /* 此处在赋值的过程中其实将doubleValues返回的vector<int>复制一份放入新的内存空间，
     然后改变v的地址，让v指向这篇内存空间。总的来说，我们刚才新建的那个vector又被复制了一遍。
     但是由于需要返回的vector是在函数内部创建，所以只能返回一个vector的复制而不能返回一个引用；
     即doubleValues在定义的时候如果函数返回值是引用则会出错。
   */
  // vector<int> v = doubleValues(vec);
  // getval() = 4;
  // cout << x << endl;
  int&& b = 7;
  b = 9;
  cout << "right reference is: " << b  << endl;
  queue<int> list;
  
  return 0;
}