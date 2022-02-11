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

int main(int argc, char* argv[]) {
  int pid = fork();
  if(pid==-1) return 1;
  if(pid==0){
    //Child process
    execl("ping","ping","-c","3","google.com",NULL);
  }
  else{
    //Parent process
    wait(NULL);
    printf("Commands executed and now post processing can be done\n");
  }
}
