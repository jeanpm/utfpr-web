#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

#define CAPACIDADE 1021


typedef struct _Item Item;
typedef struct _Lista Lista;

struct _Item
{
    long valor;
    Item* prox;
    Item* ant;
};


struct _Lista
{
    Item* inicio;
    Item* fim;
    int tamanho;
};



Lista* novaLista()
{
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->inicio = NULL;
    l->fim    = NULL;
    l->tamanho = 0;

    return l;
}

Item* novoItem(int value)
{
    Item *i = (Item*) malloc(sizeof(Item));
    i->valor = value;
    i->prox  = NULL;
    i->ant  = NULL;
    return i;
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


#include <math.h>
#include <time.h>

// Gera um arquivo de entrada aleatoriamente, para testar a função inserir.
void random_input(int max_len)
{
    const int max_value = 10;
    int set_size = rand() % max_len;
    printf("%d\n", set_size);

    int anterior = 0;
    int atual = 0;
    while (set_size-- > 0) {
        atual = anterior + rand() % max_value;
        printf("%d ", atual);
        anterior = atual;
    }
    printf("\n");
}


void read_list(Lista* s)
{
    int set_size;
    int set_item;
    scanf("%d", &set_size);
    while (set_size-- > 0) 
    {
        scanf("%d", &set_item);
        inserirFim(s, novoItem(set_item));
    }
//    printSet(s);
}

void printLista(Lista* l)
{
	if (l->inicio != NULL)
	{
		Item* curr = l->inicio;
		while(curr != l->fim)
		{
			fprintf(stdout, "%ld ", curr->valor); 
			curr = curr->prox;
		}
		fprintf(stdout, "%ld ", curr->valor); 
		fprintf(stdout, "\n");
	}
}

Lista* merge(Lista* a, Lista* b)
{
	Lista* c = novaLista();
	
	Item* aptr = a->inicio;
	Item* bptr = b->inicio;
	
	while (aptr != NULL && bptr != NULL)
	{
		if  (aptr->valor <= bptr->valor) {
			inserirFim(c, novoItem(aptr->valor));
			aptr = aptr->prox;
		} else {
			inserirFim(c, novoItem(bptr->valor));
			bptr = bptr->prox;
		}
	}
	
	while (aptr != NULL)
	{
		inserirFim(c, novoItem(aptr->valor));
		aptr = aptr->prox;
	} 
	
	while (bptr != NULL ) {
		inserirFim(c, novoItem(bptr->valor));
		bptr = bptr->prox;
	} 
	
	
	return c;
}



int main(int argc, char** argv)
{
    if (argc > 1)
    {
        srand(time(NULL));
        random_input(atol(argv[1]));
        random_input(atol(argv[1]));
    } else {
        Lista* s = novaLista();
        Lista* w = novaLista();

        read_list(s);
        read_list(w);             

        Lista* i = merge(s,w);
        printLista(i);
    }
}
