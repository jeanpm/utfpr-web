#include <stdlib.h>

int main()
{
    int* c = malloc( sizeof(int) );
    int* b = malloc(sizeof(int) * 10);
    int  d[10];

    *c = 10;
    
    c[0] = *c + c[0];

    free(c);
}
