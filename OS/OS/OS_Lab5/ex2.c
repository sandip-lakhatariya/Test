#include<stdio.h>
#include<pthread.h>

void *fun1(void *v) {
	printf("Hello from thread 1\n");
	return NULL;
}

void *fun2(void *v) {
	printf("Hello from thread 2\n");
	return NULL;
}

int main() {
	pthread_t t1;
	pthread_t t2;
	
	pthread_create(&t1, NULL, fun1, NULL);
	pthread_create(&t2, NULL, fun2, NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	return 0;
}
