#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

struct myStruct {
	int a, b;
	char *op;
};

void *add(void *v) {
	struct myStruct *ptr = v;
	printf("%d\n", (*ptr).a + (*ptr).b);
	return NULL;
}

void *sub(void *v) {
	struct myStruct *ptr = v;
	printf("%d\n", (*ptr).a - (*ptr).b);
	return NULL;
}

void *mult(void *v) {
	struct myStruct *ptr = v;
	printf("%d\n", (*ptr).a * (*ptr).b);
	return NULL;
}

void *division(void *v) {
	struct myStruct *ptr = v;
	printf("%d\n", (*ptr).a / (*ptr).b);
	return NULL;
}

int main(int argc, char* argv[]) {

	pthread_t t;
	struct myStruct s1;
	struct myStruct *ptr = &s1;
	
	(*ptr).a = atoi(argv[1]);
	(*ptr).b = atoi(argv[2]);
	(*ptr).op = argv[3];
	
	switch(*(ptr->op)){	
		case '+':
			pthread_create(&t, NULL, add, (void*)ptr);
			break;	
		case '-':
			pthread_create(&t, NULL, sub, (void*)ptr);
			break;	
		case '%':
			pthread_create(&t, NULL, mult, (void*)ptr);
			break;	
		case '/':
			pthread_create(&t, NULL, division, (void*)ptr);	
			break;
		default:
			pthread_create(&t, NULL, sub, (void*)ptr);
			
	}
	pthread_join(t, NULL);
	
	return 0;
}
