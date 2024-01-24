#include "../common.h"

volatile int counter = 0;  // 表示变量随时可能发生变化，禁止编译器优化

int loops;  // 全局变量

void* worker(void* arg)
{
  int i;

  for (i = 0; i < loops; i++)
  {
    counter ++;
  }

  return NULL;
}

int main(int argc, char* argv[])
{
  pthread_t p1, p2;

  if (argc != 2)
  {
    fprintf(stderr, "Usage: threads <value>\n");
    exit(1);
  }

  loops = atoi(argv[1]);
  
  
  printf("Initial value: %d\n", counter);

  // 创建p1， p2两个线程,并开始执行
  pthread_create(&p1, NULL, worker, NULL);
  pthread_create(&p2, NULL, worker, NULL);

  pthread_join(p1, NULL);
  pthread_join(p2, NULL);

  printf("Final value : %d\n", counter);

  return 0;
}