#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {

    int pid;

    for(int i = 0; i < 3; i++){

        pid = fork();

        if(pid > 0){
            printf("Parent %d\n", getpid());
            break;
        }
        else{
            printf("Child %d\n", getpid());
        }
    }

    wait(NULL);

    return 0;
}