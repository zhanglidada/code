#include <stdio.h>
#include <stdlib.h>

int main() {
  int i = 0, j = 0;

  char values[2][20] = {
    {0x61, 0x62, 0x63, '\0'},
    {0x60, 0x61, 0x61, 0x63, '\0'}
  };

  for (i = 0; i < 2; i++) {
    printf("%s", values[i]);
  }

  return 0;
}