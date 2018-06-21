#include <stdio.h>
int main(void){

        char str[]= " #include <stdio.h> int main(void){ char str[]= %c%s%c; printf(str, 0x22, str, 0x22);}";
        printf(str, 0x22, str, 0x22);
}
