#define _GNU_SOURCE 
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main (int argc, char **argv)
{
        DIR *dirfd=NULL;
        dirfd = opendir(argv[1]);
        if (!dirfd) {
                perror ("opendir");
                return -1;
        }
        printf ("Got dirfd for %s\n",argv[1]);
        while (1)
                sleep(10);
        return 0;

        
}

