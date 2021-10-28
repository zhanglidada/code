#include <stdio.h>
#include <stdlib.h>

int main() {
  char* buf;
  buf = malloc(sizeof(char) * 20);
  buf = "filename1 filename2";
  char filename[20];
  sscanf(buf, "%s %s", filename, filename);
  printf("%s", filename);
  return 0;
}