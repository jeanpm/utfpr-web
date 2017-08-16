#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define TAM 1000

//TABELA HASH COM TRATAMENTO DE COLISÕES POR ENCADEAMENTO SEPARADO

typedef struct celula{
	int conteudo;
	struct celula*prox;
	struct celula*ant;
}celula;

typedef struct listaDENC{
	celula*inicio;
	int cont;
}listaDENC;

listaDENC *inicializa()
{
	listaDENC* l = (listaDENC*) malloc(sizeof(listaDENC));

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

int insere_inicio(listaDENC *l, int conteudo)
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
int insere_fim(listaDENC *l, int conteudo)
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

void imprimelista (listaDENC *l)
{
	celula *p;

	for(p = l->inicio;p != NULL;p = p->prox)
	{
      		printf("%d ", p->conteudo);
	}
}

void imprime_lista (listaDENC *l)
{
	celula *p =l->inicio;

	while(p->prox != NULL)
	{
		printf("%d ", p->conteudo);
		p = p->prox;

	}
	printf("%d ", p->conteudo);
}



int main(void)
{
	int i=0,j=0,A=0,B=0,C=0;
	int conteudo;
	int marcador=0;
	listaDENC** hashc = (listaDENC**) malloc(TAM*sizeof(listaDENC*));
	listaDENC** hasha = (listaDENC**)malloc(TAM*sizeof(listaDENC*));
    listaDENC** hashb = (listaDENC**)malloc(TAM*sizeof(listaDENC*));

    	scanf("%d",&A);
	for (i = 0; i < TAM; i++)
	{
		hasha[i] = inicializa();
	}
   	for(i = 0;i < A; i++)
    	{
		scanf("%d",&conteudo);
		for(j = 0;j < TAM; j++)
        	{
			if(hasha[j]->inicio != NULL)
			{
				if(hasha[j]->inicio->conteudo == conteudo)
				{
					marcador = 1;
				}
			}
       		 }

        	if(marcador == 0)
        	{
        		insere_fim(hasha[HASH(conteudo)],conteudo);
       	 	}
		else
		{
			marcador = 0;
		}
		
  	 }
	i=0;
	j=0;
	marcador=0;
   	scanf("%d",&B);
    for (i = 0; i < TAM; i++)
    	{
        	hashb[i] = inicializa();
    	}
   	 for(i = 0;i < B; i++)
    	{
		scanf("%d",&conteudo);
		for(j = 0;j < TAM; j++)
        	{
			if(hashb[j]->inicio != NULL)
			{
				if(hashb[j]->inicio->conteudo == conteudo)
				{
					marcador = 1;
				}
			}
       		 }

        	if(marcador == 0)
        	{
        		insere_fim(hashb[HASH(conteudo)],conteudo);
       	 	}
		else
		{
			marcador = 0;
		}
	
  	 }


 	C = A+B;
 	for (i = 0; i < TAM; i++)
    	{
       		 hashc[i] = inicializa();
    	}

for (i = 0; i < TAM; i++)
	{
		for(j = 0;j < TAM; j++)
		{
			if(hasha[i]->inicio != NULL && hashb[j]->inicio != NULL)
			{
				if(hasha[i]->inicio->conteudo == hashb[j]->inicio->conteudo)
				{
					insere_fim(hashc[HASH(hasha[i]->inicio->conteudo)],hasha[i]->inicio->conteudo);
				}


			}
		}
	}


    for(i = 0;i < TAM; i++)
    {
        if(hashc[i]->inicio != NULL)
	{
            imprime_lista(hashc[i]);
	}
  }

	return(0);
}
