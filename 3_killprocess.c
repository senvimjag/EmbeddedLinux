#include<stdio.h>
#include<unistd.h>
#include<signal.h>
int main(){
        pid_t p1,p2,p3;
        p1=fork();
        p2=fork();
        p3=fork();
        printf("\nWelcome");
        kill(p1,SIGKILL);
        //kill(p2,SIGKILL);
        //kill(p3,SIGKILL);
        printf("\nFork returns:%d %d %d",p1,p2,p3);
        //printf("\nWelcome: My process id:%d, My parent's id:%d",getpid(),getppid());
        return 0;
}

