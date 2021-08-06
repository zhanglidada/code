#include "stdio.h"
#include "stdlib.h"
#include <iostream>
using namespace std;

class base {
  public:
    base();
    // 父类定义的虚函数
    virtual void test();
  private:
    char* basePStr;
};

class dumptest : public base {
  public:
    // 继承父类的虚函数
    void test();
  private:
    char* childPStr;
};

base :: base() {
  basePStr = "test_info";
}

void base :: test() {
  cout << basePStr << endl;
}

// 子类实现父类的虚函数
void dumptest :: test() {
  cout << "dumpTest" << endl;
  delete childPStr;
}

int main() {
  dumptest dump;
  // 调用虚方法test并试图试放子类未初始化的指针
  dump.test();
  return 0;
}