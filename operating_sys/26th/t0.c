#include "../common.h"

// 线程执行函数
void* mythread(void* arg)
{
  int randomNumber;

  srand(time(NULL));
  
  randomNumber = (int)rand();

  while(randomNumber--);

  printf("%s\n", (char*)arg);

  return NULL;
}

int main(int argc, char* argv[])
{
  int rc;
  pthread_t p1, p2;

  printf("main: begin\n");

  rc = pthread_create(&p1, NULL, mythread, "A");
  assert(rc == 0);

  rc = pthread_create(&p2, NULL, mythread, "B");
  assert(rc == 0);

  // 使用join后，main线程在执行结束并销毁前以阻塞的方式等待p1和p2线程的结束
  rc = pthread_join(p1, NULL);
  assert(rc == 0);

  rc = pthread_join(p2, NULL);
  assert(rc == 0);

  printf("main end.\n");

  return 0;
}