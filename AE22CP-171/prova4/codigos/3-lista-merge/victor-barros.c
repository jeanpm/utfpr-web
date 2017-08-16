#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//inicializacao//

typedef struct Item {
	int elem;
	struct Item *prox;
} Item;

typedef struct {
	int quant;
	Item *inicio;
}ld;

ld* novaLista()
{
	ld* l = (ld*) malloc(sizeof(ld));
	l->inicio = NULL;
	l->quant = 0;
	return l;
}

Item* novoItem(int value)
{
	Item *item = (Item*) malloc(sizeof(Item));
	item->elem = value;
	item->prox  = NULL;
	return item;
}

// insercao//

void inserirprimeiro(ld *l, Item *c) {
	l->quant++;
	c->prox = l->inicio;
	l->inicio = c;
}

void inserirposicao(ld *l, Item *c, int pos) {
	int cont = 0;
	Item *aux;
	aux = l->inicio;

	while (cont < (pos - 1)) {
		aux = aux->prox;
		cont++;
	}

	c->prox = aux->prox;
	aux->prox = c;
	l->quant++;
}
//mergesort//

//n usa contador//
ld* divide2(ld *l) {
	Item *rapido, *lento;
	rapido = l->inicio;
	lento = rapido;

	while (rapido->prox != NULL) {
		rapido = rapido->prox;
		if (rapido->prox != NULL) {
			rapido = rapido->prox;
			lento = lento->prox;
		}
	}

	ld *l2 = novaLista();

	l2->inicio = lento->prox;
	lento->prox = NULL;
	return l2;
}

ld* merge(ld *l1, ld *l2) {
	Item *aux1, *aux2, *tmp;
	ld *nova = novaLista();
	int pos = 0;
	aux1 = l1->inicio;
	aux2 = l2->inicio;

	while (aux1 != NULL && aux2 != NULL) {
		if (aux2->elem < aux1->elem) {
			tmp = aux2->prox;
			inserirposicao(nova, aux2, pos);
			aux2 = tmp;
		}
		else {
			tmp = aux1->prox;
			inserirposicao(nova, aux1, pos);
			aux1 = tmp;
		}
		pos++;
	}

	while (aux1 != NULL) {
		tmp = aux1->prox;
		inserirposicao(nova, aux1, pos);
		aux1 = tmp;
	}

	while (aux2 != NULL) {
		tmp = aux2->prox;
		inserirposicao(nova, aux2, pos);
		aux2 = tmp;
	}
	free(l1);
	free(l2);
	return nova;
}

void mergesort(ld *l1) {
	ld *l2 = novaLista();

	if (l1->quant > 1) {
		l2 = divide2(l1);
		mergesort(l1);
		mergesort(l2);
		l1 = merge(l1, l2);
	}
}

ld* MergeLista(ld *l1, ld *l2) {
	ld *nova = novaLista();
	Item *aux1 = l1->inicio, *aux2=l2->inicio, *tmp;
	int pos;
	
	//garantir que as listas estao ordenadas//
	mergesort(l1);
	mergesort(l2);
	
	//mesma coisa q o merge mas cria elemento//
	while (aux1 != NULL && aux2 != NULL) {
		if (aux2->elem < aux1->elem) {
			tmp = aux2->prox;
			inserirposicao(nova, novoItem(aux2->elem), pos);
			aux2 = tmp;
		}
		else {
			tmp = aux1->prox;
			inserirposicao(nova, novoItem(aux1->elem), pos);
			aux1 = tmp;
		}
		pos++;
	}

	while (aux1 != NULL) {
		tmp = aux1->prox;
		inserirposicao(nova, novoItem(aux1->elem), pos);
		aux1 = tmp;
	}

	while (aux2 != NULL) {
		tmp = aux2->prox;
		inserirposicao(nova, novoItem(aux1->elem), pos);
		aux2 = tmp;
	}
	
	//ordena a lista//
	mergesort(nova);
	
	return nova;
}

void printLista(ld* l){
	if (l->inicio != NULL){
		Item* curr = l->inicio;
		
		while (curr){
			printf("%d ", curr->elem);
			curr = curr->prox;
		}
		printf("\n");
	}
}

int main() {
	int nl1, nl2, i, x;
	
	ld *l1 = novaLista();
	ld *l2 = novaLista();
	
	scanf("%d", &nl1);
	
	for (i=0; i<nl1; i++){
		scanf("%d", &x);
		if (i == 0){
			inserirprimeiro(l1, novoItem(x));
		}
		else{
			inserirposicao(l1, novoItem(x), i);
		}
	}
	
	scanf("%d", &nl2);
	
	for (i=0; i<nl2; i++){
		scanf("%d", &x);
		if (i == 0){
			inserirprimeiro(l2, novoItem(x));
		}
		else{
			inserirposicao(l2, novoItem(x), i);
		}
	}
	
	ld *resultado = MergeLista(l1, l2);
	
	printLista(resultado);
	
    return 0;
}

