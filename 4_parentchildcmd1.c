#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
        pid_t p;
        p=fork();
        if(p==0){ //Child Process
                printf("\nI am child process");
                printf("\nChild process id:%d",getpid());
                printf("\nMy parent process id:%d",getppid());
                printf("\nFork value p @ child:%d",p);
                execl("/bin/cal","Calender",NULL); //Executes Calender Linux command
                printf("\nThis line will not execute, if the above is successful.");
                exit(1);
        }
        else if(p>0){ //Parent Process
                printf("\nI am parent process");
                printf("\nParent process id:%d",getpid());
                printf("\nMy parent process id:%d",getppid());
                printf("\nFork value p @ parent:%d",p); //It is the pid of the child process
                wait(NULL); // Wait for child termination & prevent Zombie process
        }
        else{   //p <0;
                printf("\nSorry fork failed");
                exit(0);
        }
        return 0;
}

