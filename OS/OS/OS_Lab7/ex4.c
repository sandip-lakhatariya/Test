#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {
	pid_t pid;
	
	if((pid = fork()) > 0){
		execl("/bin/ls", "ls", NULL);	
	}
	else{
		wait(NULL);
		execl("/bin/pwd", "pwd", NULL);
	}
	return 0;
}
