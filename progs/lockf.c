#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
        FILE        *fp = NULL;
        int ret;
        int i=0;

        ret= unlink("FILE");
        if (ret) {
                perror("unlink");
        }
        fp = fopen ("FILE", "a+");
        ret = lockf (fileno (fp), F_TLOCK, 0);
        if (ret) {
                perror("lock acquire failed\n");
        
        }
        printf("lock acquired on FILE by pid=%d, doing busy wait\n",getpid());
        while(i==0);
        ret = lockf (fileno (fp), F_ULOCK, 0);
        if (ret) {
                perror("lock release failed\n");
        }
        fclose(fp);
        return 0;
}

