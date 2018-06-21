#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define CHUNK_SIZE 1024

int main (int argc, char **argv)
{
        char *file = NULL;
        int fd = -1;
        char *buffer = NULL;
        size_t buf_size = 0;
        off_t offset = 0;
        size_t length = 0;
        size_t written = 0;
        int loop_count = 0;
        int i = 0;
        int ret = 0;

        if (argc < 4) {
                printf ("Usage:%s <file> <offset> <length>\n", argv[0]);
                return 0;
        }
    
        file = argv[1];
        offset = (off_t)atoi(argv[2]);
        length = (size_t)atoi(argv[3]);

        if (length < CHUNK_SIZE)
                buf_size = length;
        else
                buf_size = CHUNK_SIZE;
        buffer = calloc(1, buf_size);
        if (!buffer) {
                perror("calloc");
                return -1;
        }
        memset (buffer,'R', buf_size);
   
        fd = open(file, O_WRONLY);
        if (fd == -1) {
                perror("open");
                return -1;
        }
        offset = lseek (fd, offset , SEEK_SET);
        if (offset == -1) {
                perror("lseek");
        }
        loop_count = length/buf_size;
        for (i = 0 ; i < loop_count; i++) {
                ret =  write (fd, buffer, buf_size);
                if (ret == -1) {
                        perror("write");
                        return ret;
                }
                written += ret;
        }
        ret = write (fd, buffer, length%buf_size);
        if (ret == -1) {
                perror("write");
                return ret;
        }
        written += ret;
        
        printf("Written %d bytes starting at offset %d\n.",written, offset);
        free(buffer);
        close(fd);
        return 0;

}
