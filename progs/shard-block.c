#include <stdio.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <string.h>
#include <sys/statvfs.h>
#include <unistd.h>
#include <libgen.h>

#define get_highest_block(off, len, shard_size) \
        (((((off)+(len)) == 0)?0:((off)+(len)-1)) / (shard_size))



int main (int argc, char *argv[])
{
        int last_block = 0;

        last_block = get_highest_block(0, 18446744073709522944,4194304);
        printf("%lu\n", last_block);
        return 0;
}
