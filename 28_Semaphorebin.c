//Two Threads accessing a shared memory with Semaphore (binary) sychronization
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
int v = 2;          // Shared resource
sem_t sem;          // Semaphore variable
void* task1(void* arg){
    printf("\nT1:Entering Critical Section\n");
    sem_wait(&sem);   // Lock using semaphore
    printf("T1: Initial value = %d\n", v);
    v = v + 2;
    sleep(1); // simulate delay
    printf("T1: Final value = %d\n", v);
   // printf("\nExiting Critical Section\n")
    sem_post(&sem);   // Unlock from critical section
    return NULL;
}
void* task2(void* arg){
    printf("\nT2:Entering Critical Section\n");
    sem_wait(&sem);   // Lock using semaphore
    printf("T2: Initial value = %d\n", v);
    v = v - 2;
    sleep(1); // simulate delay
    printf("T2: Final value = %d\n", v);
    sem_post(&sem);   //Unlock from critical section
    return NULL;
}
int main(){
    pthread_t t1, t2;
    sem_init(&sem, 0, 1); //Initialize binary semaphore
    pthread_create(&t1, NULL, task1, NULL);
    pthread_create(&t2, NULL, task2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&sem);  //Destroy semaphore
    printf("\nFinal v = %d\n", v);
    return 0;
}
