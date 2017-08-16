#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAPACIDADE 1021

typedef struct Item{
	long elemento;
	struct Item *prox;
	struct Item *ant;
}Item;

typedef struct Lista{
	Item* inicio;
	Item* fim;
	int tamanho;
}Lista;

typedef struct{
	Lista *tabela_hash[CAPACIDADE];
}Set;

Item* novoItem(long elemento)
{
	Item *item = (Item*) malloc(sizeof(Item));
	item->elemento = elemento;
	item->prox = NULL;
	item->ant  = NULL;
	
	return item;
}

Lista* novaLista()
{
	Lista* l = (Lista*) malloc(sizeof(Lista));
	l->inicio = NULL;
	l->fim    = NULL;
	l->tamanho = 0;
	
	return l;
}
Set* novoSet(){
	Set *s;
	for (int i = 0; i < CAPACIDADE; i++)
	{
		s->tabela_hash[i] = novaLista();
	}
        return s;
}
void inserirInicio(Lista* l, Item* novo)
{
	// Se lista vazia
	if (l->inicio == NULL) {
		l->inicio = novo;
		l->fim = l->inicio;
	} else {
		l->inicio->ant = novo;
		novo->prox = l->inicio;
		l->inicio = novo;
	}
	l->tamanho++;
}
void inserirFim(Lista* l, Item* novo)
{
	// Se lista vazia
	if (l->fim == NULL) {
		inserirInicio(l, novo);
	} else {
		l->fim->prox = novo;
		novo->ant = l->fim;
		l->fim = novo;
		l->fim->prox = NULL;
	
		l->tamanho++;
	}
}
void printLista(Lista* l)
{
    Item* curr = l->inicio;
    while (curr != l->fim)
    {
        printf("%ld, ", curr->elemento);
        curr = curr->prox;
    }
    printf("%ld\n", curr->elemento);
}

void printSet(Set *s, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d:",i);
        if(s->tabela_hash[i]->tamanho > 0)
            printLista(s->tabela_hash[i]);
        else
         printf("\n");
    }
}

int h(long key)
{
	return key % CAPACIDADE;
}

int inserir(Set* s, long elemento){
	int hash_elemento = h(elemento);
	Item* i = novoItem(elemento);
	inserirFim(s->tabela_hash[hash_elemento], i);	
	return -1;
}


int main()
{   
    	int  IN; long x;
    	scanf("%d", &IN);
	Set *S=novoSet();
	for(int i=0; i<IN; i++){
        	scanf(" %ld", &x);
        	inserir(S, x);
    	}
	printSet(S, IN);
}
