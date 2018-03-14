#include "key.h"
#include "bit_tables.h"

char* pc_R(char *table, char *pc_right, long tabsize){

    char *result = new char[28];

    for(int i=0; i <32;i++)
    {
        result[i]=table[(int)pc_right[i]-1];
    }

    return result;
}

char* pc_L(char *table, char *pc_left, long tabsize){

    char *result = new char[28];

    for(int i=0; i <32;i++)
    {
        result[i]=table[(int)pc_left[i]-1];
    }

    return result;
}

char* shift_key(char *table, char *keyshift, int cpt){

    char *shift = new char[28];
    int i = keyshift[cpt];

    for(int j=0; j<28; j++)
        shift[j]= table[(j+i)%28];

        return shift;
}

char* fusion(char *tableL, char *tableR, char *pc2){

    char *table = new char[48];
    char *result = new char[48];

    for(int i=0; i<28; i++)
    {
        table[i] = tableL[i];
        table[i+28] = tableR[i];
    }

    for(int j=0; j<48; j++)
        result[j]=table[(int)pc2[j]-1];

    return result;
}

