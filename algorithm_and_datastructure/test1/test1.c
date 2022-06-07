#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>

int main() {
  double  integer = 0.0;  // 整数部分
  double  fp_num = 0.0;  // 小数部分
  bool    f;
  double c = -5.5 / -2.0;
  f = 0.0 > -0.0;

  fp_num = modf(-5.5, &integer);
  printf("integer_num: %f fp_num: %f\n", integer, fp_num);
  printf("%f\n", c);

  printf("%d\n", f);

  return 0;
}