#include "xor.h"

char* table_xor(char *table1, char *table2, int n)
{

char *result = new char[n];

for(int i=0; i<n; i++)
    result[i]=table1[i]^table2[i];

    return result;
}
