#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	
	int pid = fork();
	if(pid > 0){
		printf("Parent id : %d\n", getpid());
		printf("Child id : %d\n", pid);
		wait(0);
	}
	else if(pid == 0){
		printf("Child id : %d\n", getpid());
		printf("Parent id : %d\n", getppid());
	}
	
	/* printf("Hello");
	fork();
	fork();
	fork();
	fork(); */
	
	
	
	return 0;
}
