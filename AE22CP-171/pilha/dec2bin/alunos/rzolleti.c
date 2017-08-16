#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

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

Lista* novaLista()
{
	Lista* l = (Lista*) malloc(sizeof(Lista));
	l->inicio = NULL;
	l->fim    = NULL;
	l->tamanho = 0;
	
	return l;
}

Item* novoItem(long value)
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

void printLista(Lista* l)
{
	if (l->inicio != NULL)
	{
		Item* curr = l->fim;
		while(curr != l->inicio)
		{
			fprintf(stdout, "(%ld)", curr->valor); 
			curr = curr->ant;
		}
		fprintf(stdout, "(%ld)", curr->valor); 
	}
	printf("\n");
}

void decimalParaBinario(long num,Lista* p)
{
	while(num>0)
	{
		int a = num%2;
		Item* i = novoItem(a);
		inserirInicio(p,i);
		num=num/2;
	}
}

int main(void)
{
	Lista* p= novaLista();
	long x;
	scanf("%ld",&x);
	
	decimalParaBinario(x,p);
	
	printLista(p);
	
	return 0;
}
