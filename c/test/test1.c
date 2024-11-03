#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct test_struct test_t;
struct test_struct
{
  //int a;
  //int b;
};

int main()
{
  test_t a;
  int*  b;
  printf("%zu", sizeof(a));
}