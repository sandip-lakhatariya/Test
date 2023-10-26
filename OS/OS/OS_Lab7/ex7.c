#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


int main() {
	pid_t pid;
	int pipefd[2];
	pipe(pipefd);
	char buf[100];
	if((pid = fork()) > 0){
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		int fd = open("num.txt", O_RDONLY);
		read(fd, buf, sizeof(buf));
		write(pipefd[1], buf, sizeof(buf));
	}
	else{
		dup2(pipefd[0], 0);                             
		close(pipefd[1]);
		// bzero(buf, sizeof(buf));
		read(pipefd[0], buf, sizeof(buf));
		execl("/bin/sort", "sort", NULL);
	}
	return 0;
}
