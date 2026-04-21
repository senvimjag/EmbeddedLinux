#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#define MAX_RESOURCES 3
#define THREADS 5
sem_t sem;
int v = 2;   // Shared variable
void* worker(void* arg){
    int id = *(int*)arg;
    printf("Thread %d: Waiting for resource...\n", id);
    sem_wait(&sem);
    printf("Thread %d: Entered critical region\n", id);
    printf("Thread %d: Initial v = %d\n", id, v);
    int t = v;
    if (id % 2 == 0)
        t = t + 2;   // Even threads → add
    else
        t = t - 2;   // Odd threads → subtract
    sleep(1);   // Force race condition possibility
    v = t;
    printf("Thread %d: Updated v = %d\n", id, v);
    printf("Thread %d: Leaving critical region\n", id);
    sem_post(&sem);   // Release resource
    return NULL;
}
int main(){
    pthread_t t[THREADS];
    int id[THREADS];
    sem_init(&sem, 0, MAX_RESOURCES); //Initialize counting semaphore
    for(int i = 0; i < THREADS; i++){
        id[i] = i + 1;
        pthread_create(&t[i], NULL, worker, &id[i]);
    }
    for(int i = 0; i < THREADS; i++)
        pthread_join(t[i], NULL);
    sem_destroy(&sem);
    printf("\nFinal value of v = %d\n", v);
    return 0;
}
