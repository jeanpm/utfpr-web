#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE 1021

typedef struct notg
{
	long elemento;	
	struct notg *prox;
	struct notg *ant;
}no;

typedef struct lista_dinamica
{
    no* inicio;
    no *fim;
    int quant;
}LD;

typedef struct{
	LD *tabela_hash[CAPACIDADE];
}set;

LD* novaLista()
{
	LD* L = (LD*) malloc(sizeof(LD));
	L->inicio = NULL;
	L->fim    = NULL;
	L->quant = 0;
	
	return L;
}

int vazia(LD *L)
{
	if(L->inicio == NULL)
		return 1;
	else
		return 0;
}
void inicia(LD *L)
{
	L->inicio = NULL;
	L->fim = NULL;
	L->quant=0;
}
no *novoNo(long elemento)
{
	no*novo =(no*)malloc(sizeof(no));	
	novo->prox=NULL;
	novo->ant=NULL;
	novo->elemento=elemento;
	return novo;
}
void insereInicio(LD *L, no *novo)
{	
	if(vazia(L))
	{
		L->inicio=novo;
		L->fim=novo;
	}
	else
	{
		novo->prox= L->inicio;
		L->inicio->ant=novo;
		L->inicio = novo;
		
	}
	L->quant++;
}
void insereFim(LD *L,no *novo)
{
	if(vazia(L))
		insereInicio(L,novo);
	else
	{		
		L->fim->prox=novo;
		novo->ant = L->fim;
		L->fim = novo;
		L->quant++;
	}
}
int h(long key)
{
	return key % CAPACIDADE;
	
}
int verifica_colisao(set *s, long ra,int hash_ra)
{
	no *aux = s->tabela_hash[hash_ra]->inicio;
	
	while(aux->prox!=NULL)
	{
		if(aux->elemento==ra)
			return 1;
	}
	return 0;
	
}
// Tratamento de colisões por reespalhamento
// Teste linear ou endereçamento aberto.
int inserir(set *s, long ra)
{
	int hash_ra = h(ra);
	
	no* i = novoNo(ra);
	
	if(vazia(s->tabela_hash[hash_ra]))
		insereInicio(s->tabela_hash[hash_ra],i);
	else
		if(verifica_colisao(s,ra,hash_ra))
			insereInicio(s->tabela_hash[hash_ra],i);
		
	return -1;
}

/*
ACESSOs inválidos em 
	B->tabela_hash[CAPACIDADE]
	
void uniao(set*A,set*B,set *AB)
{
	for(int i;i<CAPACIDADE;i++)
	{
		if(!vazia(B->tabela_hash[CAPACIDADE]))
		{
			no *aux1=B->tabela_hash[CAPACIDADE]->inicio;
			while(aux1!=NULL)
			{
				inserir(AB,aux1->elemento);
				aux1=aux1->prox;
			}
		}
		if(!vazia(A->tabela_hash[CAPACIDADE]))
		{
		
			no *aux2=A->tabela_hash[CAPACIDADE]->inicio;
			
				while(aux2!=NULL)
				{
					inserir(AB,aux2->elemento);
					aux2=aux2->prox;
				}
		}
	}
}
*/

void uniao(set*A,set*B,set *AB)
{
	for(int i;i<CAPACIDADE;i++)
	{
		if(!vazia(B->tabela_hash[i]))
		{
			no *aux1=B->tabela_hash[i]->inicio;
			while(aux1!=NULL)
			{
				inserir(AB,aux1->elemento);
				aux1=aux1->prox;
			}
		}
		if(!vazia(A->tabela_hash[i]))
		{
		
			no *aux2=A->tabela_hash[i]->inicio;
			
				while(aux2!=NULL)
				{
					inserir(AB,aux2->elemento);
					aux2=aux2->prox;
				}
		}
	}
}

void exibe(LD *L)
{
	no *e = L->inicio;

	while( e != NULL){
		
		printf("%ld ",e->elemento);
		e =e->prox;
	}
}

int main()
{
	int N;
	set* A = (set*) malloc(sizeof(set));
	
	for (int i = 0; i < CAPACIDADE; i++)
	{
		A->tabela_hash[i] = novaLista();
	}
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		long x;
		scanf("%ld",&x);
		inserir(A, x);
	}
// termina o A	

	set* B = (set*) malloc(sizeof(set));
	
	for (int i = 0; i < CAPACIDADE; i++)
	{
		B->tabela_hash[i] = novaLista();
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
		AB->tabela_hash[i] = novaLista();
	}
	 uniao(A,B,AB);
		
	for (int i = 0; i < CAPACIDADE; i++)
	{
		exibe(AB->tabela_hash[i]);
	}
}


