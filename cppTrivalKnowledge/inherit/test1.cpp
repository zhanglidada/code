#include <iostream>
#include <vector>
using namespace std;
class Person {
 public:
  // 普通的构造函数,有默认的值
  Person (const char* name = "zl") : _name(name){
    cout << "Person()" << endl;
  }
  // 拷贝构造函数
  Person(const Person& p) : _name(p._name){
    cout << "Person(const Person&)" << endl;
  }
  Person& operator=(const Person& p) {
    cout << "Person operator=(const Person& p)" << endl;
    // 防止自赋值
    if (this != &p) {
      _name = p._name;
    }
    return *this;
  }
  // 普通的析构函数
  ~Person() {
    cout << "~Person()" << endl;
  }
 private:
  string _name;
};
class Student : public Person {
 public:
  // 子类的构造函数：由于父类没有默认的构造函数，所以子类需要在初始化列表中调用父类的构造函数
  // 先父后子
  Student(const char* name, int num) : Person(name) , _num(num){
    cout << "student()" << endl;
  }
  /* 拷贝构造
     在构造函数的初始化列表中，父类会切下子类中属于自己的部分进行拷贝构造
  */
  Student(const Student& st) : Person(st), _num(st._num){
    cout << "student(const Studend&)" << endl;
  }
  // 赋值运算符重载
  Student& operator=(const Student& st) {
    cout << "Student operator=(const Student& p)" << endl;
    // 防止自赋值
    if (this != &st) {
      // 显示调用父类的复制运算符
      Person :: operator=(st);
      _num = st._num;
    }
    return *this;
  }
  // 析构函数，先子后父
  ~Student() {
    cout << "~Student()" << endl;
    // 随后会调用父类的析构函数并输出
  }
 private:
  // 学号
  int _num = 0;
};

int main() {
  Student s1("jack", 12);
  // 拷贝构造
  Student s2(s1);
  Student s3("Rose", 18);
  
  // 复制运算
  s1 = s3;
}