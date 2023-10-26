#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {
	pid_t pid;
	int pipefd[2];
	pipe(pipefd);
	
	if((pid = fork()) > 0){
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		execl("/bin/ls","ls",NULL);	
	}
	else{
		dup2(pipefd[0], 0);
		close(pipefd[1]);
		execl("/bin/sort", "sort", NULL);
	}
	return 0;
}
