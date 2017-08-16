#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct _item
{
	int valor;
	struct _item* prox;
	struct _item* ant;
} Item;


typedef struct _list
{
	Item* inicio;
	Item* fim;
	int tamanho;
} Lista;



Lista* novaLista()
{
	Lista* l = (Lista*) malloc(sizeof(Lista));
	l->inicio = NULL;
	l->fim    = NULL;
	l->tamanho = 0;
	
	return l;
}

Item* novoItem(int value)
{
	Item *i = (Item*) malloc(sizeof(Item));
	i->valor = value;
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

Item* removerInicio(Lista* l)
{
	assert(l->tamanho > 0);
	
	Item* removed = NULL;
	
	if (l->tamanho == 1)
	{
		removed = l->inicio;
		l->inicio = NULL;
		l->fim = NULL;
	} else {
		removed = l->inicio;
		l->inicio = removed->prox;
		
		l->inicio->ant = NULL;
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
			fprintf(stdout, "%d", curr->valor); 
			curr = curr->prox;
		}
		fprintf(stdout, "%d", curr->valor); 
		fprintf(stdout, "\n");
	}
}


void freeLista(Lista* l)
{
	while (l->inicio != NULL)
		free(removerInicio(l));
}

Lista* strParaLista(char* str)
{
	Lista* nova = novaLista();
	
	for(int i = 0; str[i] != '\0'; i++)
		inserirFim(nova, novoItem(str[i]));	
		
	return nova;
}

int strcmplist(Lista* a, Lista* b)
{	
	Item* aptr = a->inicio;
	Item* bptr = b->inicio;
	
	while (aptr != NULL && bptr != NULL)
	{
		int diff = aptr->valor - bptr->valor;
		if (diff != 0)
			return diff;
		aptr = aptr->prox;
		bptr = bptr->prox;
	}
	
	if (aptr == NULL && bptr == NULL)
		return 0;
	else if (aptr != NULL && bptr == NULL)
		return aptr->valor;
	else if (bptr != NULL && aptr == NULL)
		return -bptr->valor;
	
	return -1;
}


int main()
{
	char strA[200];
	char strB[200];
	
	scanf("%s", strA);
	scanf("%s", strB);
	
	Lista* a = strParaLista(strA);
	Lista* b = strParaLista(strB);
	
//	printLista(a);
//	printLista(b);
	
	printf("%d\n", strcmp(strA, strB));
	printf("%d\n", strcmplist(a, b));

// SAIDA PARA O HACKERRANK
/*
	int resp = strcmplist(a, b);
	if (resp < 0)
		printf("A menor que B\n");
	else if (resp > 0)
		printf("A maior que B\n");
	else
		printf("A igual a B\n");
*/
}
