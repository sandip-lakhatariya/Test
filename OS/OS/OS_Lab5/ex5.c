#include<stdio.h>
#include<pthread.h>

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
	pthread_t t;
	
	for(int i = 0; i < 5; i++){
		pthread_create(&t, NULL, fun, NULL);
	}
	
	for(int i = 0; i < 5; i++){
		pthread_join(t, NULL);
	}
	return 0;
}

// pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
// pthread_mutex_lock()
