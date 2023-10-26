#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int pid = fork();
	if(pid > 0){
		printf("Parent Process : Hello");
	}
	else if(pid == 0){
		printf("Child Process : Hello");
	}
	return 0;
}
