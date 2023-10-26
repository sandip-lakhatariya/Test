#include <unistd.h>
#include <stdio.h>

void main() {
    char buff[1000];
    char *c = getcwd(buff, sizeof(buff));
    printf("Current working directory: %s\n", buff);
}