#include <stdio.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <string.h>
#include <sys/statvfs.h>
#include <unistd.h>
#include <libgen.h>
#include <uuid/uuid.h>
int main (int argc, char *argv[])
{
        uuid_t myuuid ;
        printf ("Is NULL:%s\n",uuid_is_null(myuuid)?"yes":"no");
        return 0;
}
