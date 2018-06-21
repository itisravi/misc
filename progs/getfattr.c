#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/xattr.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char **argv)
{
        int fd = 0;
        size_t attr_size = 0;
        char buffer[100] = {0};
        if (argc < 3 ) {
                printf("Usage:%s <filanem> <attr-name>\n", argv[0]);
        }
        fd = open (argv[1], O_RDONLY);
        if (fd == -1) {
                perror("open");
                return -1;
        }
        attr_size = fgetxattr (fd, argv[2], buffer, sizeof(buffer));
        if (attr_size == -1) {
                perror ("fgetxattr");
                return -1;
        }
        printf ("Key:%s Value:%s\n",argv[2], buffer);
        close (fd);
}

