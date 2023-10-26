#include <stdio.h>
#include <pthread.h>

void *fun(void *v) {
  char *str = v;
    printf("%s\n", str);
    return NULL;
}

int main() {

    pthread_t t1;
    char * str = "Hello";

    pthread_create(&t1, NULL, fun, (void*)str);
    pthread_join(t1, NULL);

    return 0;
}