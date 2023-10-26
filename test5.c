#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {

    int pid;
    pid = fork();

    if(pid == -1){
        printf("Error! \n");
    }
    else if(pid > 0){
        printf("Hello from parent : \n");
        printf("PID: %d\n", getpid());
        printf("PPID: %d\n", getppid());
    }
    else{
        printf("Hello from child : \n");
        printf("PID: %d\n", getpid());
        printf("PPID: %d\n", getppid());
    }

    return 0;
}