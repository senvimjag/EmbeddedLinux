//Timer API Programming with 2 sec delay and timer handler

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
timer_t timerid;
void timer_handler(int sig, siginfo_t *si, void *uc){ //Timer handler
    printf("\n[Handler] Timer Expired!");
    int overrun = timer_getoverrun(timerid);// Get overrun count
    printf("\nOverrun count: %d\n", overrun);
}
int main(){
    struct sigevent sev;
    struct itimerspec its;
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO; // Setup signal handler
    sa.sa_sigaction = timer_handler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, NULL);

    sev.sigev_notify = SIGEV_SIGNAL; // Configure timer to send signal
    sev.sigev_signo = SIGRTMIN;
    sev.sigev_value.sival_ptr = &timerid;
   timer_create(CLOCK_REALTIME, &sev, &timerid); //Create timer
   printf("Timer created.\n");

   its.it_value.tv_sec = 2; // Set timer: first expiry after 2 sec,
   its.it_interval.tv_sec = 2; // then expiry every 2 sec
   timer_settime(timerid, 0, &its, NULL);
   printf("Timer started (2 sec interval).\n");
   for(int i = 0; i < 5; i++){ // Check remaining time periodically
        sleep(1);
        struct itimerspec curr;
        timer_gettime(timerid, &curr);
        printf("\n[Main] Time left: %ld sec", curr.it_value.tv_sec);
    }
    timer_delete(timerid); // Delete timer
    printf("\nTimer deleted.\n");
    return 0;
}
