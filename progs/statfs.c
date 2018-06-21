#include <sys/vfs.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char**argv)
{
        int ret = 0;
        struct statfs buf={0};
        ret = statfs (argv[1], &buf);
        if (ret==-1) {
                perror("statfs");
                return -1;
        }
        printf("Total size=%llu\n",buf.f_blocks*buf.f_bsize);
        printf("Total size=%llu\n",buf.f_blocks*buf.f_frsize);
        return 0;
}
