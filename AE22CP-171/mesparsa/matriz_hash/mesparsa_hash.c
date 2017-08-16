#include <stdio.h>

#include "lista/list.h"

#define CAPACIDADE 17

#define MSIZE 10e7


int h(long i, long j)
{
	return (long)(MSIZE * i + j) % CAPACIDADE;
} 


float get(Lista* tabela_hash[], long i, long j)
{
	int hash_ra = h(i, j);
	
	Item* curr = tabela_hash[hash_ra]->inicio;
	
	while (curr != NULL) {
		if (curr->i == i && curr->j == j ) 
			return curr->valor;
		curr = curr->prox;		
	}
	return 0.0;
}


// Tratamento de colisões por encadeamento.
// Elementos com chaves repetidas não são inseridos.
int inserir(Lista* tabela_hash[], long i, long j, float valor)
{
	int hash_ra = h(i, j);
	
	Item* curr = tabela_hash[hash_ra]->inicio; 
	
	while (curr != NULL) {
		if (curr->i == i && curr->j == j ) return -1;
		curr = curr->prox;		
	}
	
	inserirInicio(tabela_hash[hash_ra], novoItem(i, j, valor));
		
	return 1;
}

int main()
{

	Lista* tabela_hash[CAPACIDADE];
	
	for (int i = 0; i < CAPACIDADE; i++)
	{
		tabela_hash[i] = novaLista();
	}
	

	inserir(tabela_hash, 23432, 9999999, 5.8);
	inserir(tabela_hash, 12,1111111, 3.8);
	inserir(tabela_hash, 1,9999999, 1.7);
	inserir(tabela_hash, 9999,9999999, 9.5);
	inserir(tabela_hash, 9999,9999999, 5.3);
	

	for (int i = 0; i < CAPACIDADE; i++)
	{
		printf("%d:", i);
		printLista(tabela_hash[i]);
	}
}
