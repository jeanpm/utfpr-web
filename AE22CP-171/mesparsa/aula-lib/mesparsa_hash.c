#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

#include "../lista/list.h"


#define MSIZE 10e7

#include "mesparsa.h"


struct _Matriz_Interface
{
	Lista* tabela_hash[CAPACIDADE];
};

Matriz* new_matrix()
{
	Matriz* m = (Matriz*) malloc(sizeof(Matriz));
	for (int i = 0; i < CAPACIDADE; i ++)
	{
		m->tabela_hash[i] = novaLista();
	}
	printf("Utilizando tabelas hash\n");
	return m;
}

int h(long i, long j)
{
	return (long)(MSIZE * i + j) % CAPACIDADE;
} 


float get(Matriz* m, long i, long j)
{
	int hash_ra = h(i, j);
	
	Item* curr = m->tabela_hash[hash_ra]->inicio;
	
	while (curr != NULL) {
		if (curr->i == i && curr->j == j ) 
			return curr->valor;
		curr = curr->prox;		
	}
	return 0.0;
}


// Tratamento de colisões por encadeamento.
// Elementos com chaves repetidas não são inseridos.
int put(Matriz* m, long i, long j, float valor)
{
	int hash_ra = h(i, j);
	
	Item* curr = m->tabela_hash[hash_ra]->inicio; 
	
	while (curr != NULL) {
		if (curr->i == i && curr->j == j ) 
			curr->valor = valor;
		curr = curr->prox;		
	}
	
	inserirInicio(m->tabela_hash[hash_ra], novoItem(i, j, valor));
		
	return 1;
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
		freeLista(m->tabela_hash[i]);
		free(m->tabela_hash[i]);
	}
}


void print_row(Matriz* m, long i)
{
	for (long j = 0; j< CAPACIDADE; j++)
	{
		float valor = get(m, i, j);
		if (valor > 0)
			printf("(%ld,%ld,%.1f), ", i, j, valor); 
	}	
}

void print_col(Matriz* m, long j)
{
	for (long i = 0; i< CAPACIDADE; i++)
	{
		float valor = get(m, i, j);
		if (valor > 0)
			printf("(%ld,%ld,%.1f), ", i, j, valor); 
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

