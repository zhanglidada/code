#include <iostream>
using namespace std;

class complex{
 public:
  complex(double real = 0.0, double imag = 0.0) : m_real(real), m_imag(imag){ }
  /*
    重载最基本的+，-，*，/
    返回的是新创建的对象的拷贝
   */
  friend complex operator+(const complex &A, const complex &B);
  friend complex operator-(const complex &A, const complex &B);
  friend complex operator*(const complex &A, const complex &B);
  friend complex operator/(const complex &A, const complex &B);
  /*
    重载+=，-=，*=，/=
    返回的是第一个对象本身
   */
  friend complex& operator+=(complex& A, const complex& B);
  friend complex& operator-=(complex& A, const complex& B);
  friend complex& operator*=(complex& A, const complex& B);
  friend complex& operator/=(complex& A, const complex& B);
  /*
    重载输入输出运算符
   */
  friend istream& operator>>(istream &in, complex &A);
  friend ostream& operator<<(ostream &out, const complex &A);
 private:
  double m_real;  // 复数的实部
  double m_imag;  // 复数的虚部
};
complex operator+(const complex &A, const complex &B) {
  complex C;
  C.m_real = A.m_real + B.m_real;
  C.m_imag = A.m_imag + B.m_imag;
  return C;
}
complex operator-(const complex &A, const complex &B) {
  complex C;
  C.m_real = A.m_real - B.m_real;
  C.m_imag = A.m_imag - B.m_imag;
  return C;
}
complex operator*(const complex &A, const complex &B) {
  complex C;
  C.m_real = A.m_real * B.m_real - A.m_imag * B.m_imag;
  C.m_imag = A.m_imag * B.m_real + A.m_real * B.m_imag;
  return C;
}
complex operator/(const complex &A, const complex &B) {
  complex C;
  double square = A.m_real * A.m_real + A.m_imag * A.m_imag;
  C.m_real = (A.m_real * B.m_real + A.m_imag * B.m_imag) / square;
  C.m_imag = (A.m_imag * B.m_real - A.m_real * B.m_imag) / square;
  return C;
}
complex& operator+=(complex &A, const complex &B){
  // A.m_real = A.m_real + B.m_real;
  // A.m_imag = A.m_imag + B.m_imag;
  A.m_real += B.m_real;
  A.m_imag += B.m_imag;
  return A;
}
istream& operator>>(istream &in, complex &A) {
  in >> A.m_real >> A.m_imag;
  return in;  // 为了可以连续输入
}
ostream& operator<<(ostream &out, const complex &A) {
  out << A.m_real << " + " << A.m_imag << " i " << endl;
  return out;
}
int main() {
  complex c1, c2, c3;
  cin >> c1 >> c2;

  c3 = c1 + c2;
  cout << "c1 + c2 = " << c3 << endl;
  c3 = c1 - c2;
  cout << "c1 - c2 = " << c3 << endl;
  c3 = c1 * c2;
  cout << "c1 * c2 = " << c3 << endl;
  c3 = c1 / c2;
  cout << "c1 / c2 = " << c3 << endl;
  
  c1 += c2;
  cout << "c1 += c2, c1 is : " << c1 << endl;

  return 0;
}