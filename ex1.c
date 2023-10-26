#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char* argv[]) {
    int pipefd1[2], pipefd2[2];
    int pid;
    char buf[100];
    
    if(pipe(pipefd1) == -1){
        printf("Error while creating pipe 1 \n");
        return 1;
    }
    
    if(pipe(pipefd2) == -1){
        printf("Error while creating pipe 2 \n");
        return 1;
    }
   
    pid = fork();
   
    if(pid != 0){
        close(pipefd1[0]); 
        close(pipefd2[1]); 
        write(pipefd1[1],argv[1],sizeof(argv[1]));
		bzero(buf,sizeof(buf));
		int m = read(pipefd2[0],buf,sizeof(buf));
        printf("Parent: Reading from pipe 2 –> %s\n", buf);
    } 
    else{
        close(pipefd1[1]);
        close(pipefd2[0]);
        bzero(buf,sizeof(buf));
		read(pipefd1[0],buf,sizeof(buf));
		int fd = open(buf,O_RDONLY);
		int n = read(fd,buf,sizeof(buf));
		write(pipefd2[1],buf,n);
    }
    return 0;
}
