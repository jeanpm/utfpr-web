#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

typedef struct Item{
    char string;
    struct Item* prox;
    struct Item* ant;
}Item;

typedef struct Lista{
    int tamanho;
    struct Item* inicio;
    struct Item* fim;
}Lista;

Lista* NewLista()
{
	Lista* l = (Lista*) malloc(sizeof(Lista));
	l->inicio = NULL;
	l->fim    = NULL;
	l->tamanho = 0;

	return l;
}

Item* novoItem(const char c)
{
	Item *i = (Item*) malloc(sizeof(Item));
	i->string = c;
	i->prox = NULL;
	i->ant  = NULL;
	return i;
}


Item* ponteiroPPosicao(Lista* l, int pos)
{
	Item* curr = NULL;

	if (pos < l->tamanho/2) {
		curr = l->inicio;
		for (int i = 0; i < pos - 1; ++i)
			curr = curr->prox;
	} else {
		curr = l->fim;
		for (int i = l->tamanho; i > pos; --i)
			curr = curr->ant;
	}

	return curr;
}


void inserirInicio(Lista* l, Item* novo)
{
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

void inserirProximo(Lista* l, Item* atual, Item* novo)
{
	assert(atual->prox != NULL);

	novo->prox = atual->prox;
	novo->ant = atual;

	atual->prox->ant = novo;
	atual->prox = novo;

	l->tamanho++;
}


void inserirFim(Lista* l, Item* novo)
{
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


void inserirNaPosicao(Lista* l, Item* novo, int pos)
{
	assert(pos >= 0 && pos <= l->tamanho);

	if (pos == 0)
		inserirInicio(l, novo);
	else if (pos == l->tamanho)
		inserirFim(l, novo);
	else {
		Item* curr = ponteiroPPosicao(l, pos);
		inserirProximo(l, curr, novo);
	}
}


void imprime(Lista* l)
{
	Item* curr = l->inicio;
	while(curr != l->fim)
	{
		fprintf(stderr, "%d\t", curr->string);
		curr = curr->prox;
	}
	fprintf(stderr, "\n");
}

Lista* strParaLista (char* str1)
{
    int i=0;
    Lista* l=NewLista();
    Item* e;
    while(str1[i]!='\0'){
        e=novoItem(str1[i]);
        inserirInicio(l,e);
        i++;
    }
    return l;
}

int strcmplista(Lista* A,Lista* B)
{
    int resultado;

    Item* curr;
    Item* curr1;

    curr=A->inicio;
    curr1=B->inicio;

    char a,b;
    while(curr!=NULL)
	{
        a=curr->string;
        b=curr1->string;

        if(a==b)
	{
            resultado=0;
        }
        else if(a<b)
	{
            resultado=-1;
            return resultado;
        }
        else if(a>b)
	{
            resultado=1;
            return resultado;
        }
        curr=curr->prox;
        curr1=curr1->prox;
    }
    return resultado;
}

int main()
{
    char str1[100];
    
    char str2[100];

    Lista* a=NewLista();
    Lista* b=NewLista();
    int resultado;

    scanf("%s",str1);
    
    scanf("%s",str2);

    a=strParaLista(str1);
       
    
    b=strParaLista(str2);    
    
    
    resultado=strcmplista(A,B);

    if(resultado==0)
    {
       printf("A igual a B");
    }
    else if(resultado>0){
        printf("A maior que B");
    }
    else if(resultado<0)
    {
        printf("A menor que B");
    }
    

    return 0;
}

