#define CAPACIDADE 10

#include <assert.h>
#include <stdlib.h>  
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "lista/qlist.h"


typedef struct _Matriz_Interface
{
	Lista* rows[CAPACIDADE];
	Lista* cols[CAPACIDADE];
} Matriz;


Matriz* new_matrix()
{
	Matriz* m = (Matriz*) malloc(sizeof(Matriz));
	for (int i = 0; i < CAPACIDADE; ++i)
	{
		m->rows[i] = novaLista();
		m->cols[i] = novaLista();
	}
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
	{	

	}
	
	return 1;
}


float get(Matriz* m, long i, long j)
{
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

bool indicesPermitidos(int i, int j)
{
	if (i < 0 || i >= CAPACIDADE || j < 0 || j >= CAPACIDADE) {
		printf("Índices (%d %d) fora das dimensões da matriz.\n", i, j);
		return false;
	}
	return true;
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


int main()
{

	Matriz* m = new_matrix();	
	
	char cmd[30];
	int i;
	int j;
	float v;

	do
	{
		printf("> ");
		scanf("%s", cmd);
		
		if (strcmp(cmd, "put") == 0)
		{
			scanf("%d %d %f", &i, &j, &v);
			if (indicesPermitidos(i,j)) {
				put(m, i, j, v);
				printf("\rM[%d][%d] = %.1f\n", i, j, v);
			}
		} else if (strcmp(cmd, "get") == 0) 
		{
			scanf("%d %d", &i, &j);
			if (indicesPermitidos(i,j)) {
				v = get(m, i, j);
				printf("\r%.1f\n", v);
			}
		} else if (strcmp(cmd, "add_to_col") == 0)
		{
			scanf("%d %f", &j, &v);
			if (indicesPermitidos(0,j)) {
				add_to_col(m, j, v);
			}
		}  else if (strcmp(cmd, "add_to_row") == 0)
		{
			scanf("%d %f", &i, &v);
			if (indicesPermitidos(i,0)) {
				add_to_row(m, i, v);
			}
		} else if (strcmp(cmd, "print_col") == 0) {
			scanf("%d", &j);
			if (indicesPermitidos(0,j))
				print_col(m, j);
		} else if (strcmp(cmd, "print_row") == 0) {
			scanf("%d", &i);
			if (indicesPermitidos(i, 0))
				print_row(m, i);
		} else if (strcmp(cmd, "print") == 0) {
			print_matrix(m);
		}		
		
	} while (strcmp(cmd, "exit") != 0);
	
	freeMatriz(m);
	
	return 1;
}
