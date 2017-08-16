#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(int argc, const char * argv[])
{
    int resultado;

    char A[100];
    char B[100];
    
    strcpy(A, "a");
    strcpy(B, "b");
    
    resultado = strcmp(A,B);

    if (resultado == 0) 
    {
         printf("Strings sao iguais\n");        
    } 
    if (resultado < 0) 
    {
        printf("A menor que B\n");
    }
    else
    {
        printf("A maior que B\n");
    }    
    return 0;
}
