#include <iostream>
#include <vector>
using namespace std;

class Person {
 public:
  Person(int age, string name) : age_(age) , name_(name) {}
  ~Person() {}
  int getAge() const{
    count_++;
    return age_;
  }
  int getAgeCallingTimes() const{
    return count_;
  }
 private:
  int age_;
  string name_;
  mutable int count_ = 0;  // 表示此变量可以多次调用
};
int main() {
  Person jack(12, "jack");
  for (int i = 0; i < 10; i++) {
    jack.getAge();
  }
  cout << "Calling Times : " << jack.getAgeCallingTimes();
}