#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
        int *ptr=NULL;

        ptr =malloc (sizeof(int));
        if (ptr==NULL){
                printf ("Malloc failed\n");
                return -1;
        }

        *ptr=100;
        printf("Derferencing pointer. Value=%d\n",*ptr);
        free (ptr);
        printf("Derferencing pointer after free. Value=%d\n",*ptr);
        printf("Bye\n");
        return 0;
}

