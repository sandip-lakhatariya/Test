#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	
	char buf[100];
	int fd = open("test.txt", O_RDONLY);
	int newfd = dup(fd);
	printf("%d\n", newfd);
	return 0;
}
