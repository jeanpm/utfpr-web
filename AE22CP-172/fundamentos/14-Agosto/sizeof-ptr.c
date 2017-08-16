#include <stdio.h>

int main() {
    printf("sizeof int = %ldbytes\n", sizeof(int));
    printf("sizeof long = %ldbytes\n", sizeof(long));
    printf("sizeof float = %ldbytes\n", sizeof(float));
    printf("sizeof char = %ldbytes\n", sizeof(char));
    printf("sizeof double = %ldbytes\n", sizeof(double));

    printf("\n");

    int p[10000];
    int* c = p;

    printf("sizeof int* = %ldbytes\n", sizeof(int*));
    printf("sizeof long* = %ldbytes\n", sizeof(long*));
    printf("sizeof float* = %ldbytes\n", sizeof(float*));
    printf("sizeof char* = %ldbytes\n", sizeof(char*));
    printf("sizeof double* = %ldbytes\n", sizeof(double*));
    printf("sizeof int[] = %ldbytes\n", sizeof(c));
 
}

/*
sizeof int = 4bytes
sizeof long = 8bytes
sizeof float = 4bytes
sizeof char = 1bytes
sizeof double = 8bytes

sizeof int* = 8bytes
sizeof long* = 8bytes
sizeof float* = 8bytes
sizeof char* = 8bytes
sizeof double* = 8bytes
sizeof int[] = 8bytes
*/
