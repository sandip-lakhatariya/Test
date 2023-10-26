#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t x;
sem_t wsem;
int readCnt;

void *reader(void * arg) {
        sem_wait(&x);
        readCnt += 1;
        if(readCnt == 1) sem_wait(&wsem);
        sem_post(&x);
        printf("Read by %d\n", (int)arg);
        sem_wait(&x);
        readCnt -= 1;
        if(readCnt == 0) sem_post(&wsem);
        sem_post(&x);
}

void *writer(void * arg) {
        sem_wait(&wsem);
        printf("Write by %d\n", (int)arg);
        sem_post(&wsem);     
}

int main () {
    readCnt = 0;
    pthread_t readThread1, readThread2, readThread3, writeThread;

    sem_init(&x,0,1);
    sem_init(&wsem, 0, 1);

    int r = 1, w = 1;
    pthread_create(&writeThread, NULL, writer, (void *)w);
    pthread_create(&readThread1, NULL, reader, (void *)r);
    r++;
    pthread_create(&readThread2, NULL, reader, (void *)r);
    r++;
    pthread_create(&readThread3, NULL, reader, (void *)r);
    pthread_join(readThread1, NULL);
    pthread_join(readThread2, NULL);
    pthread_join(readThread3, NULL);
    pthread_join(writeThread, NULL);
    return 0;
    
}