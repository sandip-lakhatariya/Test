/* 

=> finite buffer
	1 producer, 1 consumer
	1 producer, N consumer
	N producer, N consumer
	
=> infinite buffer
 */






#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t s;
sem_t n;
sem_t e;
int count = 0;
int n1 = 100;
int buffer[100];
int i = 0;
int j = 0;

void *producer(void* v) {
	while(1) {
		count++;
		//while((i+1) % n1 == j);
		//sem_wait(&e);
		sem_wait(&s);
		buffer[i] = count;
		printf("Producer : %d \n", count); 
		i = (i + 1) % n1;
		sem_post(&s);
		sem_post(&n);
		sleep(1);
	}
	//return NULL;
}

void *consumer(void* v) {
	while(1) {
		//while(i == j);
		sem_wait(&n);
		sem_wait(&s);
		int w = buffer[j];
		printf("Consumer : %d \n", w);
		buffer[j] = 0;
		j = (j + 1) % n1; 
		sem_post(&s);
		sleep(1);
		//sem_post(&e);
	}
	//return NULL;
}

int main () {
	pthread_t t1[2];

	sem_init(&s, 0, 1);
	sem_init(&n, 0, 0);
	sem_init(&e, 0, 100);
	
	pthread_create(&t1[1], NULL, consumer, NULL);
	pthread_create(&t1[0], NULL, producer, NULL);
	
	pthread_join(t1[0], NULL);
	pthread_join(t1[1], NULL);
	
	return 0;
}

