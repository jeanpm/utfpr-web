#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CAPACIDADE 1021

typedef struct Z
{
	long elemento;
	struct Z *prox;
	struct Z *ant;
}Az;

typedef struct ListaDin
{
    Az* inicio;
    Az *fim;
    int quant;
}LD;

typedef struct{
	LD *tabela_hash[CAPACIDADE];
}set;

LD* NovaLista()
{
	LD* L = (LD*) malloc(sizeof(LD));
	L->inicio = NULL;
	L->fim    = NULL;
	L->quant = 0;

	return L;
}
int vazia(LD *L)
{
	if(L->inicio==NULL)
		return 1;
	else
		return 0;
}
void inicia(LD *L)
{
	L->inicio=NULL;
	L->fim=NULL;
	L->quant=0;
}
Az *Novono(long elemento)
{
	Az*Novo =(Az*)malloc(sizeof(Az));
	Novo->prox=NULL;
	Novo->ant=NULL;
	Novo->elemento=elemento;
	return Novo;
}
void InserirInicio(LD *L, Az *Novo)
{
	if(vazia(L))
	{
		L->inicio=Novo;
		L->fim=Novo;
	}
	else
	{
		Novo->prox= L->inicio;
		L->inicio->ant=Novo;
		L->inicio = Novo;
	}
	L->quant++;
}
void inserirFim(LD *L,Az *Novo)
{
	if(vazia(L))
    {
		InserirInicio(L,Novo);
    }
	else
	{
		L->fim->prox=Novo;
		Novo->ant = L->fim;
		L->fim = Novo;
		L->quant++;
	}
}
int Y(long key)
{
	return key % CAPACIDADE;
}
int colisao(set *s, long ra,int hash_ra)
{
	Az *aux = s->tabela_hash[hash_ra]->inicio;

	while(aux->prox!=NULL)
	{
		if(aux->elemento==ra)
        {
		  return 1;
        }
	}
	return 0;
}
int inserir(set *s,long int ra)
{
	int hash_ra = Y(ra);

	Az* i = Novono(ra);

	if(vazia(s->tabela_hash[hash_ra]))
    {
		InserirInicio(s->tabela_hash[hash_ra],i);
    }
    else
    {
		if(colisao(s,ra,hash_ra))
        {
			InserirInicio(s->tabela_hash[hash_ra],i);
        }
    }
	return -1;
}
void exibe(LD *L)
{
	Az *e = L->inicio;

	while(e != NULL)
    {
		printf("%ld",e->elemento);
		e =e->prox;
	}
}

set* intersecao(set* A, set* B)
{
    int i;
    set* s = (set*)malloc(sizeof(set));
    for (i=0; i<CAPACIDADE; i++)
    {
        if(A->tabela_hash[i]==B->tabela_hash[i])
        {
            inserir(s, A->tabela_hash[i]);
        }
    }
    return(s);
}
int main(void)
{
	int N;
	set* A = (set*) malloc(sizeof(set));

	for (int i = 0; i < CAPACIDADE; i++)
	{
		A->tabela_hash[i] = NovaLista();
	}
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		long x;
		scanf("%ld",&x);
		inserir(A, x);
	}
	set* B = (set*) malloc(sizeof(set));

	for (int i = 0; i < CAPACIDADE; i++)
	{
		B->tabela_hash[i] = NovaLista();
	}
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		long x;
		scanf("%ld",&x);
		inserir(B, x);
	}
	set* AB = (set*) malloc(sizeof(set));

	for (int i = 0; i < CAPACIDADE; i++)
	{
		AB->tabela_hash[i] = NovaLista();
	}
	intersecao(A,B);

	for (int i = 0; i < CAPACIDADE; i++)
	{
		exibe(AB->tabela_hash[i]);
	}
	return(0);
}
