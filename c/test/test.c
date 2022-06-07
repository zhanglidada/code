#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// str从起始字符开始有多少字符和group中的字符匹配，group是一个字符集合
size_t strspn(const char* str, const char* group)
{
  const char* p = NULL;
  const char* g = NULL;
  size_t count = 0;  // 匹配字符个数

  for (p = str; *p != '\0'; p++)
  {
    for (g = group; *g != '\0'; g++)
    {
      if (*p == *g)
      {
        count ++;
        break;
      }
    }

    // str中当前字符，匹配到group中最后一个字符均没有匹配，直接返回
    if (*g == '\0')
    {
      return count;
    }
  }
  memccpy()
}

int main()
{
  
}
