#include <stdio.h>
#include <stdlib.h>

int main() {
  char values[3][20] = {
    {0x61, 0xd6, 0xd0, '\0'},
    {0xE4, 0xBA, 0xB8, '\0'},
    {0x63, 0x64, 0x65, '\0'},
  };

  for (int i = 0; i < 3; i++) {
    printf("%s\n", values[i]);
  }
}