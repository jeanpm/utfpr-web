#include <stdio.h>
#include <string.h>

void push(char);
char pop();
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
int main(void)
{
    char str[100];
    int i,contador = 0,len;
    
    scanf("%s",str);
    len = strlen(str);
    for (i = 0; i < len; i++)
    {

        push(str[i]);

    }
    for (i = 0; i < len; i++)
    {

        if (str[i] == pop())
            contador++;
    }
    if (contador == len)
        printf("SIM");
    else
        printf("NÃO");
}



