#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char mainPath[1000];

    DIR *dirp = opendir("/proc/");
    struct dirent *d;

    int pid;
    char cmd[100];

    printf("%6s %30s\n", "PID", "COMMAND");

    while(d = readdir(dirp)){
        // printf("%s\n", d->d_name);
        if(strcmp(d -> d_name, ".") != 0 && strcmp(d -> d_name, "..") != 0){
            if(d -> d_type == DT_DIR && atoi(d -> d_name) > 0){
                strcpy(mainPath, "/proc");
                strcat(mainPath, d->d_name);
                strcat(mainPath, "/stat");

                FILE *fp = fopen(mainPath, "r");
                if(fp == NULL) {
                    continue;
                }

                fscanf(fp, "%d\t%s", &pid, cmd);
                printf("%6d %30s\n", pid, cmd);
                fclose(fp);
            }
        }
    }
    closedir(dirp);

    return 0;
}