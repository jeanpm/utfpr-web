#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct item
{
	long valor;
	struct item* prox;
	struct item* ant;
}item;

typedef struct 
{
	item* inicio;
	item* fim;
	int quant;
}lista;

lista* novalista()
{
	lista *l= (lista*) malloc(sizeof(lista));
	l->inicio=NULL;
	l->fim=NULL;
	l->quant=0;
	return l;
}

item* novoitem(int value)
{
	item *c= (item*) malloc(sizeof(item));
	c->valor=value;
	c->ant=NULL;
	c->prox=NULL;
	return c;
}

void push(lista* l, item* novo)
{
	if(l->quant==0)
	{
		l->inicio=novo;
		l->fim=novo;
		l->quant++;
	}
	else
	{
//		novo->prox=l->inicio->prox;		
//		l->inicio->ant=novo;
		
		novo->prox = l->inicio;
		l->inicio->ant = novo;
		l->inicio = novo; 
		l->quant++;
	}
}

item* pop(lista* l)
{
	item* aux;
	if(l->quant==0)return NULL;
	else if(l->quant==1)
	{
		aux=l->inicio;
		l->inicio=NULL;
		l->fim=NULL;
		l->quant--;
		return aux;
	}
	else
	{
		aux=l->inicio;
		l->inicio=aux->prox;
		l->quant--;
		return aux;
	}
}
void decimalparabinario(long num)
{
	item* it;
	lista* l=novalista();
	while(num!=0)
	{
		it=novoitem(num%2);
		push(l,it);
		num=num/2;
	}
	while((l->quant)!=0)
	{
		it=pop(l);
		printf("%ld", it->valor);
//		num=(10*num)+(it->valor);
	}

	printf("%ld\n",num);
}

int main(void)
{
	long a;
	scanf("%ld",&a);
	decimalparabinario(a);
}

