#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
	char buf[100];
	int pipefd[2], pid;

	if (pipe(pipefd) < 0)
		exit(1);

	if ((pid = fork()) > 0) {
		write(pipefd[1],argv[1],sizeof(argv[1]));
		close(pipefd[0]);
	}
	else {
		close(pipefd[1]);
        bzero(buf,sizeof(buf));
        read(pipefd[0],buf,sizeof(buf));
		int fd = open(buf,O_RDONLY);
		int n = read(fd,buf,sizeof(buf));
		printf("%s\n", buf);
	}
	return 0;
}
