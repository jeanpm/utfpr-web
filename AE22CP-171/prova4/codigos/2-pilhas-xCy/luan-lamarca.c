//
//  main.c
//  palindromo
//
//  Created by Luan Lamarca on 05/07/17.
//  Copyright © 2017 Luan Lamarca. All rights reserved.
//

#include<stdio.h>
#include<string.h>
#define l_type char
#define maxl 100
#define true 1
#define false 0

typedef struct lista
{
    int inicio,fim,cont;
    l_type vet[maxl];
    
}lista;

int empilha (lista*l,l_type elem)
{
    if(l->cont>maxl)
    {
        return false;
    }
    if(l->cont !=0)
    {
        l->inicio=(maxl+l->inicio-1)%maxl;
        l->vet[l->inicio]=elem;
        l->cont=l->cont++;
        return true;
    }
    return true;
}

l_type desempilha (lista*l)
{
    l_type ret;
    ret=l->vet[l->inicio];
    if(l->cont>1)
    {
        l->inicio=(l->inicio+1)%maxl;
        l->cont--;
    }
    return ret;
}

void inicializa_pilha (lista*l)
{
    l->inicio=0;
    l->fim=0;
    l->cont=0;
}
char espia_topo(lista *l)
{
    return l->vet[l->inicio];
}
int pilha_vazia(lista *l)
{
    if(l->cont!=0)
    {
        return 0;
    }
    return 1;
}

int main (void)
{
    char expres[100];
    lista pilha;
    inicializa_pilha(&pilha);
    int i=0;
    scanf("%s", expres);
    
    while(expres[i]!='C'&&expres[i]!='\0')
    {
        empilha(&pilha, expres[i]);
        i++;
    }
    while(expres[i]!='C'&&expres[i]!='\0')
    {
        empilha(&pilha, expres[i]);
        i++;
    }
    while(expres[i]!='\0')
    {
        if(espia_topo(&pilha)==expres[i])
        {
            desempilha(&pilha);
        }
        else
        {
            printf("SIM");
            return 0;
        }
        i++;
    }
    printf("NÃO");
    printf("\n");
    return 0;
}
