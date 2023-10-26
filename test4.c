#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>

int main() {

    char buff[1000];
    char *c = getcwd(buff, sizeof(buff));

    DIR *dp = opendir(c);
    struct dirent *d;

    while(d = readdir(dp)){
        if(d -> d_name[0] == '.')
            continue;
        printf("%s ", d -> d_name);
    }

    return 0;
}