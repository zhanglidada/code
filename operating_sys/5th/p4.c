#include "../common.h"

// 
int main(int argc, char* argv[])
{
  int rc;
  int wc;

  // 创建子进程
  rc = fork();

  if (rc < 0)  // fork failed， exists
  {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)  // child: redirect standard output to a file
  {
    char* myargs[3];

    close(STDOUT_FILENO);
    open("./p4.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);

    myargs[0] = strdup("wc");     // program: "wc" (word count)
    myargs[1] = strdup("p4.c");   // argument: file to count
    myargs[2] = NULL;             // marks end of array

    // now exec wc
    execvp(myargs[0], myargs);  // runs word count

    printf("this shouldn't print out");
  }
  else  // parent goes down this path (main)
  {
    wc = wait(NULL);  // 父进程延迟自己，直到子进程执行结束
  }
  
  return 0;
}