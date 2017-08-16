#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define CAPACIDADE 1021

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
} Set;

//Operacoes de lista//
Lista* novaLista()
{
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->inicio = NULL;
    l->fim    = NULL;
    l->tamanho = 0;

    return (l);
}

Item* novoItem(int value)
{
    Item *item = (Item*) malloc(sizeof(Item));
    item->valor = value;
    item->prox  = NULL;
    item->ant  = NULL;
    return (item);
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

void printLista(Lista* l)
{
    if (l->inicio != NULL)
    {
        Item* curr = l->inicio;
        while(curr != l->fim)
        {
            fprintf(stdout, "%ld ", curr->valor);
            curr = curr->prox;
        }

        fprintf(stdout, "%ld ",curr->valor);

    }
}

int h(long key)
{
    return key % CAPACIDADE;
}

int buscaLista(Lista* l, long elem)
{
    if (!l)
    {
        return (1);
    }

    Item* tmp = l->inicio;

    while (tmp)
    {
        if (tmp->valor == elem)
        {
            return (-1);
        }

        tmp=tmp->prox;

    }

    return (1);
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

    return (-1);
}


Set* intersecao(Set* a, Set* b)
{
    int i;
    Set* s2 = (Set*)malloc(sizeof(Set));
    for (i=0; i<CAPACIDADE; i++)
    {
        if(a->tabela_hash[i] == b->tabela_hash[i])
        {
         inserir(s2, a->tabela_hash[i]);
        }
    }
    return(s2);
}

int main()
{
    Set* s0 = (Set*)malloc(sizeof(Set));
    Set* s1 = (Set*)malloc(sizeof(Set));
    Set* s2 = (Set*)malloc(sizeof(Set));
    int b,a,i;
    a = b = i = 0;
    long elem;
    scanf ("%d",&a);
    for (i=0; i<a; i++)
    {
        scanf ("%ld",&elem);
        inserir(s0, elem);
    }
    scanf ("%d",&b);
    for (i=0; i<b; i++)
    {
        scanf ("%ld",&elem);
        inserir(s1, elem);
    }
    s2 = intersecao(s0,s1);
    for (i=0; i<CAPACIDADE; i++)
    {
        if (s2->tabela_hash[i])
        {
            printLista(s2->tabela_hash[i]);
        }
    }

    return(0);
}

