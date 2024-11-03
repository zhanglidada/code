#include <stdio.h>

void byteorder() {
  // 结构体中两个变量共享同一块内存
  union
  {
    short value;
    char union_bytes[sizeof(short)];
  } test;  // 创建结构体实例名为test

  test.value = 0x0102;
  if (test.union_bytes[0] == 1 && test.union_bytes[1] == 2)
    printf("big ending");
  else if (test.union_bytes[1] == 1 && test.union_bytes[0] == 2)
    printf("little ending");
  else
    printf("unknown");
}
int main() {  // 程序入口
  
  byteorder();
  
  return 0;
}