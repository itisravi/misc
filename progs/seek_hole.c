#define _GNU_SOURCE 
#include <sys/types.h>
 #include <unistd.h>
 #include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
        char *file = NULL;
        off_t offset = 0;
        int fd = -1;
        if (argc != 3) {
                printf("Usage: %s filename offset\n",argv[0]);
                return 0;
        }
        file = argv[1];
        offset = atoi(argv[2]);
        fd = open (file, O_RDONLY);
        if (fd == -1) {
                perror ("open");
                return -1;
        }

        offset = lseek (fd, 0,SEEK_SET);
        if (offset == -1) {
                perror ("SEEK_SET");
                return -1;
        }

        offset = lseek (fd, 0,SEEK_DATA);
        if (offset == -1) {
                perror ("SEEK_DATA");
                return -1;
        }
        printf ("First data found at offset %zd \n",offset);
        
        offset = lseek (fd, 0, SEEK_HOLE);
        if (offset == -1) {
                perror ("SEEK_HOLE");
                return -1;
        }
        printf ("First hole found at offset %zd \n",offset);

        offset = lseek (fd, offset,SEEK_DATA);
        if (offset == -1) {
                perror ("SEEK_DATA after hole");
                return -1;
        }
        printf ("First data found at offset %zd after first hole\n",offset);
        
        return 0;
}

