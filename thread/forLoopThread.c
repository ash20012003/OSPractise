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
  pthread_t thread[10];
  pthread_mutex_init(&mutex,NULL);
  for(int i = 0; i<10; i++){
    pthread_create(thread+i, NULL, &inc, NULL);
    printf("Thread %d has started\n",i);
  }
  for(int i = 0 ;i<10; i++){
    pthread_join(thread[i], NULL);
    printf("Thread %d has finished execution\n", i);
  }
  //We dont create and join in the same for loop, then the threads will get created and complete their execution one after the other which is against the very reaon of using threads in the first place.
  pthread_mutex_destroy(&mutex);
  printf("NO OF MAILS : %d", mail);
  return 0;
}
