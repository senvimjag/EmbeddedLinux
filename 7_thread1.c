#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int main(){
  printf("\nMain Process ID %d:",getpid());
  printf("\nMain Thread ID %lu:",pthread_self());
  return 0;
}
