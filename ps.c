#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>

void ps_command(int argc, char *argv[])
{
    char mainPath[100];
    DIR *dirp = opendir("/proc/");
    struct dirent *d;

    int pid;
    char cmd[100];
    char state;
    int ppid;
    char state1[20];

    printf("%6s %30s\n", "PID", "COMMAND");

    while (d = readdir(dirp))
    {
        if (strcmp(d->d_name, ".") != 0 && strcmp(d->d_name, "..") != 0)
        {
            if (d->d_type == DT_DIR && atoi(d->d_name) > 0)
            {
                strcpy(mainPath, "/proc/");
                strcat(mainPath, d->d_name);
                strcat(mainPath, "/stat");

                FILE *fp = fopen(mainPath, "r");
                if (fp == NULL)
                    continue;

                fscanf(fp, "%d\t%s", &pid, cmd);

                printf("%6d %30s ", pid, cmd);

                printf("\n");
                fclose(fp);
            }
        }
    }
    closedir(dirp);
}

int main(int argc, char *argv[])
{
    ps_command(argc, argv);
    return 0;
}
