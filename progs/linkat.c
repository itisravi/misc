#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <string.h>

int
main (int argc, char **argv)
{
        int ret = 0;
        int fd1 =-1;
        char emptystring[2]={'\0'};

        fd1 = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
        if (fd1 == -1) {
                perror ("open");
                return -1;
        }

        ret = write (fd1,"hello\n", strlen("hello\n"));
        if (ret == -1){
                perror ("write");
                close (fd1);
                return -1;
        }
        ret = linkat (fd1, emptystring, AT_FDCWD, argv[2], AT_EMPTY_PATH);
        if (ret) {
                perror ("linkat");
        }
        close(fd1);
        return 0;
}

