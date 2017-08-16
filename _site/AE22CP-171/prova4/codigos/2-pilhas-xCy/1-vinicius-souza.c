#include <stdio.h>
#include <string.h>

char pilha[100];
int topo = -1;

void push(char c)
{
    pilha[++topo] = c;
}
char pop()
{
    return(pilha[topo--]);
}

int main()
{
    char string[100];
    int i, cont = 0, len;


    scanf("%s", string);
    len = strlen(string);
    for (i = 0; i < len; i++)
    {

        push(string[i]);

    }
    for (i = 0; i < len; i++)
    {

        if (string[i] == pop())
            cont++;
    }
    if (cont == len)
        printf("SIM");
    else
        printf("NÃO");
}

