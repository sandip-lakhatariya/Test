#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
	pid_t pid;
	// int pipefd[2];
	// pipe(pipefd);
	char buf[100];
	int fd = open("num.txt", O_RDONLY);
	int n = read(fd, buf, sizeof(buf));
	int x = atoi(buf);
	// printf("%d\n", x);
	
	int arr[100], i = 0, j = 0;
	for (i = 0; i<n; i++) {
 
         if (buf[i] == ' '){
            j++;
        }
        else {
            printf("%c\n", buf[i]);
            arr[j] = arr[j] * 10 + (buf[i] - 48);
        }
        // printf("%d ", arr[j]);
    }
    
	//int arr[100];
	//for() 
	/* if((pid = fork()) > 0){
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		execl("/bin/ls","ls",NULL);	
	}
	else{
		dup2(pipefd[0], 0);
		close(pipefd[1]);
		execl("/bin/sort", "sort", NULL);
	} */
	return 0;
}
