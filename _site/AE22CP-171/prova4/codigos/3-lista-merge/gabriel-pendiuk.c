#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct notag{
	int chave;
	struct notag *prox;
}no;

typedef struct{
	no* inicio;
	int quant;
}LD;
typedef struct{
	no* inicio;
	int quant;
	no* fim;
}LDD;


void DefineS(LD *L){
	L->quant=0;
	L->inicio=NULL;
}

void DefineD(LDD *L){
	L->quant=0;
	L->inicio=NULL;
	L->fim=NULL;
}

no* BuscaValor(LD *L, int ch){
	no *p;
	if(L->quant==0) return NULL;
	else{
		p=L->inicio;
		while(p!=NULL){
			if(p->chave==ch) return p;
			else p=p->prox;
		}
	}
	return NULL;
}

no* BuscaPosicao(LD *L, int pos){
	no *p;
	p=L->inicio;
	int cont;
	if(pos > L->quant){
		printf("posicao invalida\n");
		return NULL;
	}
	while(p!=NULL){
		if(pos==cont) return p;

		cont++;
		p=p->prox;
	}
	return NULL;
}

void RemoverDepois(LD *L, no **q){
	no *p;
	p=(*q)->prox;
	(*q)->prox=p->prox;
	free(p);
	L->quant--;
}

int insere(LD *L, int ch, int pos){
	int cont=0;
	no *q, *p;
	p=L->inicio;
	if(L->quant==0){
	q=malloc(sizeof(no));
	q->chave=ch;
	q->prox=NULL;
	L->inicio=q;
	L->quant++;
	return 1;
	}
	while(p!=NULL){
		if(pos-1==cont){
			q=malloc(sizeof(no));
			q->chave=ch;
			q->prox=p->prox;
			p->prox=q;
			L->quant++;
			return 1;
		}
		cont++;
		p=p->prox;
	}
	return 0;
}

LD merge(LD *L, LD *L2){
	no *p, *q, *maior;
	LD L3;
	if(L->quant>=L2->quant){
		maior=L->inicio;
		p=L2->inicio;
	}
	else{
		maior=L2->inicio;
		p=L->inicio;
	}
	q=malloc(sizeof(no));
	L3.inicio=q;
	L3.quant=0;
	while(maior!=NULL){
		q->chave=maior->chave;
		q->prox=malloc(sizeof(no));
		q=q->prox;
		maior=maior->prox;
		if(p!=NULL){
			q->chave=p->chave;
			p=p->prox;
			q->prox=malloc(sizeof(no));
			q=q->prox;
		}
	}
	q=NULL;
	return L3;
}

void transformacircular(LD *L){
	no *q;
	q=L->inicio;
	while(q->prox!=NULL)
		q=q->prox;

	q->prox=L->inicio;
}

void imprime(no *x)
{
  if(x!=NULL)
  {
      printf("%d ",x->chave);
      imprime(x->prox);
  }
}

void SelectionSort(lista *L)
{
    int i, j;
    elemento aux;
    for(i = 1; i <= L->numElem - 1; i++)
    {
        for(j = i + 1; j <= L->numElem; j++)
        {
            if(L->A[i].chave > L->A[j].chave)
            {
                aux = L->A[i];
                L->A[i] = L->A[j];
                L->A[j] = aux;
            }
        }
    }
}

int main(void)
{
    int cont;
    int insercoes;
    int i;
    int valor;
    int *aux;

    LD lista1, lista2, lista3;
    no *x;

    DefineS(&lista1);
    DefineS(&lista2);
    DefineS(&lista3);

    scanf("%d",&insercoes);
    for(i=0;i<insercoes;i++)
    {
      scanf("%d",&valor);
      cont=insere(&lista1,valor,i);
    }
    scanf("%d",&insercoes);
    for(i=0;i<insercoes;i++)
    {
      scanf("%d",&valor);
      cont=insere(&lista2,valor,i);
    }
    lista3=merge(&lista2,&lista1);
    SelectionSort(&lista3);
    x=lista3.inicio;
    do{
      if(x->chave!=0)
			   printf("%d ",x->chave);
			x=x->prox;
		}while(x!=NULL);
    printf("\n");
}

