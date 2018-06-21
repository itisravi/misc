#include <stdio.h>
#include <stdlib.h>

int array[10]={9,8,4,3,1,5,6,7,2,0};

int compare (const void *i, const void *j)
{
        int *p1 = (int*)i;
        int *p2 = (int*)j;
        
        if (*p1==*p2)
                return 0;
        return (*p1 > *p2 ? 1: -1);

}
int main(void)
{       int loop = 0;
        qsort(array,10,sizeof(int),&compare);
        for (loop = 0; loop < 10; loop++)
                printf("%d\n",array[loop]);
       return 0;
} 
