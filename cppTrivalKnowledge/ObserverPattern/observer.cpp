#include <iostream>
#include <list>
#include <memory>
using namespace std;

// 定义observer和subkect的虚基类
class Observer;
class Subject {
 public:
  virtual void Attach(Observer*) = 0;
  virtual void Detach(Observer*) = 0;
  virtual void Notify() = 0;
};
class Observer {
 public:
  // 只有在subject的notify调用的时候，notify中对每个observer进行update
  virtual void Update(int) = 0;
};


class ConcreteObserver1 : public Observer {
 public:
  ConcreteObserver1(Subject* psubject) : m_pSubject(psubject){}
  void Update(int value)
  {
    cout << "ConcreteObserver1 get the update. New State:" << value << endl;
  }

 private:
  Subject* m_pSubject = nullptr;
};

class ConcreteObserver2 : public Observer {
 public:
  ConcreteObserver2(Subject* psubject) : m_pSubject(psubject){}
  void Update(int value)
  {
    cout << "ConcreteObserver2 get the update. New State:" << value << endl;
  }

 private:
  Subject* m_pSubject = nullptr;
};

class ConcreteSubject : public Subject {
 public:
  void Attach(Observer* pPbserver);
  void Detach(Observer* pObserver);
  void Notify();

  void setState(int state) {
    m_state = state;
  }
 private:
  list<Observer*> m_observer_list;
  int m_state = 0;
};
void ConcreteSubject::Attach(Observer* pObserver) {
  m_observer_list.push_back(pObserver);
}
void ConcreteSubject::Detach(Observer *pObserver)
{
  m_observer_list.remove(pObserver);
}
void ConcreteSubject::Notify() {
  list<Observer*>::iterator it = m_observer_list.begin();
  while (it != m_observer_list.end()) {
    (*it)->Update(m_state);
    it++;
  }
}
int main() {
  // create Subject
  ConcreteSubject *pSubject = new ConcreteSubject();
  // create observer
  ConcreteObserver1 *pObserver1 = new ConcreteObserver1(pSubject);
  ConcreteObserver2 *pObserver2 = new ConcreteObserver2(pSubject);

  // create the state
  pSubject->setState(13);

  // register the observer
  pSubject->Attach(pObserver1);
  pSubject->Attach(pObserver2);

  pSubject->Notify();

  pSubject->setState(18);
  pSubject->Notify();

  pSubject->Detach(pObserver1);
  pSubject->Notify();

  delete pSubject;
  delete pObserver1;
  delete pObserver2;
}