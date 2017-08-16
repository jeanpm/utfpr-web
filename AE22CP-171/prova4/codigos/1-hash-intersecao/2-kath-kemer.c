#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define TAM 1021

typedef struct celula
{	
	int conteudo;                
	struct celula*prox;
	struct celula*ant;
}celula;

typedef struct lista
{				
	celula*inicio;
	int cont;
}lista;

lista *inicializa()
{
	lista* l = (lista*) malloc(sizeof(lista));

	l->inicio = NULL;
	l->cont = 0;
	
	return l;
}

celula *cria(int conteudo)			
{
	celula *p = malloc(sizeof(celula));
	p->conteudo = conteudo;
	p->prox = NULL;
	p->ant = NULL;
	return p;
}

int HASH(int conteudo)
{
	return(conteudo % TAM);
}

int insere_inicio(lista *l, int conteudo)
{
	if(l == NULL)
	{
		return 0;
	}
	celula *novo = cria(conteudo);
	if(novo == NULL)
	{
		return 0;
	}

	novo->prox = l->inicio;
	novo->ant = NULL;
	l->inicio = novo;
	if(novo->prox != NULL)
	{
		novo->prox->ant = novo;
	}

	l->cont++;
	return 1;
}
int insere_fim(lista *l, int conteudo)	
{
	if(l->inicio==NULL)
	{
		return(insere_inicio(l,conteudo));
	}
	
	celula *novo = cria(conteudo);

	if(novo==NULL)
	{
		return (0);
	}
	
	celula *ultimo = l->inicio;

	while(ultimo->prox !=NULL)
	{
		ultimo = ultimo->prox;
		
	}

	ultimo->prox=novo;
	l->cont++;
	return 1; 
}

void printLista(lista *l)  		
{
	celula *p =l->inicio;
	
	while(p->prox != NULL)
	{ 
		printf("%d ", p->conteudo);
		p = p->prox;
		      		
	}
	printf("%d ", p->conteudo);
}

void conjunto(lista **tabA, lista **tabB, lista **tabC)
{
	int i,j;
	i=j=0;

	for (i = 0; i < TAM; i++)
	{
		for(j = 0;j < TAM; j++)
		{
			if(tabA[i]->inicio != NULL && tabB[j]->inicio != NULL)
			{			
				if(tabA[i]->inicio->conteudo == tabB[j]->inicio->conteudo)
				{
					insere_fim(tabC[HASH(tabA[i]->inicio->conteudo)],tabA[i]->inicio->conteudo);
				}

			
			}
		}
	}
	
}

int main(void)
{
	int i=0,j=0;
	int A=0,B=0,C=0;
	int repete=0;
	int valor=0; 
	lista** tabA = (lista**)malloc(TAM*sizeof(lista*));
	lista** tabB = (lista**)malloc(TAM*sizeof(lista*));
    	
	scanf("%d",&A);  	

	for (i = 0; i < TAM; i++) 
	{
		tabA[i] = inicializa();  
	}
   	for(i = 0;i < A; i++)               
    	{ 
		scanf("%d",&valor); 
		for(j = 0;j < TAM; j++)
        	{
			if(tabA[j]->inicio != NULL)
			{		
				if(tabA[j]->inicio->conteudo == valor)
				{
					repete = 1;
				}
			}
       		 }

        	if(repete == 0)
        	{
        		insere_fim(tabA[HASH(valor)], valor);
       	 	}
		else
		{
			repete = 0;
		}   
		
  	 }

	i=0;
	j=0;
	repete=0;
   	
	scanf("%d",&B); 
   	
   	 for (i = 0; i < TAM; i++) 
	{
        	tabB[i] = inicializa();  
    	}
   	 for(i = 0;i < B; i++)               
    	{ 
		scanf("%d",&valor); 
		for(j = 0;j < TAM; j++)
        	{
			if(tabB[j]->inicio != NULL)
			{		
				if(tabB[j]->inicio->conteudo == valor)
				{
					repete = 1;
				}
			}
       		 }

        	if(repete == 0)
        	{
        		insere_fim(tabB[HASH(valor)],valor);
       	 	}
		else
		{
			repete = 0;
		}   		

  	 }
 
 	C = A+B;
 	lista** tabC = (lista**) malloc(TAM*sizeof(lista*));

   	for (i = 0; i < TAM; i++) 
    	{
       		 tabC[i] = inicializa();  
    	}

	
	conjunto(tabA, tabB, tabC);


    	for(i = 0;i < TAM; i++)
    	{ 
       		 if(tabC[i]->inicio != NULL)
		{
          		  printLista(tabC[i]);
		}
	} 
	printf("\n");
	return 0;
}
