#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {

    for(int i = 0; i < 3; i++){
        if(fork() == 0){
            printf("Child %d from Parent %d\n", getpid(), getppid());
            exit(0);
        }
    }

    return 0;
}