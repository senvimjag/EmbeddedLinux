#include<stdio.h>
#include<unistd.h>
int main(){
	pid_t p;
	p=fork();
	printf("\nFork returns:%d",p);
	printf("\nWelcome: My process id:%d, My parent's id:%d",getpid(),getppid());
	return 0;
}


