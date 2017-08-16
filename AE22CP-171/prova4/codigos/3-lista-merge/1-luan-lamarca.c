//
//  main.c
//  merge
//
//  Created by Luan Lamarca on 05/07/17.
//  Copyright © 2017 Luan Lamarca. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int info,id;
    struct no *next;
    struct no *prev;
}no;

typedef struct lista
{
    int Nnos;
    no *head;
    no *tail;
}lista;

lista *inicializa()
{
    lista *l=(lista*)malloc(sizeof(lista));
    
    l->Nnos=0;
    l->head=NULL;
    l->tail=NULL;
    
    return l;
}

void insere(lista *l, int e)
{
    no *novo=(no*)malloc(sizeof(no));
    novo->info=e;
    novo->id=l->Nnos+1;
    novo->prev=NULL;
    novo->next=NULL;
    
    if(l->head==NULL){
        l->Nnos++;
        l->head=novo;
        l->tail=novo;
    }
    else{
        l->Nnos++;
        novo->prev=l->tail;
        l->tail->next=novo;
        l->tail=novo;
    }
}

void imprime(lista *l){
    no *nodo=l->head;
    int i;
    printf("\n\n");
    for(i=0;i<l->Nnos;i++){
        printf("\t[%d]",nodo->info);
        nodo=nodo->next;
    }
    printf("\n\n");
    nodo=l->head;
    for(i=0;i<l->Nnos;i++){
        printf("\t[%d]",nodo->id);
        nodo=nodo->next;
    }
    printf("\n\n");
}

void copylist(lista *origem, lista *destino){
    int i;
    no *o=origem->head;//nó para percorrer a lista
    no *d;//nó auxiliar para atribuir os indices
    
    for(i=0;i<origem->Nnos;i++){//percorre toda a lista
        insere(destino,o->info);//insere na lista o valor contido na origem
        o=o->next;//avança para o proximo nó
    }
    
    d=destino->head;
    o=origem->head;
    
    for(i=0;i<origem->Nnos;i++){//percorre toda a lista
        d->id=o->id;//atribui o indice da origem para o destino
        o=o->next;// avança para o proximo nó de origem
        d=d->next;//avança para o proximo nó de destino
    }
    
    
}

lista *teste(){//lista para testes
    lista *list=inicializa();
    
    
    insere(list,12);
    insere(list,158);
    insere(list,484);
    insere(list,458);
    insere(list,1);
    insere(list,0);
    insere(list,3);
    
    return list;
}

void divide(lista *l, lista *L, lista *R){//divide a lista em duas
    int i,p=l->head->id,r=l->tail->id,q;//p e r recebem os indices
    no *Q=l->head;//nó para percorrer a lista
    
    q=((r-p)/2)+1;//encontra o indice do meio
    for(i=0;i<=q-1;i++){//percorre a lista até o meio
        Q=Q->next;
    }
    //atribui os valores respectivos para a lista da esquerda
    L->head=l->head;
    L->Nnos=q;
    L->tail=Q->prev;
    
    //atribui os valores respectivos para a lista da direita
    R->head=Q;
    R->Nnos=(r-p)-(q-1);
    R->tail=l->tail;
    
}

void Merge(lista *l,lista *LEFT, lista *RIGHT){
    no *left;//nó para comparações da lista da esquerda
    no *right;//nó para comparações da lista da direita
    no *list=l->head;//nó para percorrer a lista
    lista *L=inicializa();//lista para ser copiada a lista da esquerda
    lista *R=inicializa();//lista para ser copiada a lista da direita
    int i;
    
    copylist(LEFT,L);//copia o conteudo de LEFT para L
    copylist(RIGHT,R);//copia o conteudo de RIGHT para R
    
    left=L->head;
    right=R->head;
    
    insere(L,9999);//insere valor "infinito"
    insere(R,9999);
    
    for(i=0;i<l->Nnos;i++){//percorre toda a lista
        if(left->info < right->info){//compara se o valor da esquerda é maior que o valor da direita
            list->info=left->info;//copia pra lista o valor da esquerda
            left=left->next;//avança para o proximo nó da esquerda;
        }
        else{
            list->info=right->info;//copia o valor da direta para a lista
            right=right->next;//avança para o proximo nó da direita
        }
        list=list->next;//avança para o proximo nó da lista
    }
    
}

void MergeSort(lista *l, int p, int r)
{
    lista *L=inicializa();//cria a lista da divisão da esquerda
    lista *R=inicializa();//cria a lista da divisão da direita
    if(r-p>0){
        
        divide(l,L,R);//divide a lista em duas
        
        MergeSort(L,L->head->id,L->tail->id);//faz recursão para a lista da esquerda
        MergeSort(R,R->head->id,R->tail->id);//faz recursão para a lista da direita
        Merge(l,L,R);//funde as listas
    }
    
}

int main(){
    lista *list=inicializa();
    
    printf("\n");
    return 0;
}


