#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t s1;
int count = 0;

void *func(void* v) {
	sem_wait(&s1);
	count++;
	printf("Count : %d \n", count);
	sem_post(&s1);
	return NULL;
}

int main () {
	pthread_t t1[5];

	sem_init(&s1, 0, 1);
	
	for(int i = 0; i < 5; i++) {
		pthread_create(&t1[i], NULL, func, NULL);
	}
	
	for(int i = 0; i < 5; i++) {
		pthread_join(t1[i], NULL);
	}
	
	return 0;
}

