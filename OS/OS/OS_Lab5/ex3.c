#include<stdio.h>
#include<pthread.h>

void *fun(void *v) {
	char *str = v;
	
	printf("%s\n", str);
	
	return NULL;
}

int main() {
	pthread_t t;
	char *str = "Hello"; 
	
	pthread_create(&t, NULL, fun, (void*)str);
	
	pthread_join(t, NULL);
	
	return 0;
}
