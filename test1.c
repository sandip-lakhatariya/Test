#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void main(int argc, char* argv[]) {
    char buff[1000];
    int n, fd;

    if(argc == 1){
        while(n = read(0, buff, sizeof(buff))){
            write(1, buff, n);
        }
    }
    if(argc >= 2){
        for(int i = 0; i < argc; i++){
            fd = open(argv[i], O_RDONLY);
            n = read(fd, buff, 100);
            write(1, buff, n);
            // write(1, "\n", 1);
        }
    }
}