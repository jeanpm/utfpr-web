
#include <assert.h>
#define CAPACIDADE 10

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "../lista/qlist.h"

#include "mesparsa.h"

struct _Matriz_Interface
{
	Lista* rows[CAPACIDADE];
	Lista* cols[CAPACIDADE];
};

Matriz* new_matrix()
{
	Matriz* m = (Matriz*) malloc(sizeof(Matriz));
	for (int i = 0; i < CAPACIDADE; ++i)
	{
		m->rows[i] = novaLista();
		m->cols[i] = novaLista();
	}
		printf("Utilizando listas encadeadas\n");
	return m;
}

void print_row(Matriz* m, long i)
{
	Lista* l = m->rows[i];
	printf("\r%d: ", l->tamanho);
	Item* curr = l->inicio;
	while(curr != NULL)
	{
		printf("(%ld,%ld,%.1f), ", curr->i, curr->j, curr->valor); 
		curr = curr->prox;
	}
	printf("\n");
}

void print_col(Matriz* m, long j)
{
	Lista* l = m->cols[j];
	printf("\r%d: ", l->tamanho);
	Item* curr = l->inicio;
	while(curr != NULL)
	{
		printf("(%ld,%ld,%.1f), ", curr->i, curr->j, curr->valor); 
		curr = curr->abaixo;
	}
	printf("\n");
}

void print_matrix(Matriz* m)
{
	printf("\r%5s", "");
	for (int i = 0; i < CAPACIDADE; i++)
		printf("%5d", i);
	printf("\n");
	
	for (int i = 0; i < CAPACIDADE; i++)
	{
		printf("%5d", i);
		
		for (int j = 0; j < CAPACIDADE; j++)
		{
			float valor = get(m, i,j);
			if (valor == 0.0) printf("%5s", "-");
			else              printf("%5.1f", valor  );
		}
		printf("\n");
	}
}


// Se o item já existe, substituir seu valor
int put(Matriz* m, long i, long j, float valor)
{
	assert (i < CAPACIDADE && j < CAPACIDADE);
	
	Lista* row = m->rows[i];
	Lista* col = m->cols[j]; 

	Item* novo = novoItem(i, j, valor); 
	
	bool ROW_ESTA_VAZIA = (row->inicio == NULL);
	bool COL_ESTA_VAZIA = (col->inicio == NULL);
		
	if (ROW_ESTA_VAZIA) 
		inserirInicioLinha(row, novo);
	else 
	{	// Se não está vazia, encontre a posição de inserção
		// Ponteiros para percorrer as listas.
		Item* rptr = row->inicio; // row pointer
		
		// Encontra posição na coluna.
		while (rptr != NULL && rptr->j < j)
			rptr = rptr->prox;
		
		// Se os índices são iguais, o item já existe, basta atualizar.
		if (rptr == NULL) {
			inserirFimLinha(row, novo);
		} else if (rptr->j == j) {
			rptr->valor = valor;
		} else if (rptr == row->inicio) {
			inserirInicioLinha(row, novo);
		} else {// Senão o novo item é inserido antes de rptr.
			inserirProximoLinha(row, rptr->ant, novo); 
		}
	}
		
	if (COL_ESTA_VAZIA)
		inserirInicioColuna(col, novo);
	else
	{	// Se não está vazia, encontre a posição de inserção
		// Ponteiros para percorrer as listas.
		Item* cptr = col->inicio; // col pointer
	
		// Encontra posição na linha.
		while (cptr != NULL && cptr->i < i)
			cptr = cptr->abaixo;
		
		// Se os índices são iguais, o item já existe, basta atualizar.
		if (cptr == NULL) {
			inserirFimColuna(col, novo);
		} else if (cptr->i == i) {
			cptr->valor = valor;
		} else if (cptr == col->inicio) {
			inserirInicioColuna(col, novo);	
		} else {// Senão o novo item é inserido antes de rptr.
			inserirProximoColuna(col, cptr->acima, novo); 
		}

	}
	
	return 1;
}


// Se o item já existe, substituir seu valor
float get(Matriz* m, long i, long j)
{
	assert (i < CAPACIDADE && j < CAPACIDADE);
	
	Lista* row = m->rows[i];
	Lista* col = m->cols[j]; 

	bool ROW_ESTA_VAZIA = (row->inicio == NULL);
	bool COL_ESTA_VAZIA = (col->inicio == NULL);
		
	if (ROW_ESTA_VAZIA || COL_ESTA_VAZIA)
		return 0.0;
	else 
	{	// Se não está vazia, encontre a coluna j
		// Ponteiros para percorrer as listas.
		Item* rptr = row->inicio; // row pointer

		// Encontra posição na coluna.
		while (rptr != NULL && rptr->j < j)
			rptr = rptr->prox;
		
		// Se os índices são iguais, o item já existe, basta atualizar.
		if (rptr == NULL)
			return 0.0;
		else if (rptr->j == j) 
			return rptr->valor;		
	}
	
	return 0.0;
}


int add_to_col(Matriz* m, long col, float val)
{
	for (int i = 0; i < CAPACIDADE; i++)
		put(m, i, col, get(m, i, col) + val);
	return 1;
}

int add_to_row(Matriz* m, long row, float val)
{
	for (int j = 0; j < CAPACIDADE; j++)
		put(m, row, j, get(m, row, j) + val);
	return 1;
}



void freeMatriz(Matriz* m)
{
	for (int i = 0; i < CAPACIDADE; i++)
	{
		freeLista(m->rows[i]);
		free(m->rows[i]);
		free(m->cols[i]);
	}
}



