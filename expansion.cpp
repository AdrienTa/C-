#include "expansion.h"


char* expansion(char *table, char *exp_table, long tabsize)
{
    char *result = new char[48];

    for(int i=0; i <48;i++)
    {
        result[i]=table[(int)exp_table[i]-1];
    }

    return result;
}
