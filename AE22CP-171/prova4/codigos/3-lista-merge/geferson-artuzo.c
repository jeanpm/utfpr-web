#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

    typedef struct Item
    {
        int valor;
        struct Item *prox;
    }Item;

    typedef struct
    {
        int quant;
        Item *inicio;
    }LD;
LD *merge(LD *L1, LD *L2);
void criaLD(LD *L)
{
    L->quant=0;
    L->inicio=NULL;
}
void inserirPos(LD*L, Item *c,int pos)
{
    int cont=0;
    Item *aux;
    aux=L->inicio;
    while(cont<(pos-1))
    {
        aux=aux->prox;
        cont++;
    }
    c->prox=aux->prox;
    aux->prox=c;
    L->quant++;
}

LD *merge(LD *L1, LD *L2)
{
    Item *aux1,*aux2,*tmp;
    LD *nova=malloc(sizeof(nova));
    criaLD(nova);
    aux1=L1->inicio;
    aux2=L2->inicio;
    int pos=1;
    while(aux1!=NULL && aux2!=NULL)
    {
        if(aux2->valor < aux1 ->valor)
        {
            tmp=aux1->prox;
            inserirPos(nova,aux1,pos);
            aux1=tmp;
            pos++;
        }
        else
        {
            tmp=aux2->prox;
            inserirPos(nova,aux2,pos);
            aux1=tmp;
            pos++;
        }

    }
    while(aux1!=NULL)
    {
        tmp=aux1->prox;
        inserirPos(nova,aux1,pos);
        aux1=tmp;
        pos++;
    }
    while(aux2!=NULL)
    {
        tmp=aux2->prox;
        inserirPos(nova,aux2,pos);
        aux2=tmp;
        pos++;
    }
    free(L1);
    free(L2);
    return(nova);
}
void imprimir(LD *l)
{
    Item *ini;
    ini= l->inicio;
    while(ini!=NULL)
        {
            printf("%d\n",ini->valor);
            ini=ini->prox;
        }

}
int main() {
    LD *Lista; LD *Lista2;
    criaLD(Lista);criaLD(Lista2); 
    Item *a; Item *b;  
    int cont=0;int cont2=0;int tam;int l;
    scanf("%d",&tam);
    for(int i=0;i<tam;i++)
    {
        scanf("%d",&l);
        a=malloc(sizeof(Item));
        a->valor=l;
        inserirPos(Lista,a,i);
    }
    for(int i=0;i<tam;i++)
    {
        scanf("%d",&l);
        b=malloc(sizeof(Item));
        b->valor=l;
        inserirPos(Lista2,a,i);
    }
    
    imprimir(merge(Lista,Lista2));
    return 0;
}

