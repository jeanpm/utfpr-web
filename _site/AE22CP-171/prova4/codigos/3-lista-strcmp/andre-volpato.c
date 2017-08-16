#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#define MAX 100


typedef struct _Item Item;
typedef struct _Lista Lista;

struct _Item
{
	int n;
	struct _Item* prox;
	struct _Item* ant;
};


struct _Lista
{
	Item* inicio;
	Item* fim;
	int tamanho;
};

Lista* novaLista()
{
	Lista* l = (Lista*) malloc(sizeof(Lista));
	l->inicio = NULL;
	l->fim    = NULL;
	l->tamanho = 0;

	return l;
}

Item* novoItem(int n)
{
	Item *i = (Item*) malloc(sizeof(Item));
	i->n = n;
	i->prox  = NULL;
	i->ant  = NULL;
	return i;
}

void inserirInicio(Lista* l, Item* novo)
{
	// Se lista vazia
	if (l->inicio == NULL) {
		l->inicio = novo;
		l->fim = l->inicio;
	} else {
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
	if (l->fim == NULL) {
		inserirInicio(l, novo);
	} else {
		l->fim->prox = novo;
		novo->ant = l->fim;
		l->fim = novo;
		l->fim->prox = NULL;

		l->tamanho++;
	}
}

Item* removerFim(Lista* l)
{
	assert(l->tamanho > 0);

	Item* removed = NULL;

	if (l->tamanho == 1)
	{
		removed = l->fim;
		l->fim = NULL;
		l->inicio = NULL;
	} else {
		removed = l->fim;
		l->fim = removed->ant;

		l->fim->prox = NULL;
	}
	l->tamanho--;

	return removed;
}


void printLista(Lista* l)
{
    if (l->inicio != NULL)
    {
        Item* curr = l->inicio;

        while(curr != l->fim)
        {
            fprintf(stdout, "%c", curr->n);
            curr = curr->prox;
        }
            fprintf(stdout, "%c\n", curr->n);
    }
}

Lista* tolist(const char* st)
{
    Lista *l = novaLista();
    int i,x;
    for(i=0 ; st[i]!='\0' ; i++)
    {
        x = (int) (st[i]-'0');
        inserirFim(l,novoItem(x));
    }
    return l;
}

int strcmplist(Lista *A ,Lista *B)
{

    Item *aux=A->inicio;
    Item *aux2=B->inicio;
    int cont=0;

    if(A->tamanho > B->tamanho)
    {
        cont = 1;
    }
    else if(A->tamanho < B->tamanho)
    {
        cont = -1;
    }
    else if(A->tamanho == B->tamanho)
    {
        for(int i=0 ; i<A->tamanho ; i++)
        {
            if(aux->n > aux2->n)
            {
                //printf("A maior que B");
                cont = 1;
            }
            else if(aux->n < aux2->n)
            {
                //printf("A menor que B");
                cont = -1;
            }
            else if(aux->n == aux2->n)
            {
                cont = 0;
            }
            aux=aux->prox;
            aux2=aux2->prox;
        }
    }

    return cont;
}

int main()
{
    char* A = (char *)malloc(512000 * sizeof(char));
    char* B = (char *)malloc(512000 * sizeof(char));
    scanf("%s %s", A, B);

    Lista *C=tolist(A);
    Lista *D=tolist(B);
    int i = strcmplist(C,D);

    if(i < 0)
    {
        printf("A menor que B");
    }
    else if(i == 0)
    {
        printf("A igual a B");
    }
    else if(i > 0)
    {
        printf("A maior que B");
    }
}

