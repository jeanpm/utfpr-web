#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <malloc.h>

typedef struct no{
    int numero;

    struct no*prox;
}no;


typedef struct{
    int quant;
    no*inicio;
}LD;


void criaLD(LD*L){
    L->quant=0;
    L->inicio=NULL;
}
void inserirprimeiro(LD*L,no*c);
void inserirfinal(LD*L,no*c);
void imprime (LD *L);
void inserirfinal(LD*L,no*c){
    no*aux;
    aux=L->inicio;

    c->prox = NULL;
    if(aux==NULL){
        L->inicio=c;
    }
    else{
        while(aux->prox != NULL)
			aux = aux->prox;
    aux->prox=c;
    }

}

LD* merge(LD*L1,LD*L2){
    LD*C1;
    C1=malloc(sizeof(LD));
    if(C1==NULL){
        return NULL;
    }
    criaLD(C1);
    no*aux1,*aux2;
    aux1=L1->inicio;
    aux2=L2->inicio;
    while(aux1!=NULL&&aux2!=NULL){
        if(aux1->numero>=aux2->numero){
                inserirfinal(C1,aux2);
                aux2=aux2->prox;
        }
        else{
            inserirfinal(C1,aux1);
            aux1=aux1->prox;
        }

    }
    if(aux1==NULL){
        while(aux2!=NULL){
            inserirfinal(C1,aux2);
            aux2=aux2->prox;
        }

    }
    else{
        while(aux1!=NULL){
            inserirprimeiro(C1,aux1);
            aux1=aux1->prox;
            }

    }
    imprime (C1);
   // return C1;
}

void inserirprimeiro(LD*L,no*c){
    L->quant++;
    c->prox=L->inicio;
    L->inicio=c;
}








int vazia(LD *L){
	if(L->inicio == NULL)
		return 1;
	else
		return 0;
}




void inserirordpreco(LD*L,no*c){
    no*aux ;
    if(L->inicio==NULL||c->numero<L->inicio->numero){
        inserirprimeiro(L,c);
        L->quant++;
    }
    else{
        aux=L->inicio;
        while(aux->prox!=NULL&&aux->prox->numero<c->numero){
            aux=aux->prox;
        }
        c->prox=aux->prox;
        aux->prox=c;
        L->quant++;
    }
}





void imprime (LD *L) {
    no*aux;
    aux=L->inicio;

   while (aux!= NULL) {
      printf ("%d \n",aux->numero);
        aux=aux->prox;
   }printf("\n");
}





















int main(){

    LD lista;
    LD lista1;
    LD *lista2;


    criaLD(&lista);
    criaLD(&lista1);

  //////Faltou terminar faltou terminar




    no *aux=lista.inicio;

    no *aux1=lista1.inicio;


    int i;


    lista2=merge(&lista,&lista1);


   

    return 0;
}








