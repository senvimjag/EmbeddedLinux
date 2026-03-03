#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *Thread1(void*){
  int i;
  printf("\nI am in a Thread 1:%lu", pthread_self());
  for(i = 1; i <= 10; i++){
        printf("\nThread 1 printing:%d",i);
        sleep(1);
  }
  pthread_exit(NULL);
}

void  *Thread2(void*){
  int i;
  printf("\nI am in Thread2:%lu", pthread_self());
  for(i= 11; i<=111; i=i+10){
         printf("\nThread 2 printing:%d",i);
         sleep(1);
  }
  pthread_exit(NULL);
}

int main(){
  pthread_t t1, t2;
  int i;
  printf("\nMain Process ID %d:",getpid());
  printf("\nMain Thread ID %lu:",pthread_self());
  pthread_create(&t1,NULL, Thread1, NULL);
  pthread_create(&t2,NULL, Thread2, NULL);
  for(i=100; i<=1000; i=i+100){
        printf("\nMain Thread printing:%d",i);
        sleep(2);
  }
  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  pthread_exit(NULL);
  return 0;
}
