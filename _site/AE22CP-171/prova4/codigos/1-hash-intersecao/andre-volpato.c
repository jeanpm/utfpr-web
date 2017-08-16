#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#define CAPACIDADE 1021

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

int h(int n)
{
	return n % 10;
}

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

void printLista(Lista* l)
{
    if (l->inicio != NULL)
    {
        Item* curr = l->inicio;

        while(curr != l->fim)
        {
            fprintf(stdout, "%d, ", curr->n);
            curr = curr->prox;
        }
            fprintf(stdout, "%d", curr->n);
    }
}

// Tratamento de colises por reespalhamento
// Teste linear ou endereamento aberto.
int inserir(Lista* tabela_hash[], int n)
{
	int hash_n = h(n);

	inserirFim(tabela_hash[hash_n],novoItem(n));

	return -1;
}

int main()
{
    Lista* tabela_hash[CAPACIDADE];

	for (int i = 0; i < CAPACIDADE; i++)
	{
		tabela_hash[i] = novaLista();
	}

}

