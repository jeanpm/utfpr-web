#include <stdio.h>
#include <string.h>

char pilha[100];
int topo = -1;

void empilha(char c)
{
    pilha[++topo] = c;
}
char desempilha(){
    return(pilha[topo--]);
}


int main(void){
    char str[100];
    int i, aux = 0, le;

    scanf("%s", str);
    le = strlen(str);
    for (i = 0; i < le; i++)
    {

        empilha(str[i]);

    }
    for (i = 0; i < le; i++)
    {

        if (str[i] == desempilha())
            aux++;
    }
    if (aux== le)
        printf("SIM");
    else
        printf("NÃO");
}
