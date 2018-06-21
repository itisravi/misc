#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int fd, ret;
        char buf[256]={0};
	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		perror("open");
		return -1;	
	}
	while(1){

                ret = read (fd, buf,256);
                if (ret == -1) {
                        perror("read");
                        return -1;
                }
                if (ret == 0)
                        break;
                printf("+++++++++++++++++++Read %d bytes ++++++++++++++\n",ret);
                printf("%s\n",buf);
                /*
                lseek(fd,0,SEEK_SET);
                if (ret == -1) {
                        perror("read");
                        return -1;
                }
                */
                sleep(1);
        }

        return 0;
        
}
