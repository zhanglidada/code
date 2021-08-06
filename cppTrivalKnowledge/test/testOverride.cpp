#include <iostream>
#include <vector>
using namespace std;

class Animal {
 public:
  // 函数重载(参数不同)
  void func1(int tmp) {
    cout << "I'm animal : " << tmp << endl;
  }
  void func1(char* s) {
    cout << "I'm func1 animal : " << s << endl;
  }

  // 基类的虚函数
  virtual void func2(int tmp) {
    cout << "I'm func2 virtual animal : " << tmp << endl;
  }
  void func3(int tmp) {
    cout << "I'm func3 animal : " << tmp << endl;
  }
  
  static void func() {
    cout << "static fatherFunc" << endl;
  }
};
class Fish : public Animal {
 public:
  // 函数的重定义，参数不同，隐藏父类的方法
  void func1() {
    cout << "I'm func1 fish1" << endl;
  }
  // 重写父类的虚函数
  void func2(int tmp) {
    cout << "I'm func2 fish : " << tmp << endl;
  }
  // 函数的重定义，参数相同，也会隐藏父类的方法
  void func3(int tmp) {
    cout << "I'm func3 fish : " << tmp << endl;
  }
  static void func() {
    cout << "static sonFunc." << endl;
  }
};
int main() {
  Animal an;
  Fish fi;

  fi.func1();
  // 采用强制类型转换，调用被隐藏的父类函数
  dynamic_cast<Animal*>(&fi)->func1(21);
  dynamic_cast<Animal*>(&fi)->func1("fish");
  // 调用子类的方法
  fi.func2(233);  // 因为是虚函数，子类重写父类方法
  dynamic_cast<Animal*>(&fi)->func2(332);  // 强制类型转换之后仍然调用子类重写后的函数

  fi.func3(334);  // 调用子类重定义的函数
  dynamic_cast<Animal*>(&fi)->func3(337);  // 强制类型转换，调用父类被隐藏的函数

  /* 
    可以看出子类不能重定义父类的静态方法
    */
  fi.func();  // 调用子类自己的静态函数
  dynamic_cast<Animal*>(&fi)->func();  // 调用父类的静态函数，因为强制类型转换为父类的指针
  // 定义一个父类指针，指向子类的实例
  Animal* an1 = new Fish();
  an1->func();  // 父类的静态函数并没有被子类的静态函数所隐藏
}