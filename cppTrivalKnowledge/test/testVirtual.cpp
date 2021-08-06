#include <iostream>
using namespace std;

class Father {
 public:
  // 父类的虚函数
  virtual void Say() {
    cout << "Say Father hello!" << endl;
  }
  void speak() {
    cout << "speak father hi!" << endl;
  }
};
class Son : public Father {
 public:
  void Say() {
    cout << "Say Son hello!" << endl;
  }
  void speak() {
    cout << "speak son hi!" << endl;
  }
};
int main() {
  Son sn = Son();
  // 向上类型转换
  Father fa = sn;
  fa.speak();  // 调用的是父类对象的成员函数
  /* 
    父类指针指向子类中包含的父类地址部分
    如果没有定义虚函数则只能调用父类函数
  */
  Father *pFather = &sn;
  pFather->Say();  // 调用子类重写的虚函数函数
  pFather->speak();  // 调用父类的函数，因为不是虚函数
  cout << "father size: " << sizeof(fa) << " son size: " << sizeof(sn) << endl;;
} 