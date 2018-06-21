#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main (int argc, char** argv)
{
        int fd;
        int ret;
        if (argc < 2) {
                printf ("Usage: %s <filename>\n",argv[0]);
                return 0;
        }
        fd = open (argv[1],O_RDWR);
        if (fd == -1) {
                perror("open");
                return -1;
        }
        ret = fsync(fd);
        if (ret == -1) {
                perror("fsync");
                return 0;
        }
}

