#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int arg, char **args[]){
	//char str[100];
	//int r = read(0, str, sizeof(str));
	int fd = open(args[0], O_RDONLY);
	char buf[100];
	int y = read(fd, buf, sizeof(buf));
	int x = write(1, buf, y);
	return 0;
}
