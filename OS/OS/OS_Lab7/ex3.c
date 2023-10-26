#include <stdio.h>
#include <unistd.h>

int main() {
	printf("Before ls\n");	
	// execl("/bin/ls", "ls", "-l", NULL);
	execl("/bin/ls", "ls", NULL);
	printf("After ls\n");
	return 0;
}
