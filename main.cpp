#include <iostream>
#include "permutations.h"
#include "bit_tables.h"
#include "data_tables.h"
#include "data_messages_examples.h"
#include "split.h"
#include "expansion.h"
#include "key.h"
#include "xor.h"
#include "substitution.h"

using namespace std;

int main()
{
    char *firstperm = new char[64];
    char *splitR = new char[32];
    char *splitL = new char[32];
    char *exp = new char[48];
    char *pcL = new char[32];
    char *pcR = new char[32];
    char *key = new char[48];
    char *result_xor = new char[48];
    char *sub = new char[32];
    char *perm = new char[32];
    char *xor_fi = new char[64];
    char *perm_message = new char[64];
    char *message = new char[64];

    cout<<"Original message"<<endl;
    displayBitTable(message_03,64);
    displayAsHex(message_03,64);
    cout<<endl<<"Primary key:"<<endl;
    displayBitTable(g,64);
    displayAsHex(g,64);

/////////////////////Premiere Permutation/////////////////////
    firstperm=permute(message_03,init_perm,64);

////////////////////Séparation en 2 blocs/////////////////
    splitL=splitLeft(firstperm,64);
    splitR=splitRight(firstperm,64);

////////////////////Iteration/////////////////////

    for (int cpt=0; cpt<16; cpt++)
    {

////////////////////////////Expansion////////////////////////////
        exp=expansion(splitR,expansion_table,48);

////////////////////KEY////////////////////////////////////
        pcL=pc_L(g,pc_1_left,32);
        pcR=pc_R(g,pc_1_right,32);

        pcL = shift_key(pcL,keyshift,cpt);
        pcR = shift_key(pcR,keyshift,cpt);

        key = fusion(pcL, pcR, pc_2);

///////////////XOR entre KEY et exp////////////////////
        result_xor = table_xor(exp, key, 48);

/////////////////Substitution//////////////////////////
        sub=substitution(result_xor,s_boxes);

///////////////Permutation///////////////
        perm=permute(sub,permut_32,32);

//////////////XOR entre splitL et la permutation/////////////
        xor_fi = table_xor(perm, splitL, 32);

        splitL = splitR;
        splitR = xor_fi;
    }
/////////////////Fin iteration///////////////////

///////////////Concatenation des 2 blocs///////////////
    for(int i =0; i<32; i++)
    {
        message[i]=splitR[i];
        message[i+32]=splitL[i];
    }

    perm_message=permute(message,reverse_perm,64);
    cout<<endl<<"Encrypted message"<<endl;
    displayBitTable(perm_message, 64);
    displayAsHex(perm_message,64);

}

