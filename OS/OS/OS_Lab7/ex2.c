#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	int fd = open("test.txt", O_WRONLY | O_APPEND);
	int newfd = dup2(fd, 1);
	printf("Welcome to DDU.\n");
	return 0;
}
