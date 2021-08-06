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
class Clothe {
 public:
  virtual ~Clothe() {};
  virtual void Show()  = 0;
};

// nike鞋子
class NikeShoes : public Shoes {
 public:
  void Show() {
    cout << "我是耐克球鞋Just do it" << std::endl;
  }
};
// 耐克衣服
class NiKeClothe : public Clothe {
 public:
  void Show() {
    std::cout << "我是耐克衣服hhhhh" << std::endl;
  }
};


// Factory为抽象工厂，提供了创建鞋子CreateShoes()和衣服产品CreateClothe()对象的接口。
class Factory {
 public:
  virtual Shoes* CreateShoes() = 0;
  virtual Clothe* CreateClothe() = 0;
  virtual ~Factory() {};
};
// NiKeProducer为具体工厂，实现了创建耐克鞋子和耐克衣服的方式。
class NikeProducer : public Factory{
 public:
  Shoes *CreateShoes() {
    return new NikeShoes();
  }

  Clothe *CreateClothe() {
    return new NiKeClothe();
  }
};

int main() {
  // ================ 生产耐克流程 ==================== //
  // 鞋厂开设耐克生产线
  Factory* NikeProduce = new NikeProducer();

  // 耐克生产线产出球鞋
  Shoes* Nikeshoes = NikeProduce->CreateShoes();
  // 耐克生产线产出衣服
  Clothe* NikeClothe = NikeProduce->CreateClothe();

  NikeClothe->Show();
  Nikeshoes->Show();

  // 释放资源
  delete Nikeshoes;
  delete NikeClothe;
  delete NikeProduce;
  return 0;
}