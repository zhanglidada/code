#include <iostream>
#include <vector>
using namespace std;

// 抽象父类
class Shoes {
 public:
  // 声明一个虚析构函数
  virtual ~Shoes() {};
  virtual void Show() = 0;  // 此时show在子类中即使没有具体实现也不会报错
};
class NikeShoes : public Shoes {
 public:
  void Show() {
    cout << "我是耐克球鞋，我的广告语：Just do it" << std::endl;
  }
};
// 阿迪达斯鞋子
class AdidasShoes : public Shoes {
 public:
  void Show() {
    cout << "我是阿迪达斯球鞋，我的广告语:Impossible is nothing" << std::endl;
  }
};
// 李宁鞋子
class LiNingShoes : public Shoes {
 public:
  void Show() {
    cout << "我是李宁球鞋，我的广告语：Everything is possible" << std::endl;
  }
};
// 枚举类型
enum SHOES_TYPE {
  NIKE,
  LINING,
  ADIDAS
};

// shoes_factory为工厂类，类里实现根据鞋子类型创建对应鞋子产品对象的CreateShoes函数
class Shoes_Factory {
 public:
  virtual Shoes* Create_Shoes() = 0;
  virtual ~Shoes_Factory() {};  // 虚析构函数用于删除子类中的指针
};

class NiKeProducer : public Shoes_Factory {
 public:
  Shoes* Create_Shoes() {
    return new NikeShoes();
  }
};
class LiNingProducer : public Shoes_Factory {
 public:
  Shoes* Create_Shoes() {
    return new LiNingShoes();
  }
};
class AdidasProducer : public Shoes_Factory {
 public:
  Shoes* Create_Shoes() {
    return new AdidasShoes();
  }
};
int main() {
  Shoes_Factory* NikeProdue = new NiKeProducer();
  Shoes* NikeShoes = NikeProdue->Create_Shoes();
  NikeShoes->Show();

  // 释放内存,先删除子类的实例
  delete NikeShoes;
  delete NikeProdue;
  return 0;
}