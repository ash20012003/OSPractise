#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

/*
Here we are creating 2 child processes. With the three processes in hand, we split a given array into 3, calculate their sums individually and then we put the caculated sums to gether to get the total sum.
*/

int main(int argc, char* argv[]) {
  int arr[] = {1,2,3,4,5,6,7,8,9};
  int size = sizeof(arr)/sizeof(int);
  int fd2[2];
  int fd[2];
  if(pipe(fd)==-1) return 1;
  if(pipe(fd2)==-1)return 1;
  int id1 = fork();
  int id2;
  if(id1 != 0){
    id2 = fork();
  }
  int start,end;
  if(id2==0){
    start = 0;
    end = size/3;
  }
  else{
    if(id1==0){
      start = size/3;
      end = 2*(size/3);
    }
    else{
      start = 2*(size/3);
      end = size;
    }
  }
  int sum =0;
  for(int i=start;i<end;i++) sum += arr[i];
  printf("Calculated partial sum is : %d\n",sum);
  if(id2==0){
    close(fd2[0]);
    write(fd2[1], &sum, sizeof(sum));
    close(fd2[1]);
  }
  else{
    if(id1 ==0){
      close(fd[0]);
      write(fd[1], &sum, sizeof(sum));
      close(fd[1]);
    }
    else{
      close(fd[1]);
      close(fd2[1]);
      int sum1;
      read(fd[0], &sum1, sizeof(sum1));
      close(fd[0]);
      int sum2;
      read(fd2[0],&sum2,sizeof(sum2));
      close(fd2[0]);
      int sumTotal = sum1+sum2+sum;
      printf("Total sum is %d\n",sumTotal);
    }
  }
  return 0;
}
