#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACIDADE 1021

/*typedef struct aluno
{
	long matricula;
	char nome[100];

	struct aluno* prox;
	struct aluno* ant;
} Aluno;*/
typedef struct Item
{
	long numero;
	struct Item* prox;
	struct Item* ant;
}Item;

typedef struct Lista
{
	Item* inicio;
	Item* fim;
	int tamanho;
} Lista;


typedef struct 
{
	Lista* tabela_hash[CAPACIDADE];
} Set;


Item* novoItem(long value)
{
	Item *x = malloc(sizeof(Item));
	x->numero = value;
	x->prox = NULL;
	x->ant = NULL;

	return (x);
}

Lista* novaLista()
{
	Lista* l = malloc(sizeof(Lista));
	l->inicio = NULL;
	l->fim = NULL;
	l->tamanho = 0;

	return (l);
}

void inserirInicio(Lista* l, Item* novo)
{
	// Se lista vazia
	if (l->inicio == NULL)
	{
		l->inicio = novo;
		l->fim = l->inicio;
	}
	else
	{
		l->inicio->ant = novo;
		novo->prox = l->inicio;
		l->inicio = novo;
	}
	l->tamanho++;
}

void inserirFim(Lista* l, Item* novo)
{
	// Se lista vazia
	if (l->fim == NULL)
	{
		inserirInicio(l, novo);
	}
	else
	{
		l->fim->prox = novo;
		novo->ant = l->fim;
		l->fim = novo;
		l->fim->prox = NULL;

		l->tamanho++;
	}
}

void printLista(Lista* l)
{
	Item* printado = l->inicio;
	while (printado != l->fim)
	{
		printf("%ld " , printado->numero);
		printado = printado->prox;
	}
	printf("%ld ", printado->numero);
}


//=====================================================================
int hash(long key)
{
	return key % CAPACIDADE;
}

void InserirNaTabelaHash(Lista** s , Item* j)
{
	int hash_item = hash(j->numero);
	Lista* x = s[hash_item];

	if(x->tamanho == 0)
	{
		inserirFim(x, j);
	}
	else
	{
		int aux;
		Item* w = x->inicio;
// x não é alterado
//		while(x!= NULL)
// CORREÇÃO
		while(w != NULL)
		{
			if(w->numero ==  j->numero)
			{
				return;
			}
			w = w->prox;
		}
		inserirInicio(x , j);
	}
}

Lista** uniao(Lista** A , Lista** B)
{
	Lista** NOVA = (Lista**) malloc(CAPACIDADE * sizeof(Lista*));
// Não inicializou as listas da tabela, segmentation fault
// CORREÇÃO
	
	for (int i=0 ; i<CAPACIDADE ; i++)
		NOVA[i] = novaLista();
	
	int i;

	for(i = 0 ; i < CAPACIDADE ; i++)
	{
		Lista* Aux = A[i];
		Item* q = Aux->inicio;
		while(q != NULL)
		{
			InserirNaTabelaHash(NOVA , q);
			q = q->prox;
		}

		Aux = B[i];
		q = Aux->inicio;
		while(q != NULL)
		{
			InserirNaTabelaHash(NOVA , q);
			q = q->prox;
		}
	}

	return (NOVA);
}

int main()
{
	int i;
    // Declaração da tabelaHash(turma) depois da declaracao do tamanho
    //Lista** thash = (Lista**) malloc(capacidade * sizeof(Lista*));
	Lista** TH = (Lista**) malloc(CAPACIDADE * sizeof(Lista*));
	Lista** TH2 = (Lista**) malloc(CAPACIDADE * sizeof(Lista*));
	Lista** TH3 = (Lista**) malloc(CAPACIDADE * sizeof(Lista*));
	for (i=0 ; i<CAPACIDADE ; i++)
	{
		TH[i] = novaLista();
		TH2[i] = novaLista();
	}


	//SET A
	int QtdeInsercao;
    scanf("%d", &QtdeInsercao);
	long elemento;
    for(i=1 ; i<=QtdeInsercao ; i++)
    {
        scanf("%ld", &elemento);
        Item* x = novoItem(elemento);
        InserirNaTabelaHash(TH , x);
    }
    for (i=0; i<CAPACIDADE ; i++)
	{
		if(TH[i]->tamanho > 0 )
		{
			printLista(TH[i]);
		}
	}
	printf("\n");

	//SET B
	QtdeInsercao = 0;
	elemento = 0;
    scanf("%d", &QtdeInsercao);
    for(i=1 ; i<=QtdeInsercao ; i++)
    {
        scanf("%ld", &elemento);
        Item* x = novoItem(elemento);
        InserirNaTabelaHash(TH2 , x);
    }
    for (i=0; i<CAPACIDADE ; i++)
	{
		if(TH2[i]->tamanho > 0 )
		{
// Imprimindo a tabela hash errada		
//			printLista(TH[i]);
// CORREÇÃO
			printLista(TH2[i]);
		}
	}
	printf("\n");


	//Apos a uniao
	TH3 = uniao(TH , TH2);
	for (i=0; i<CAPACIDADE ; i++)
	{
		if(TH3[i]->tamanho > 0 )
		{
			printLista(TH3[i]);
		}
	}

	return 0;
}
