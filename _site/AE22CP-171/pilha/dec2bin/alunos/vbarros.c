#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct item{
    char string;
    struct item* prox;
    struct item* anterior;
}item;

typedef struct pilha{
    int quant;
    struct item* bgn;
    struct item* end;
}pilha;

pilha* criapilha()
{
	pilha* l = (pilha*) malloc(sizeof(pilha));
	l->bgn = NULL;
	l->end = NULL;
	l->quant = 0;

	return l;
}

item* criaitem(const char c)
{
	item *i = (item*) malloc(sizeof(item));
	i->string=c;
	i->prox  = NULL;
	i->anterior  = NULL;
	return i;
}

void push(pilha *l, item* novo)
{
	// Se lista vazia
	if (l->end == NULL)
	{
		l->bgn = novo;
		l->end = l->bgn;
		l->quant++;
    }
	else
	{
		l->end->prox = novo;
		novo->anterior = l->end;
		l->end = novo;
		l->end->prox = NULL;
		l->quant++;
	}
}

item* pop(pilha* l)
{
	assert(l->quant > 0);

	item* removed = NULL;

	if (l->quant == 1)
	{
		removed = l->end;
		l->end = NULL;
		l->end = NULL;
	} else {
		removed = l->end;
		l->end = removed->anterior;

		l->end->prox = NULL;
	}
	l->quant--;
    removed->prox=NULL;
	removed->anterior=NULL;

	return removed;
}

item* removerbgn(pilha* l)
{
	assert(l->quant > 0);

	item* removed = NULL;

	if (l->quant == 1)
	{
		removed = l->bgn;
		l->bgn = NULL;
		l->end = NULL;
	} else {
		removed = l->bgn;
		l->bgn = removed->prox;

		l->bgn->anterior = NULL;
	}
	l->quant--;
	removed->prox=NULL;
	removed->anterior=NULL;


	return removed;
}

void freeLista(pilha* l)
{
	while (l->bgn != NULL)
		free(removerbgn(l));
}

int main (void )
{
    pilha *p=criapilha();
    int n;
    scanf("%d", &n);
    while (n!=0)
    {
      push(p,n%2);
      n=n/2;
    }
    while (pop(p) !=NULL)
      printf("%ld",pop(p));

}

