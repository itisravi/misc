#include <stdio.h>
#include <stdlib.h>
int main (void)
{
        char *set1[3] = {"DS", "DF","SF"};
        char *set2[3] = {"DS", "DF","SF"};
        char *set3[3] = {"DS", "DF","SF"};
        int i, j ,k;
        
        for(i=0; i<3; i++)
                for(j=0;j<3; j++)
                        for(k=0; k<3; k++) {

                                printf("%s %s %s\n",set1[i],set2[j],set3[j]);
                                
                        }

        return 0;
}

