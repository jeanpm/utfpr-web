#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include <sys/resource.h>


int main(int argc, char** argv)
{
    
    struct rlimit limit;
    getrlimit (RLIMIT_STACK, &limit);
    printf ("\nStack Limit = %ld and %ld max\n",limit.rlim_cur,limit.rlim_max);
    
    int array_size = 0;

    scanf("%d", &array_size);
    int t[8408608];

    int vetor[array_size];

    for (int i = 0;i < array_size; i++)
        vetor[i] = i;


    for (int i = 0;i < array_size; i++)
        printf("%d ", vetor[i]);
    printf("\n");


    return 0;
}

