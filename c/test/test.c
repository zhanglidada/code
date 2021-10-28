#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct test1 test1_2;
struct test1 {
  int sig[128];
};

// pathname_t是char[128]数组的别名
typedef char pathname_t[128];
pathname_t name;

int main() {
  test1_2 * new_test;
  new_test = malloc(sizeof(test1_2));

  printf("size of member in struct pointer is : %d\n", sizeof(new_test->sig) / sizeof(int));
  printf("size of alias is : %d\n", sizeof(name));

  char* buf = "\"123";
  printf("%d\n", strlen(buf));

  return 0;
}