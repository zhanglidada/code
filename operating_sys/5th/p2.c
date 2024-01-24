#include "../common.h"

// 相对于p1增加了wait系统调用，
int main(int argc, char* argv[])
{
  int rc;
  int wc;

  // 先输出当前进程的pid
  printf("hello world (pid: %d)\n", (int)getpid());

  // 创建子进程
  rc = fork();

  if (rc < 0)  // fork failed， exists
  {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)  // child (new process)
  {
    // 子进程直接从上面的fork系统调用返回（子进程只获取了fork返回值）
    printf("hello, i am child (pid: %d)\n", (int)getpid());
  }
  else  // parent goes down this path (main)
  {
    wc = wait(NULL);  // 父进程延迟自己，直到子进程执行结束
    printf("hello, i am parent of %d (wc: %d) (pid: %d)\n", rc, wc, (int)getpid());
  }
  
  return 0;
}