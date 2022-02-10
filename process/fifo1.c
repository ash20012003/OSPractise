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
/*
FIFO FILES/ NAMED PIPE
*/

int main(int argc, char* argv[]) {
  mkfifo("firstfifo",0777); // Here 0777 is the permission code of the fifo file
  printf("Opening...\n");
  int fd = open("firstfifo",O_WRONLY); //This way we can create a file descriptor. Here fd is only in write mode and hence we dont have two values

  //We will find out that once the fifo file is opened, the subsequent steps are not being executed and the terminal lags there. This is because fifo files have to be open from both ends. ie, if we write into the file, another process must read that file and vice versa

  //To do this for eg, run the command "cat firstfifo" in another terminal
  printf("Opened\n");
  int x = 97;
  write(fd,&x,sizeof(x));
  printf("Written\n");
  close(fd);
  printf("Closed\n");
  return 0;
}
