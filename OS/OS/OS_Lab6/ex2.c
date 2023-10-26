#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define n 16

char* msg = "hello, world !";

int main()
{
	char buf[n];
	int pipefd[2], pid, nbytes;

	if (pipe(pipefd) < 0)
		exit(1);

	if ((pid = fork()) > 0) {
		write(pipefd[1], msg, n);
		close(pipefd[1]);
	}
	else {
		close(pipefd[1]);
		read(pipefd[0], buf, n);
		printf("%s\n", buf);
	}
	
	return 0;
}

