#include <stdlib.h>

void faznada(int a1, int b1)
{
    int a = a1;
    int b = b1;
    int c = a + b;
}

int main()
{
    int* a = malloc(sizeof(int)* 10);
    int  b[10];
    int c = 11;
    faznada(99, 1);
    for (int i = 0; i <= 15; i++)
    {
        a[i] = i;
        b[i] = i;
    }
}
