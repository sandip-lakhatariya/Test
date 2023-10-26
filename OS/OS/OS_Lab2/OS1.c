#include<unistd.h>
#include<stdio.h>

int main(){
	char buf[100];
	char *c = getcwd(buf, sizeof(buf));
	printf("Current Working Directory : %s\n", buf);
	// int x = write(1, c, sizeof(c));
	return 0;
}
