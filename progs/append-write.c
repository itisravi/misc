#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char **argv)
{
        char *file = NULL;
        int fd = -1;
        char *buffer = NULL;
        size_t buf_size = 1024;
        size_t written = 0;
        int ret = 0;
        int i = 0;

        if (argc < 2) {
                printf ("Usage:%s <file>\n", argv[0]);
                return 0;
        }
    
        file = argv[1];

        buffer = calloc(1, buf_size);
        if (!buffer) {
                perror("calloc");
                return -1;
        }
   
        fd = open(file, O_WRONLY|O_APPEND);
        if (fd == -1) {
                perror("open");
                return -1;
        }
        while (1) {
                sprintf(buffer,"This is line %d \n",i);
                printf("Writing:%s",buffer);
                ret =  write (fd, buffer, strlen(buffer));
                if (ret == -1) {
                        perror("write");
                        break;
                }
                written += ret;
                i++;
                sleep (2);
        }
        
        printf("Written %d bytes and %d lines\n.",written,i);
        free(buffer);
        return 0;

}
