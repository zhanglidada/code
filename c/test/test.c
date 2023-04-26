#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>


int main()
{
  FILE* fp;
  pid_t pid;
  char  file_buf[1024];
  char  val_buf[1024];
  char  tmp[64];
  
  pid = getpid();
  
  strcpy(file_buf, "ls /proc/");
  sprintf(tmp, "%d", pid);
  printf("pid is : %s\n", tmp);
  strcat(file_buf, tmp);
  strcat(file_buf, "/fd | wc -l");

  // 读取当前进程打开文件数
  fp = popen(file_buf, "r");
  fgets(val_buf, sizeof(val_buf), fp);
  pclose(fp);
  printf("current process opened handle : %s\n", val_buf);

  fp = popen("cat /proc/sys/fs/file-max", "r");
  fgets(val_buf, sizeof(val_buf), fp);
  pclose(fp);
  printf("max file handle : %s\n", val_buf);

  pthread_condattr_t  cattr;

  pthread_condattr_init(&cattr);

  sleep(10000);

  return 0;
}