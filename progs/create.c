#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
        int ret = 0;
        if (argc<2) {
                printf("%s:<filename to create>\n",argv[0]);
                return 0;             
        }
        
        ret = creat (argv[1], 0644);
        if (ret==-1)
                perror("create");
        return 0;

}

