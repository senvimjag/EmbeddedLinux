#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
void alarm_handler(int sig) {// Signal handler for alarm 
    printf("\nAlarm signal received! (Signal %d)\n", sig);
}
int main() {
    printf("Process Details\n");
    printf("Process ID (PID): %d\n", getpid());
    printf("Parent Process ID (PPID): %d\n", getppid());
    printf("\nFork Demo\n");
    pid_t pid = fork();
    if(pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }
    else if(pid == 0) { //Child Process 
        printf("\n I am Child Process \n");
        printf("Child PID: %d\n", getpid());
        printf("Child Parent PID: %d\n", getppid());
        printf("Child sleeping for 2 seconds...\n");
        sleep(2);

        printf("\nExecute Linux Commands from child process\n");
        printf("Child replacing process using execl()\n");
        execl("/bin/ls", "ls", "-l", NULL);
        printf("Exec failed!\n");         // Runs only if exec fails 
        exit(0);
    }
    else {  //Parent Process 
        printf("\nI am Parent Process \n");
        signal(SIGALRM, alarm_handler);         // Setup alarm signal
        printf("Setting alarm for 3 seconds...\n");
        alarm(3);
        printf("Parent waiting for signal using pause()...\n");
        pause();  // waits until alarm signal arrives
        printf("Parent resumed after signal\n");
        wait(NULL); // Wait for child termination 
        printf("Child process finished\n");
    }
    return 0;
}
