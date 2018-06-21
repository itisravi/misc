#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main (void)
{
        char hostname[1024];
        hostname[1023] = '\0';
        gethostname(hostname, 1023);
        printf("Hostname: %s\n", hostname);
        struct hostent* h;
        h = gethostbyname(hostname);
        printf("h_name: %s\n", h->h_name);
        return 0;
}

