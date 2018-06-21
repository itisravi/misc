#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

int main()
{
        uint64_t val= 4379182848;
        uint16_t datamap = 0;
        uint16_t metadatamap = 0;
        uint64_t event = 0;

        printf("%" PRIX64 "\n", val);

        metadatamap = (val & 0x000000000000ffff) >> 0;
        datamap =     (val & 0x00000000ffff0000) >> 16;
        event =       (val & 0xffffffff00000000) >> 32;
        printf ("event=%X data=%X metadata=%X\n",event, datamap, metadatamap);

/*
         val = ((uint64_t) metadatamap) |
                (((uint64_t) datamap) << 16) |
                (((uint64_t) event) << 32);
        printf("%" PRIX64 "\n", val);
*/
        return 0;
} 
