#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <pthread.h>
#include <fcntl.h>
#include <time.h>
/*
FIFO FILES/ NAMED PIPE
*/

int main(int argc, char* argv[]) {
  int arr[5];int fd = open("firstfifo",O_RDONLY);
  int i = 0;
  read(fd, arr, sizeof(int) *5);
  // for(i = 0;i<5;i++){
  //   read(fd,&arr[i],sizeof(int));
  //   printf("Received %d\n",arr[i]);
  // }
  close(fd);
}
