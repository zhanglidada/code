#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char* str1 = "abcdef";
  char str2[50] = "abcdef";
  int i = 0;

  // 一个一个字符输出
  printf("%-10s", str1);
  while (*str1 != '\0') {
    printf("%X ", *str1++);
  }
  printf("\n");

  printf("%-10s", str2);
  for (i = 0; i < 6; i++) {
    printf("%02X ", str2[i]);
  }
  printf("\n");

  printf("%-10s %20X", str2);

  return 0;
}