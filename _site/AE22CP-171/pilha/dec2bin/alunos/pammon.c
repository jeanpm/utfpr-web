#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item{
	long num;
	struct item* proximo;
	struct item* anterior;
} Item;

typedef struct lista{
	int quantidade;
	struct item* inicio;
	struct item* fim;
} Pilha;

Pilha* CriaPilha(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->inicio = NULL;
	p->fim = NULL;
	p->quantidade = 0;

	return p;
}

Item* CriaItem(int valor){
	Item *i = (Item*) malloc(sizeof(Item));
	i->num = valor;
	i->proximo  = NULL;
	i->anterior  = NULL;
	return i;

}

void push(Pilha *p, Item* i){
	if(p->inicio == NULL){
		p->inicio = i;
		p->fim = p->inicio;
		p->quantidade++;
    }
	else{
		p->fim->proximo = i;
		i->anterior = p->fim;
		p->fim = i;
		p->fim->proximo = NULL;
		p->quantidade++;
	}
}

Item* pop(Pilha* p){
	Item* removido = NULL;
	if(p->quantidade == 1){
		removido = p->fim;
		p->inicio = NULL;
		p->fim = NULL;
	}
	else{
		removido = p->fim;
		p->fim = removido->anterior;
		p->fim->proximo = NULL;
	}
	p->quantidade--;

	return removido;
}

int main(){
	Pilha* p = CriaPilha();
	long n;
	int j, resto = 0;
	scanf("%ld", &n);
	while(n != 0){
		resto = n%2;
		Item* i = CriaItem(resto);
		n = n/2;
		push(p, i);
	}

// pop(p) retorna um item, não dá para imprimí-lo diretamente
//	for(j = 0; p->quantidade > 0; j++)
//		printf("%d", pop(p));
	
// MODIFICAÇÂo:
	for(j = 0; p->quantidade > 0; j++) {
		printf("%ld", pop(p)->num);
	}	
	
	printf("\n");
	return 0;
}

