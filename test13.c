
#include <stdio.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void *fun(void *v) {
    pthread_mutex_lock(&m);
    count++;
    printf("%d\n", count);
    pthread_mutex_unlock(&m);
    return NULL;
}

int main() {

  int pipefd[2];

  if(pipe(pipefd) == -1) {
    printf("Error!");  
  }
  else{z
    printf("%d\n", pipefd[0]);
    printf("%d\n", pipefd[1]);
  }

    return 0;
}