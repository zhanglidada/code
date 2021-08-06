#include <stdio.h>
#include <stdlib.h>

void dumpCrash() {
  char* ptr = "test1";
  // 因为ptr为常量指针，而常量保存在常量区，所以试放肯定会崩溃
  free(ptr);
}

int main() {
  dumpCrash();
  return 0;
}