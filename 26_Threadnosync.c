//Two Threads accessing a shared memory without sychronization
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int v = 2; //shared memory
void* task1(){
   int t;
   printf("T1:intial value of v:%d\n",v);
   t = v;
   t = t+2;
   sleep(1);
   v = t;
   printf("T1:final value of v:%d\n",v);
}
void* task2(){
   int t;
   printf("T2:intial value of v:%d\n",v);
   t = v;
   t = t-2;
   sleep(1);
   v = t;
   printf("T2:final value of v:%d\n",v);
}
int main(){
   pthread_t t1,t2;
   pthread_create(&t1,NULL, task1, NULL);
   pthread_create(&t2,NULL, task2, NULL);
   pthread_join(t1,NULL);
   pthread_join(t2,NULL);
   printf("\nFinal value of v (main):%d\n",v);
   return 0;
}
