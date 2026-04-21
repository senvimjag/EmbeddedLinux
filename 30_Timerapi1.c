//Timer API Programming with 1 sec delay and signal handler
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
timer_t tid;

void handler(int sig) { // Signal handler for timer
    printf("[Handler] Timer expired!\n");
}

int main() {
    struct sigevent sev;
    struct itimerspec its;
    struct sigaction sa;

    sa.sa_handler = handler; //Setup signal handler
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGALRM, &sa, NULL);
    printf("Signal handler registered\n");

    sev.sigev_notify = SIGEV_SIGNAL; //Configure timer
    sev.sigev_signo = SIGALRM;


    timer_create(CLOCK_REALTIME, &sev, &tid); //Create Timer

    printf("Timer created\n");

    its.it_value.tv_sec = 1; // Set timer: 1 sec initial
    its.it_interval.tv_sec = 1; // Set timer: 1 sec interval
    timer_settime(tid, 0, &its, NULL); //Set Timer

    printf("Timer started (1 sec interval)\n");
    for(int i = 0; i < 5; i++) { //Start Timer
        printf("[Main] Waiting... (%d)\n", i+1);
        sleep(1);
    }

    timer_delete(tid); //Delete timer
    printf("Timer stopped and deleted\n");
    return 0;
}
