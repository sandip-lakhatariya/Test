#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void main(int argc, char* argv[]) {
    // int source_fd = open(argv[1], O_RDONLY);
    // char source_buff[1000];
    // int fp = read(source_fd, source_buff, sizeof(source_buff));
    // int dest_fd = open(argv[2], O_WRONLY);
    // int n = write(dest_fd, source_buff, fp);

    int source_fd = open(argv[1], O_RDONLY);
    char source_buff[1000];
    int fp = read(source_fd, source_buff, sizeof(source_buff));
    int dest_fd = open(argv[2], O_WRONLY | O_CREAT);
    int n = write(dest_fd, source_buff, fp);
}