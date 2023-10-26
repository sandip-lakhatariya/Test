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

    pthread_t t1;

    for(int i = 0; i < 5; i++){
      pthread_create(&t1, NULL, fun, NULL);
      
    }
    for(int i = 0; i < 5; i++){
      pthread_join(t1, NULL);

    }

    return 0;
}