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
  // 根据鞋子类型创建对应的鞋子对象
  Shoes* Create_shoes(SHOES_TYPE type) {
    Shoes * shoes;
    switch (type) {
      case NIKE:
        shoes =  new NikeShoes();
        break;
      case LINING:
        shoes =  new LiNingShoes();
        break;
      case ADIDAS:
        shoes =  new AdidasShoes();
    default:
      shoes = nullptr;
      break;
    }
    return shoes;
  }
};
int main() {
  // 构造工厂对象
  Shoes_Factory shoesFactory;
  
  // 从鞋工厂生产NIKE鞋
  Shoes* NikeShoes = shoesFactory.Create_shoes(NIKE);
  if (NikeShoes != nullptr) {
    NikeShoes->Show();
    // 释放资源
    delete NikeShoes;
    NikeShoes = nullptr;
  }
  return 0;
}