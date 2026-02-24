#include<stdio.h>
#include<unistd.h>
int main(){
	fork();
	printf("\nWelcome: My process id:%d, My parent's id:%d",getpid(),getppid());
	return 0;
}


