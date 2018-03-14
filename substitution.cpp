#include "substitution.h"

char *generateBitBlockFromInt(int outputvalue)
{
    char *result = new char[4];

    for (int i=0;i<4;i++)
    {
        result[i]=(outputvalue/8)%2;
        outputvalue *=2;
    }

    return result;
}

int generateIntFromBitBlock(char *block, long blocksize)
{
    int result=0;

    for(int i=0;i<blocksize;i++)
    {
        result = (2*result+block[i]);
    }

    return result;
}

char* substitution(char *table, char sTable[][64])
{
    char *result = new char[32];
    char *table_line = new char[2];
    char *table_col = new char[4];
    char *table_res = new char[4];
    int line, col, pos;

    for(int i =0; i<8; i++)
    {
        table_line[0]=table[0+(i*6)];
        table_line[1]=table[5+(i*6)];
        table_col[0]=table[1+(i*6)];
        table_col[1]=table[2+(i*6)];
        table_col[2]=table[3+(i*6)];
        table_col[3]=table[4+(i*6)];

        line = generateIntFromBitBlock(table_line, 2);
        col = generateIntFromBitBlock(table_col, 4);
        pos = (line*16)+col;

        table_res=generateBitBlockFromInt((int)sTable[i][pos]);

        for(int j =0; j<4;j++)
            result[j+(i*4)]=table_res[j];
    }
    return result;
}



