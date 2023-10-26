#include<stdio.h>
#include<unistd.h>
#define n 16

int main() {
   int pipefd1[2], pipefd2[2];
   int pid;
   char* msg1 = "Hello 1";
   char* msg2 = "Hello 2";
   char buf[n];
   
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
      printf("Parent: Writing to pipe 1 –> %s\n", msg1);
      write(pipefd1[1], msg1, sizeof(msg1));
      read(pipefd2[0], buf, sizeof(buf));
      printf("Parent: Reading from pipe 2 –> %s\n", buf);
   } 
   else{
      close(pipefd1[1]);
      close(pipefd2[0]);
      read(pipefd1[0], buf, sizeof(buf));
      printf("Child: Reading from pipe 1 –> %s\n", buf);
      printf("Child: Writing to pipe 2 –> %s\n", msg2);
      write(pipefd2[1], msg2, sizeof(msg2));
   }
   return 0;
}
