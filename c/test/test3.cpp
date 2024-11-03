#include<iostream>

class A {
  private:
    int value;
  public:

    A(int n) 
    {
      value = n;
    }

    A(A &other)
    {
      value = other.value;
    }

    void print()
    {
      std::cout << value << std::endl;
    }
};


int main(int argc, char* argv[])
{
  A a(10);
  A b = a;
  b.print();

  return 0;
}