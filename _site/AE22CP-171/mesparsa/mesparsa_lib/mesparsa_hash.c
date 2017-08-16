#include <assert.h>
#include <stdlib.h>  
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "lista/list.h"

#include "mesparsa.h"


#define MSIZE 100000

struct _Matriz_Interface
{
	Lista* thash[CAPACIDADE];
};

Matriz* new_matrix()
{
	Matriz* m = (Matriz*) malloc(sizeof(Matriz));
	for (int i = 0; i < CAPACIDADE; ++i)
	{
		m->thash[i] = novaLista();
	}
	printf("Matriz esparsa por tabela hash.\n");
	return m;
}

void print_row(Matriz* m, long i)
{
	printf("\r");
	for (long j = 0; j < CAPACIDADE; j++)
	{
		float valor = get(m, i, j);
		if (valor != 0.0)
			printf("(%ld,%ld,%.1f), ", i, j, valor);
	}
	printf("\n");
}

void print_col(Matriz* m, long j)
{
	printf("\r");
	for (long i = 0; i < CAPACIDADE; i++)
	{
		float valor = get(m, i, j);
		if (valor != 0.0)
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



long h(long i, long j)
{
	return (long)(MSIZE* i + j) % CAPACIDADE;
}

// Retornar 0.0 não existir elemento na tabela hash com chave (i,j)
// Retornar o valor caso exista
float get(Matriz* m, long i, long j)
{
	Lista** tabela_hash = m->thash;
	
	int hash_ra = h(i, j);
	
	Item* curr = tabela_hash[hash_ra]->inicio; 
	
	// Inserir somente elementos com chaves não repetidas.
	while (curr != NULL) {
		if (curr->i == i && curr->j ==j) 
			return curr->valor;
		curr = curr->prox;		
	}
	return 0.0;
}

// Tratamento de colisões por encadeamento.
// Elementos com chaves repetidas não são inseridos.
int put(Matriz* m, long i, long j, float valor)
{
	Lista** tabela_hash = m->thash;
	
	int hash_ra = h(i, j);
	
	Item* curr = tabela_hash[hash_ra]->inicio; 
	
	// Inserir somente elementos com chaves não repetidas.
	while (curr != NULL) {
		if (curr->i == i && curr->j ==j) {
			curr->valor = valor;
			return 1;
		}
		curr = curr->prox;		
	}
	
	inserirInicio(tabela_hash[hash_ra], novoItem(i,j,valor));
		
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
		freeLista(m->thash[i]);
	}
	free(m);
}
