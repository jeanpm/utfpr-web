#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

typedef struct _Item Item;
typedef struct _Lista Lista;

#define CAPACIDADE 1021

int h(long key)
{
	return key % CAPACIDADE;
}


struct _Item
{
	long i,j;
	float valor;
	
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

Item* novoItem(float value)
{
	Item *item = (Item*) malloc(sizeof(Item));
	item->valor = value;
	item->prox  = NULL;
	item->ant  = NULL;
	return item;
}


Item* ponteiroParaPosicao(Lista* l, int pos)
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

// =============================================================================

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



void inserirNaPosicao(Lista* l, Item* novo, int pos)
{	
	assert(pos >= 0 && pos <= l->tamanho);

	if (pos == 0)
		inserirInicio(l, novo);
	else if (pos == l->tamanho)
		inserirFim(l, novo);
	else {
		Item* curr = ponteiroParaPosicao(l, pos);
		inserirProximo(l, curr, novo);
	}	
}

// =============================================================================


Item* removerInicio(Lista* l)
{
	assert(l->tamanho > 0);
	
	Item* removed = NULL;
	
	if (l->tamanho == 1)
	{
		removed = l->inicio;
		l->inicio = NULL;
		l->fim = NULL;
	} else {
		removed = l->inicio;
		l->inicio = removed->prox;
		
		l->inicio->ant = NULL;
	}
	l->tamanho--;
	
	
	return removed;
}

Item* removerProximo(Lista* l, Item* anterior)
{
	assert(anterior->prox->prox != NULL);
	
	Item* removed = anterior->prox;
	removed->prox->ant = anterior;
	anterior->prox = removed->prox;
	
	l->tamanho--;
	
	return removed;
}

Item* removerFim(Lista* l)
{
	assert(l->tamanho > 0);
	
	Item* removed = NULL;
	
	if (l->tamanho == 1)
	{
		removed = l->fim;
		l->fim = NULL;
		l->inicio = NULL;		
	} else {
		removed = l->fim;
		l->fim = removed->ant;
		
		l->fim->prox = NULL;
	}
	l->tamanho--;
	
	return removed;
}

// =============================================================================


void printLista(Lista* l)
{
	if (l->inicio != NULL)
	{
		Item* curr = l->inicio;
		while(curr != l->fim)
		{
			fprintf(stdout, "%f ",curr->valor); 
			curr = curr->prox;
		}
		fprintf(stdout, "%f ", curr->valor); 
	}
	printf("\n");
}


// =============================================================================

void freeLista(Lista* l)
{
	while (l->inicio != NULL)
		free(removerInicio(l));
}

// Tratamento de colisões por reespalhamento
// Teste linear ou endereçamento aberto.
int inserir(Lista* tabela_hash[], long ra)
{
	int hash_ra = h(ra);
	
	Item* i = novoItem(ra);
    
    inserirFim(tabela_hash[hash_ra], i);
		
	return -1;
}

void Conjunto(Lista* l,Lista* l2)
{
	if (l->inicio != NULL)
	{
		Item* curr = l->inicio;
        Item* curr2 = l2->inicio;
		while(curr != l->fim)
		{
            while(curr2!= l->fim)
            {
            if(curr->valor == curr2->valor){
                fprintf(stdout, "%f ", curr2->valor);
            }
            curr2 = curr2->prox;
            }
			curr = curr->prox;
		}
	}
}
int main()
{
    int num,elem;
    
	Lista* tabela_hash[CAPACIDADE];
    Lista* tabela_hash1[CAPACIDADE];
	
	for (int i = 0; i < CAPACIDADE; i++)
	{
		tabela_hash[i] = novaLista();
	}
	
	scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&elem);
        inserir(tabela_hash, elem);
    }
	
	for (int i = 0; i < CAPACIDADE; i++)
	{
		tabela_hash1[i] = novaLista();
	}
	
	scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&elem);
        inserir(tabela_hash1, elem);
    }

    
    
    for(int i=0;i<CAPACIDADE;i++){
        
        Conjunto(tabela_hash[i],tabela_hash1[i]);
    }
}

