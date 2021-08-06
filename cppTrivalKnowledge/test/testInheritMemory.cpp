#include <iostream>
using namespace std;

class Base {
 public:
  // 声明静态成员变量
  static int m_data;
  // 定义静态成员函数
  static void func(int value) {
    m_data = value;
  }
  // 普通的构造函数
  Base(int num) : m_value(num){
    cout << "common constructor: " << endl;
  }
  // 友元函数
  friend ostream& operator<<(ostream& os, Base& b) {
    os << b.m_value;
    return os;
  }
  // 赋值运算符重载
  Base& operator=(Base& b) {
    m_value = b.m_value;
    return *this;
  }
 private:
  int m_value;
};
// 静态成员变量必须在类的外部声明或者定义一次
int Base :: m_data = 0;
class Test : public Base {
 public:
  Test(int value) : Base(value) {
    cout << "son's constructor:" << endl;
  }
};
int main() {
  Test x(123);
  Test y(321);
  /* 可以继承的：
     1.静态成员变量
     2.静态成员函数
     3.友元函数
     4.重载的赋值运算符
  */
  cout << Test::m_data << endl;
  Test::func(999);
  cout << y << endl;
  cout << x << endl;
  y = x;
  cout << y << endl;
}