#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct item{
    char string;
    struct item* prox;
    struct item* anterior;
}item;

typedef struct pilha{
    int quant;
    struct item* bgn;
    struct item* end;
}pilha;

pilha* criapilha()
{
	pilha* l = (pilha*) malloc(sizeof(pilha));
	l->bgn = NULL;
	l->end = NULL;
	l->quant = 0;

	return l;
}

item* criaitem(const char c)
{
	item *i = (item*) malloc(sizeof(item));
	i->string=c;
	i->prox  = NULL;
	i->anterior  = NULL;
	return i;
}

void push(pilha *l, item* novo)
{
	if (l->end == NULL)
	{
		l->bgn = novo;
		l->end = l->bgn;
		l->quant++;
    }
	else
	{
		l->end->prox = novo;
		novo->anterior = l->end;
		l->end = novo;
		l->end->prox = NULL;
		l->quant++;
	}
}

item* pop(pilha* l)
{
	assert(l->quant > 0);
	item* removed = NULL;
	if (l->quant == 1)
	{
		removed = l->end;
		l->end = NULL;
		l->end = NULL;
	} else {
		removed = l->end;
		l->end = removed->anterior;
		l->end->prox = NULL;
	}
	l->quant--;
    removed->prox=NULL;
	removed->anterior=NULL;
	return removed;
}

char top (pilha* p){
    char a=p->end->string;
    return a;
}

void palindrome(char* str) {
    int i=0;
    pilha* p=criapilha();
    item* a;
    while(str[i]!='C'){
        a=criaitem(str[i]);
        push(p,a);
        i++;
    }
    int f=i+1;
    while(str[f]!='\0'){
        if(top(p)==str[f]){
            pop(p);
        }
        f++;
    }
    if(p->end==NULL){
        printf("SIM\n");
    }
    else{
        printf("NÃO\n");
    }
}

int main() {
    char* palavra = (char *)malloc(100 * sizeof(char));
    scanf("%s", palavra);
    palindrome(palavra);
    return 0;
}

