//
//  main.c
//  uniaofinal
//
//  Created by Luan Lamarca on 05/07/17.
//  Copyright © 2017 Luan Lamarca. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
    
#define CAPACIDADE 1021
    
//listas//
//=======================================================================//
//construtores//
typedef struct _Item Item;
typedef struct _Lista Lista;
struct _Item
{
    long valor;
    Item* prox;
    Item* ant;
};
struct _Lista
{
    Item* inicio;
    Item* fim;
    int tamanho;
};
    
typedef struct
{
    Lista* tabela_hash[CAPACIDADE];
}Set;
    
//Operacoes de lista//
Lista* novaLista()
{
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->inicio = NULL;
    l->fim	= NULL;
    l->tamanho = 0;
    return l;
}
Item* novoItem(int value)
{
    Item *item = (Item*) malloc(sizeof(Item));
    item->valor = value;
    item->prox  = NULL;
    item->ant  = NULL;
    return item;
}
    
void inserirInicio(Lista* l, Item* novo)
{
    // Se lista vazia
    if (l->inicio == NULL)
    {
        l->inicio = novo;
        l->fim = l->inicio;
    }
    else
    {
        l->inicio->ant = novo;
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    l->tamanho++;
}
void inserirProximo(Lista* l, Item* atual, Item* novo)
{
    assert(atual->prox != NULL);
    novo->prox = atual->prox;
    novo->ant = atual;
    atual->prox->ant = novo;
    atual->prox = novo;
    l->tamanho++;
}
void inserirFim(Lista* l, Item* novo)
{
    // Se lista vazia
    if (l->fim == NULL)
    {
        inserirInicio(l, novo);
    }
    else
    {
        l->fim->prox = novo;
        novo->ant = l->fim;
        l->fim = novo;
        l->fim->prox = NULL;
        l->tamanho++;
    }
}
void printlista (Set *l, Set *f)
{
    Item *p;
    Item *h;
    
    for(p = l->tabela_hash[0]; p!= NULL; p=p->prox)
    {
        for(h = l->tabela_hash[0]; h!=NULL; h=h->prox)
        {
            if(p->valor == h->valor)
            {
                printf("=> %ld ", p->valor);
            }
        }
    }
}
    
    //=======================================================================//
    
    //hash//
int h(long key)
{
    return key % CAPACIDADE;
}
int buscaLista(Lista* l, long elem)
{
    if (!l)
    {
        return 1;
    }
    
    Item* tmp = l->inicio;
    
    while (tmp)
    {
        if (tmp->valor == elem){
            return -1;
        }
        tmp=tmp->prox;
    }
    
    return 1;
}
    
int inserir(Set *s, long elemento)
{
    int hash_elem = h(elemento);
    int repete = 0;
    
    if (!s->tabela_hash[hash_elem])
    {
        s->tabela_hash[hash_elem] = novaLista();
    }
    if ((repete = buscaLista(s->tabela_hash[hash_elem], elemento)) == 1)
    {
        Item* novo = novoItem(elemento);
        inserirInicio(s->tabela_hash[hash_elem], novo);
    }
    return -1;
}
void transferirLista(Lista* l, Set* dest)
{
    if (l->inicio != NULL)
    {
        Item* curr = l->inicio;
        while(curr != l->fim)
        {
            inserir(dest, curr->valor);
            curr = curr->prox;
        }
        inserir(dest, curr->valor);
    }
}
    
Set* uniao(Set* A, Set* B)
{
    int i;
    Set* result = (Set*)malloc(sizeof(Set));
    
    for (i=0; i<CAPACIDADE; i++){
        if (A->tabela_hash[i])
        {
            transferirLista(A->tabela_hash[i], result);
        }
    }
    
    for (i=0; i<CAPACIDADE; i++)
    {
        if (B->tabela_hash[i])
        {
            transferirLista(B->tabela_hash[i], result);
        }
    }
        
    return result;
}
/*void imprime_lista (Set *l, Set *f)
{
    Item *p;
    Item *h;
    while(p->prox != NULL)
    {
        printf("=> %d ", p->conteudo);
        p = p->prox;
        
    }
    printf("=> %d\n", p->conteudo);
}*/
int main(void)
{
    int n;
    scanf("%d", &n);
    Set* s = (Set*)malloc(sizeof(Set));
    Set* s2 = (Set*)malloc(sizeof(Set));
    
    int i;
    long elem;
    for (i=0; i<n; i++)
    {
        scanf ("%ld",&elem);
        inserir(s, elem);
    }
    
    scanf("%d", &n);
    
    for (i=0; i<n; i++)
    {
        scanf ("%ld",&elem);
        inserir(s2, elem);
    }
    
    Set* resultado = uniao(s, s2);
    
    printlista(s, s2);
    printf("\n");
    return 0;
}

