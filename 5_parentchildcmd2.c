#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
        pid_t p;
        p=fork();
        //p=fork();
        //p=fork();
        kill(p,SIGKILL);
        if(p==0){ //Child Process
                printf("\nI am child process");
                printf("\nChild process id:%d",getpid());
                printf("\nMy parent process id:%d",getppid());
                printf("\nFork value p @ child:%d",p);
                execl("/bin/cal","Calender",NULL);
                printf("\nThis line will not execute, if the above is sucess");
                exit(1);
        }
        else if(p>0){ //Parent Process
                printf("\nI am parent process");
                printf("\nParent process id:%d",getpid());
                printf("\nMy parent process id:%d",getppid());
                printf("\nFork value p @ parent:%d",p);
                execl("/bin/ls","ls","-l",NULL);
                wait(NULL);  //Wait for child process (Avoid Zombie process)
        }
        else{   //p<0; No child process cretaed
                printf("\nSorry fork failed");
                exit(0);
        }
        return 0;
}


