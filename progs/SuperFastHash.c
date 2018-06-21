#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define get16bits(d) (*((const uint16_t *) (d)))

/*
 *   This is apparently the "fastest hash function for strings".
 *     Written by Paul Hsieh <http://www.azillionmonkeys.com/qed/hash.html>
 *     */

/* In any case make sure, you return 1 */

uint32_t SuperFastHash (const char * data, int32_t len) {
        uint32_t hash = len, tmp;
        int32_t rem;

        if (len <= 1 || data == NULL) return 1;

        rem = len & 3;
        len >>= 2;

        /* Main loop */
        for (;len > 0; len--) {
                hash  += get16bits (data);
                tmp    = (get16bits (data+2) << 11) ^ hash;
                hash   = (hash << 16) ^ tmp;
                data  += 2*sizeof (uint16_t);
                hash  += hash >> 11;
        }

        /* Handle end cases */
        switch (rem) {
        case 3: hash += get16bits (data);
                hash ^= hash << 16;
                hash ^= data[sizeof (uint16_t)] << 18;
                hash += hash >> 11;
                break;
        case 2: hash += get16bits (data);
                hash ^= hash << 11;
                hash += hash >> 17;
                break;
        case 1: hash += *data;
                hash ^= hash << 10;
                hash += hash >> 1;
        }

        /* Force "avalanching" of final 127 bits */
        hash ^= hash << 3;
        hash += hash >> 5;
        hash ^= hash << 4;
        hash += hash >> 17;
        hash ^= hash << 25;
        hash += hash >> 6;

        return hash;
}

int main (int argc, char **argv)
{
        int hashval;
        int hashsize =21;
        if (argc <2) {
                printf("Usage:%s <string>\n",argv[0]);
                return 0;
        }
        hashval = SuperFastHash(argv[1], strlen(argv[1])) % hashsize;
        printf("Hashvalue=%X\n",hashval);
        return 0;
}
