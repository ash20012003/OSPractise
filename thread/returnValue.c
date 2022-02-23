#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

void* inc(){
  int value = (rand() % 6) + 1;
  int* result = malloc(sizeof(int));
  *result = value;
  return (void*) result;
}

int main(int argc, char* argv[]){
  srand(time(NULL));
  int* res;
  pthread_t t1;
  pthread_create(&t1,NULL,&inc,NULL);
  pthread_join(t1,(void*) &res);
  printf("%d is the Result\n", *res);
  free(res);
  return 0;
}
