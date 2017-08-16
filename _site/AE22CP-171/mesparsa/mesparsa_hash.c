#define MSIZE 1000000000

#define CAPACIDADE 10

#include <assert.h>
#include <stdlib.h>  
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "lista/list.h"

#include "mesparsa.h"


struct _Matriz_Interface
{
	Lista* thash[CAPACIDADE];
};


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
		freeLista(m->thash[i]);
	}
}


int main()
{

	Matriz m;
	
	for (int i = 0; i < CAPACIDADE; ++i)
	{
		m.thash[i] = novaLista();
	}
	
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
				put(&m, i, j, v);
				printf("\rM[%d][%d] = %.1f\n", i, j, v);
			}
		} else if (strcmp(cmd, "get") == 0) 
		{
			scanf("%d %d", &i, &j);
			if (indicesPermitidos(i,j)) {
				v = get(&m, i, j);
				printf("\r%.1f\n", v);
			}
		} else if (strcmp(cmd, "add_to_col") == 0)
		{
			scanf("%d %f", &j, &v);
			if (indicesPermitidos(0,j)) {
				add_to_col(&m, j, v);
			}
		}  else if (strcmp(cmd, "add_to_row") == 0)
		{
			scanf("%d %f", &i, &v);
			if (indicesPermitidos(i,0)) {
				add_to_row(&m, i, v);
			}
		} else if (strcmp(cmd, "print_col") == 0) {
			scanf("%d", &j);
			if (indicesPermitidos(0,j))
				print_col(&m, j);
		} else if (strcmp(cmd, "print_row") == 0) {
			scanf("%d", &i);
			if (indicesPermitidos(i, 0))
				print_row(&m, i);
		} else if (strcmp(cmd, "print") == 0) {
			print_matrix(&m);
		}		
		
	} while (strcmp(cmd, "exit") != 0);
	
	freeMatriz(&m);
	
	return 1;
}
