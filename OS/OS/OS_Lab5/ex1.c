#include<stdio.h>
#include<pthread.h>

void *fun(void *v) {
	printf("Hello!");
	return NULL;
}

int main() {
	pthread_t t;
	
	pthread_create(&t, NULL, fun, NULL);
	
	//pthread_join(t, NULL);
	return 0;
}
