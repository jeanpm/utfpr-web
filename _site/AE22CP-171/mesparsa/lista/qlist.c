#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

#include "qlist.h"


Lista* novaLista()
{
	Lista* l = (Lista*) malloc(sizeof(Lista));
	l->inicio = NULL;
	l->fim    = NULL;
	l->tamanho = 0;
	
	return l;
}

Item* novoItem(long i, long j, float value)
{
	Item *item = (Item*) malloc(sizeof(Item));
	item->valor = value;
	item->prox  = NULL;
	item->ant  = NULL;
	item->acima = NULL;
	item->abaixo = NULL;	
	item->i = i;
	item->j = j;
	return item;
}


void inserirInicioLinha(Lista* row, Item* novo)
{
	// Se lista vazia
	if (row->inicio == NULL) {
		row->inicio = novo;
		row->fim = row->inicio;
	} else {
		row->inicio->ant = novo;
		novo->prox = row->inicio;
		row->inicio = novo;
	}
	row->tamanho++;
}

void inserirInicioColuna(Lista* col, Item* novo)
{
	// Se lista vazia
	if (col->inicio == NULL) {
		col->inicio = novo;
		col->fim = col->inicio;
	} else {
		col->inicio->acima = novo;
		novo->abaixo = col->inicio;
		col->inicio = novo;
	}
	col->tamanho++;
}

void inserirProximoLinha(Lista* row, Item* atual, Item* novo)
{
	assert(atual->prox != NULL);

	novo->prox = atual->prox;
	novo->ant = atual;

	atual->prox->ant = novo;
	atual->prox = novo;
		
	row->tamanho++;
}

void inserirProximoColuna(Lista* col, Item* atual, Item* novo)
{
	assert(atual->abaixo != NULL);

	novo->abaixo = atual->abaixo;
	novo->acima = atual;

	atual->abaixo->acima = novo;
	atual->abaixo = novo;
		
	col->tamanho++;
}


void inserirFimLinha(Lista* row, Item* novo)
{
	// Se lista vazia
	if (row->fim == NULL) {
		inserirInicioLinha(row, novo);
	} else {
		row->fim->prox = novo;
		novo->ant = row->fim;
		row->fim = novo;
		row->fim->prox = NULL;
	
		row->tamanho++;
	}
}


void inserirFimColuna(Lista* col, Item* novo)
{
	// Se lista vazia
	if (col->fim == NULL) {
		inserirInicioColuna(col, novo);
	} else {
		col->fim->abaixo = novo;
		novo->acima = col->fim;
		col->fim = novo;
		col->fim->abaixo = NULL;
	
		col->tamanho++;
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


void freeLista(Lista* l)
{
	while (l->inicio != NULL)
		free(removerInicio(l));
}



