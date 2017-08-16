#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define CAPACIDADE 1021

//TABELA HASH COM TRATAMENDO DE COLISÕES POR TESTE LINEAR

typedef struct celula
{
    	long conteudo;
   
    	struct celula* prox;
    	struct celula* ant;

}celula;

typedef struct lista
{
	celula* inicio;
    	celula* fim;
    	int cont;
}lista;

lista *inicializa()
{
	lista* l = (lista*) malloc(sizeof(lista));

	l->inicio = NULL;
	l->fim = NULL;
	l->cont = 0;
	
	return l;
}

celula *cria(long conteudo)			
{
	celula *p = (celula*)malloc(sizeof(celula));
	p->conteudo = conteudo;
	
	p->prox = NULL;
	p->ant = NULL;
	return p;
}

int HASH(long conteudo)
{
	return conteudo % CAPACIDADE;
}

int REhash(int hash_conteudo)
{
	return (hash_conteudo + 1) % CAPACIDADE;
}

int insere_inicio(lista *l, long conteudo)
{
	if(l == NULL)
	{
		return 0;
	}

	celula *novo = cria(conteudo);

	novo->prox = l->inicio;
	novo->ant = NULL;
	l->inicio = novo;
	if(novo->prox != NULL)
	{
		novo->prox->ant = novo;
	}

	l->cont++;
	return 1;
}

void inserir_tabela(lista **tabela_hash, long conteudo)
{	
	int r = HASH(conteudo);
	int qtd = 0;

	celula *aux = cria(conteudo);

	while (tabela_hash[r]->inicio->conteudo != -1  && qtd < CAPACIDADE)
	{
		r = REhash(r);
		qtd++;
	}
	if (qtd < CAPACIDADE) 
	{
		tabela_hash[r]->inicio->conteudo = aux->conteudo;
	}
}

void imprime_hash(lista** tabela_hash, int N)
{
	int i=0;

	for (int i = 0; i < N; i++)
	{
		printf("%ld ", i, tabela_hash[i]->inicio->conteudo);
	}

	printf("\n");
}

// Misturou as implementações por teste linear e encadeadas
int main(void)
{
	int N, i, j;
	long conteudo;
	int repetida=0;
	i = j = 0;
	
    	scanf("%d",&N);  

	// A tabela hash deveria ter tamanho CAPACIDADE
	lista** tabela_hash = (lista**) malloc(N*sizeof(lista*));

	for (i = 0; i < N; i++)
	{
		tabela_hash[i] = inicializa();
		insere_inicio(tabela_hash[i], -1);
	}
	i=0;
	
	// Percorrer toda a tabela procurando por repetições não faz sentido em
	// uma tabela hash
	for(i = 0;i < N; i++)               
    	{ 
		scanf("%ld",&conteudo); 
 		for(j = 0;j < N; j++)               
    		{ 
			if(tabela_hash[j]->inicio->conteudo == conteudo)
			{
				repetida = 1;
			}
			else
			{
				repetida=0;
			}
		}
        	if(repetida == 0)
		{

        		inserir_tabela(tabela_hash, conteudo); 
		}
    	}

    	imprime_hash(tabela_hash,N);
	
	return 0;
}

