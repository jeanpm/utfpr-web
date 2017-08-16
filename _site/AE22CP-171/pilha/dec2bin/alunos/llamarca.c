//
//  main.c
//  exe2
//
//  Created by Luan Lamarca on 28/06/17.
//  Copyright © 2017 Luan Lamarca. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
    int *dados, tam, pos;
}pilha;

int inicializapilha(pilha *p, int tam)
{
    p->tam = tam;
    p->pos = 0;
    return *(p->dados = malloc(tam * sizeof(int)));
}

void empilha(pilha *p, int elem)
{
    if(p->pos == p->tam)
    {
        printf("pilha cheia\n") ;
    }
    else
    {
        p->dados[p->pos++] = elem;
    }
}
int desempilha(pilha *p)
{
    if(!p->pos)
        return 0;
    else
        return p->dados[--p->pos];
}
void decimalParaBinario(int num, pilha *p)
{
    int aux;
    while(num != 0)
    {
        aux = num%2;
        empilha(p, aux);
        num = num/2;
    }
}
int topo(pilha *p)
{
    return p->pos;
}

int main(void)
{
    int numero;
    pilha *p=malloc(sizeof(pilha));
    inicializapilha(p, 50);
    scanf("%d", &numero);
    decimalParaBinario(numero, p);
    while(desempilha(p)!=0)
        printf("%d", topo(p));
    printf("\n");
    return 0;
}
