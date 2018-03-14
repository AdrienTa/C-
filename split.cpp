#include "split.h"


char* splitLeft(char *table, long tabsize)
{
    char *d = new char[32];

    for(int i=0; i <32;i++)
    {
        d[i]=table[i];
    }

    return d;
}

char* splitRight(char *table, long tabsize)
{
    char *d = new char[32];

    for(int i=32; i <tabsize;i++)
    {
        d[i-32]=table[i];
    }

    return d;
}
