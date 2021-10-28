#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <netinet/in.h>

int main() {
  struct sockaddr_storage* server_addr;
  struct sockaddr_storage* client_addr;

  /* 
    sockaddr_storage和sockaddr均为通用socket地址
    sockaddr_in sockaddr_in6均为专用socket地址
   */
  ((struct sockaddr_in*)server_addr)->sin_addr;

  return 0;
}