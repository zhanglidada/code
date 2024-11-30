#include "../common.h"

// 易变性，不能优化到寄存器上
static volatile int counter = 0;

// 线程执行函数
void* mythread(void* arg)
{
  int i;

  printf("%s: begin.\n", (char*)arg);

  // 获取共享数据并+1
  for (i = 0; i < 1e7; i++)
    counter = counter + 1;

  printf("%s: done.\n", (char*)arg);

  return NULL;
}

int main(int argc, char* argv[])
{
  pthread_t p1, p2;

  printf("main: begin\n");

  pthread_create(&p1, NULL, mythread, "A");
  pthread_create(&p2, NULL, mythread, "B");

  // 使用join后，main线程在执行结束并销毁前以阻塞的方式等待p1和p2线程的结束
  pthread_join(p1, NULL);
  pthread_join(p2, NULL);

  printf("main: done with both (counter = %d)\n", counter);

  return 0;
}