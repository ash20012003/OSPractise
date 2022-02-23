#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int mail = 0;
pthread_mutex_t mutex;

void* inc(){
  for(int i = 0; i< 1000000; i++) { //for some very large limit for i as race conditions takes place at those values. Before one thread completes processing, another thread would have accessed the shared memory
    pthread_mutex_lock(&mutex);
    mail++;
    pthread_mutex_unlock(&mutex);
  }
}

int main(int argc, char* argv[]){
  pthread_t t1;
  pthread_t t2;
  pthread_mutex_init(&mutex,NULL);
  pthread_create(&t1,NULL,&inc,NULL);
  pthread_create(&t2,NULL,&inc,NULL);
  pthread_join(t1,NULL);
  pthread_join(t2,NULL);  
  pthread_mutex_destroy(&mutex);
  printf("NO OF MAILS : %d", mail);
  return 0;
}
