//Two Threads Accessing Shared Memory with Mutex Synchronization
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int v = 2; //shared memory
pthread_mutex_t lock;
void* task1(){
   int t;
   printf("\nEntering critical section of T1\n");
   pthread_mutex_lock(&lock); //Locking critical section
   printf("T1:intial value of v:%d\n",v);
   t = v;  //Reading from shared memory
   t = t+2; //Updating the value
   sleep(1); //Waiting for other process (but not allows)
   v = t; //Writing back to shaed memory
   printf("T1:final value of v:%d\n",v);
   //printf("\nExiting critical section of T1\n");
   pthread_mutex_unlock(&lock);//unlocking critical section
}
void* task2(){
   int t;
   printf("\nEntering critical section of T2:\n");
   pthread_mutex_lock(&lock);
   printf("T2:intial value of v:%d\n",v);
   t = v;
   t = t-2;
   sleep(1);
   v = t;
   printf("T2:final value of v:%d\n",v);
   //printf("\nExiting critical section of T2\n");
   pthread_mutex_unlock(&lock);
}
int main(){
   pthread_t t1,t2;
   pthread_mutex_init(&lock,NULL); //Initialize Mutex
   pthread_create(&t1,NULL, task1, NULL);
   pthread_create(&t2,NULL, task2, NULL);
   pthread_join(t1,NULL);
   pthread_join(t2,NULL);
   printf("\nFinal value of v (main):%d\n",v);
   pthread_mutex_destroy(&lock);//Destroy Mutex
   return 0;
}
