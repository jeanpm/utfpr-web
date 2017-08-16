#include <stdlib.h>

int main()
{
    int d = 99;

    int* a;

    int* b = NULL;

    if (b)
        b = &d;

    *a = 10;
}
