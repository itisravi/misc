//http://www.stlinux.com/devel/debug/backtrace
//gcc flags: -funwind-tables -rdynamic
#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>

#define BACKTRACE_SIZ 64
 
void log_backtrace (void)
{
    void    *array[64];
    size_t   size, i;
    char   **strings;
    FILE *fp = fopen ("/tmp/backtrace.txt", "a+");
    if(!fp)
        return;

    size = backtrace(array, 64);
    strings = backtrace_symbols(array, size);

    fprintf(fp,"++++++++++++++++++++\n");
    fprintf(fp,"pid:%d parentpid:%d\n",getpid(),getppid());
    for (i = 0; i < size; i++) {
       fprintf(fp,"%p : %s\n", array[i], strings[i]);
    }

        fclose(fp);
    free(strings);  // malloced by backtrace_symbols
}

void show_backtrace (void)
{
    void    *array[BACKTRACE_SIZ];
    size_t   size, i;
    char   **strings;
 
    size = backtrace(array, BACKTRACE_SIZ);
    strings = backtrace_symbols(array, size);
 
    for (i = 0; i < size; i++) {
        printf("%p : %s\n", array[i], strings[i]);
    }
 
    free(strings);  // malloced by backtrace_symbols
}

void wrapper(void)
{
	show_backtrace();
}
int main(void)
{
	wrapper();
	return 0;
	
}


