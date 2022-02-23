#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

void *printHello(){
  printf("Hello all\n");
  sleep(3);
  printf("Thread ended");
}

int main(int argc, char* argv[]){
  pthread_t t1;
  pthread_t t2;
  pthread_create(&t1,NULL,&printHello,NULL);
  pthread_create(&t2,NULL,&printHello,NULL);
  pthread_join(t1,NULL);
  pthread_join(t2,NULL);  
  return 0;
}
