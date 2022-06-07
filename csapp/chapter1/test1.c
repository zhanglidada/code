#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int a[2];  // 注意，a的size只有2
  double d;
} struct_t;

double fun(int i) {
  // volatile表示该变量为易变类型变量，编译器不要做优化
  volatile struct_t s;  // 函数内部临时变量
  s.d = 3.14;
  s.a[i] = 1073741824;
  return s.d;
}

int main() {
  for (int i = 0; i < 9; i++) {
    printf("%f\n", fun(i));
  }

  return 0;
} 