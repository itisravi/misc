#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_string(char *str, int len)
{
        char *ptr = str;
        ptr+=len;

        if (len<=0) 
                return;
        while (len >0) {
                ptr--;
                len-=1;
                if(*ptr != 0x20)
                        continue;
                break;
        }
        printf("%s\n",ptr);
        *ptr = '\0';
        reverse_string(str, strlen(str));

}

int main (int argc, char**argv)
{
        if (argc <2) {
                printf("%s <\"sentence\">\n",argv[0]);
                return 0;
        }
        reverse_string(argv[1], strlen(argv[1]));
        return 0;
}

