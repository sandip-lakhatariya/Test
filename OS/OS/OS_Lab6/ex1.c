#include <stdio.h>
#include <unistd.h>

int main() {
	
	int pipefd[2];
	
	if(pipe(pipefd) < 0){
		printf("Error!");
	}
	else{
		printf("%d\n", pipefd[0]);
		printf("%d\n", pipefd[1]);
	}
	return 0;
}
