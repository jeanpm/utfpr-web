#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

#include "list.h"





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

void atualizarCircularidade(Lista* l)
{
	l->inicio->ant = l->fim;
	l->fim->prox = l->inicio;
}

/*
Item* ponteiroParaPosicao(Lista* l, int pos)
{
	Item* curr = l->inicio;
	for (int i = 0; i < pos - 1; ++i)
		curr = curr->prox;
	return curr;
}
*/

Item* ponteiroParaPosicao(Lista* l, int pos)
{
	Item* curr = NULL;
	
	if (pos < l->tamanho/2) {
		curr = l->inicio;
		for (int i = 0; i < pos - 1; ++i)
			curr = curr->prox;
	} else {
		curr = l->fim;
		for (int i = l->tamanho; i > pos; --i)
			curr = curr->ant;
	}
	
	return curr;
}

// =============================================================================

void inserirInicio(Lista* l, Item* novo)
{
	// Se lista vazia
	if (l->inicio == NULL) {
		l->inicio = novo;
		l->fim = l->inicio;
		
		// Parte especifica da lista circular
		atualizarCircularidade(l);
	} else {
		l->inicio->ant = novo;
		novo->prox = l->inicio;
		l->inicio = novo;
		
		// Parte especifica da lista circular
		atualizarCircularidade(l);
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
		
		// Parte especifica da lista circular
		atualizarCircularidade(l);		
	
		l->tamanho++;
	}
}



void inserirNaPosicao(Lista* l, Item* novo, int pos)
{	
	assert(pos >= 0 && pos <= l->tamanho);

	if (pos == 0)
		inserirInicio(l, novo);
	else if (pos == l->tamanho)
		inserirFim(l, novo);
	else {
		Item* curr = ponteiroParaPosicao(l, pos);
		inserirProximo(l, curr, novo);
	}	
}

// =============================================================================


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
		
		// Parte especifica da lista circular
		atualizarCircularidade(l);
	}
	l->tamanho--;
	
	
	return removed;
}

Item* removerProximo(Lista* l, Item* anterior)
{
	assert(anterior->prox->prox != NULL);
	
	Item* removed = anterior->prox;
	removed->prox->ant = anterior;
	anterior->prox = removed->prox;
	
	l->tamanho--;
	
	return removed;
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
		
		// Parte especifica da lista circular
		atualizarCircularidade(l);		
	}
	l->tamanho--;
	
	return removed;
}

void removerItem(Lista* lista, Item* i)
{
	if (i == lista->inicio)
		removerInicio(lista);
	else if (i == lista->fim)
		removerFim(lista);
	else {
		// Se não é início nem fim, o item possui antecessor e sucessor.
		// Então basta atualizar os ponteiros, removendo-o da lista.
		i->ant->prox = i->prox;
		i->prox->ant = i->ant;
		
		lista->tamanho--;
	} 
}

Item* removerDaPosicao(Lista* l, int pos)
{
	assert(pos >= 0 && pos < l->tamanho);	
	
	Item* removed = NULL;
	
			
	if (pos == 0) {
		removed = removerInicio(l);		
	} else if (pos == l->tamanho-1) {
		removed = removerFim(l);	
	} else {
		Item* curr = ponteiroParaPosicao(l, pos);
		removed = removerProximo(l, curr);
	}
	
	return removed;
}

// =============================================================================


void printLista(Lista* l)
{
	Item* curr = l->inicio;
	while(curr != l->fim)
	{
		fprintf(stderr, "%d\t", curr->valor); 
		curr = curr->prox;
	}
	fprintf(stderr, "\n");
}



void reverterLista(Lista* lista)
{
	assert(lista->fim != NULL);
	
	Item* curr = lista->fim;
	
	// Se existe anterior, então a lista tem ao menos dois elementos.
	while(curr != lista->inicio)
	{
		Item* anterior = curr->ant;
		removerItem(lista, anterior);
		inserirFim(lista, anterior);
	}
}

// =============================================================================

void freeLista(Lista* l)
{
	while (l->inicio != NULL)
		free(removerDaPosicao(l, 0));
}

