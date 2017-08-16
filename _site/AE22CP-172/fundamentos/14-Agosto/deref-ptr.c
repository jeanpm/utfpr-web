#include<stdlib.h>

#include <stdio.h>

int main() {
    int c = 10;

    int* ptr = &c;

    int* vetor = malloc(sizeof(int) * 10);

    vetor[0] = -198;

//    ptr = 1999;

    *ptr = 18765;

    ptr[0] = 9876;

    return 0;

}
