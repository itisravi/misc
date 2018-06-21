#define  _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
        int fd = 0;
        int mode = -1;
        off_t offset = -1;
        off_t len = -1;
        int ret =0;

        if (argc <  5) {
                printf("\nUsage:%s {filename} {mode} {offset} {length}\n", argv[0]);
                printf("mode:\n"
                        "\t 0-default \n"
                        "\t 1-keep size\n"
                        "\t 2-hole punch\n"
                        "\t 3-collapse range\n"
                        "\t 4-zero range\n\n");
                return 0;
        }

        switch (atoi(argv[2])) {

          case 0:
                mode = 0;
                break;
          case 1:
                mode = FALLOC_FL_KEEP_SIZE;
                break;
          case 2:
                mode = FALLOC_FL_KEEP_SIZE|FALLOC_FL_PUNCH_HOLE;
                break;
          case 3:
                //mode = FALLOC_FL_COLLAPSE_RANGE;
                mode = 0x08;
                break;
          case 4:
                //mode = FALLOC_FL_ZERO_RANGE;
                mode = 0x10;
                break;
          default:
                mode=0;
        }

        offset = atoi(argv[3]);
        len = atoi(argv[4]);
        fd = open(argv[1], O_RDWR|O_CREAT, 0666);
        ret = fallocate (fd, mode, offset, len);
        if (ret == -1)
                perror ("fallocate");

        return ret;
}
