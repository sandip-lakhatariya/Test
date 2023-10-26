#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t x;
sem_t y;
sem_t z;
sem_t rsem;
sem_t wsem;
int readCnt, writeCnt;

void *reader(void * arg) {
        sem_wait(&z);
        sem_wait(&rsem);
        sem_wait(&x);
        readCnt += 1;
        if(readCnt == 1) sem_wait(&wsem);
        sem_post(&x);
        sem_post(&rsem);
        sem_post(&z);
        printf("Read by %d\n", (int)arg);
        sem_wait(&x);
        readCnt -= 1;
        if(readCnt == 0) sem_post(&wsem);
        sem_post(&x);
}

void *writer(void * arg) {
    sem_wait(&y);
    writeCnt++;
    if(writeCnt == 1) sem_wait(&rsem);
    sem_post(&y);
    sem_wait(&wsem);
    printf("Write by %d\n", (int)arg);
    sem_post(&wsem);     
    sem_wait(&y);
    writeCnt--;
    if(writeCnt == 0) sem_post(&rsem);
    sem_post(&y);
}

int main () {
    readCnt = 0;
    pthread_t readThread1, readThread2, readThread3, writeThread1, writeThread2;

    sem_init(&x,0,1);
    sem_init(&wsem, 0, 1);
    sem_init(&y,0,1);
    sem_init(&z,0,1);
    sem_init(&rsem, 0, 1);

    int r = 1, w = 1;
    pthread_create(&writeThread1, NULL, writer, (void *)w);
    pthread_create(&readThread1, NULL, reader, (void *)r);
    r++;
    pthread_create(&readThread2, NULL, reader, (void *)r);
    r++;
    w++;
    pthread_create(&writeThread2, NULL, writer, (void *)w);
    pthread_create(&readThread3, NULL, reader, (void *)r);
    pthread_join(writeThread1, NULL);
    pthread_join(readThread1, NULL);
    pthread_join(readThread2, NULL);
    pthread_join(writeThread2, NULL);
    pthread_join(readThread3, NULL);

    return 0;
    
}