#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutexFuel;
pthread_cond_t condFuel;

int fuel = 0;

void* fuel_car(void* arg){
  for(int i = 0; i< 5; i++){
  pthread_mutex_lock(&mutexFuel);
  fuel+=15;
  printf("Fuel filled ... %d\n", fuel);
  pthread_cond_signal(&condFuel);
  pthread_mutex_unlock(&mutexFuel);
  sleep(1);
  }
}

void* car(void* arg){
  pthread_mutex_lock(&mutexFuel);
  while(fuel < 40){
    printf("Not filled ... waiting\n");
    pthread_cond_wait(&condFuel, &mutexFuel);
  }
  fuel-=40;
  printf("Got fuel !!\n");
  printf("Fuel left = %d\n",fuel);
  pthread_mutex_unlock(&mutexFuel);
}

int main(int argc, char* argv[]) {
    pthread_t th[2];
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_cond_init(&condFuel, NULL);
    int i;
    for (i = 0; i < 2; i++) {
      if(i==1){
        pthread_create(&th[i], NULL, &fuel_car, NULL);
      }
      else pthread_create(&th[i], NULL, &car, NULL);
    }
    for (i = 0; i < 2; i++) {
         if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    pthread_mutex_destroy(&mutexFuel);
    pthread_cond_destroy(&condFuel);
    return 0;
}
