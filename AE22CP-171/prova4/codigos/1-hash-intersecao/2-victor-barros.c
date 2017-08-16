#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define tamanho 1021

typedef struct item{
	int conteudo;
	struct item*prox;
	struct item*ant;
}item;

typedef struct listaDENC{
	item*inicio;
	int cont;
}listaDENC;

listaDENC *inicializa()
{
	listaDENC* l = (listaDENC*) malloc(sizeof(listaDENC));

	l->inicio = NULL;
	l->cont = 0;

	return l;
}

item *cria(int conteudo)
{
	item *p = malloc(sizeof(item));
	p->conteudo = conteudo;
	p->prox = NULL;
	p->ant = NULL;
	return p;
}

int HASH(int conteudo)
{
	return(conteudo % tamanho);
}

int insere_inicio(listaDENC *l, int conteudo)
{
	if(l == NULL)
	{
		return 0;
	}
	item *novo = cria(conteudo);
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
int inserefim(listaDENC *l, int conteudo)
{
	if(l->inicio==NULL)
	{
		return(insere_inicio(l,conteudo));
	}

	item *novo = cria(conteudo);

	if(novo==NULL)
	{
		return (0);
	}

	item *ultimo = l->inicio;

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
	item *p;

	for(p = l->inicio;p != NULL;p = p->prox)
	{
      		printf("%d ", p->conteudo);
	}
}

void imprime_lista (listaDENC *l)
{
	item *p =l->inicio;

	while(p->prox != NULL)
	{
		printf("%d ", p->conteudo);
		p = p->prox;

	}
	printf("%d ", p->conteudo);
}

void UNIAO (listaDENC **s1, listaDENC **s2, listaDENC **tabC)
{
	int i,j;
	//int flagrepetida=0;
	i=j=0;

	for (i = 0; i < tamanho; i++)
	{
		for(j = 0;j < tamanho; j++)
		{
			if(s1[i]->inicio != NULL && s2[j]->inicio != NULL)
			{
				if(s1[i]->inicio->conteudo == s2[j]->inicio->conteudo)
				{
					inserefim(tabC[HASH(s1[i]->inicio->conteudo)],s1[i]->inicio->conteudo);
				}


			}
		}
	}

}

int main(void)
{
	int i=0,j=0,A=0,B=0,C=0;
	int conteudo;
	int flagrepetida=0;

    	scanf("%d",&A);
	listaDENC** s1 = (listaDENC**)malloc(tamanho*sizeof(listaDENC*));

	for (i = 0; i < tamanho; i++)
	{
		s1[i] = inicializa();
	}
   	for(i = 0;i < A; i++)
    	{
		scanf("%d",&conteudo);
		for(j = 0;j < tamanho; j++)
        	{
			if(s1[j]->inicio != NULL)
			{
				if(s1[j]->inicio->conteudo == conteudo)
				{
					flagrepetida = 1;
				}
			}
       		 }

        	if(flagrepetida == 0)
        	{
        		inserefim(s1[HASH(conteudo)],conteudo);
       	 	}
		else
		{
			flagrepetida = 0;
		}
		 }





	i=j=flagrepetida=0;
   	scanf("%d",&B);
   	listaDENC** s2 = (listaDENC**)malloc(tamanho*sizeof(listaDENC*));

   	 for (i = 0; i < tamanho; i++)
    	{
        	s2[i] = inicializa();
    	}
   	 for(i = 0;i < B; i++)
    	{
		scanf("%d",&conteudo);
		for(j = 0;j < tamanho; j++)
        	{
			if(s2[j]->inicio != NULL)
			{
				if(s2[j]->inicio->conteudo == conteudo)
				{
					flagrepetida = 1;
				}
			}
       		 }

        	if(flagrepetida == 0)
        	{
        		inserefim(s2[HASH(conteudo)],conteudo);
       	 	}
		else
		{
			flagrepetida = 0;
		}
  	 }




 	C = A+B;
 	listaDENC** s3 = (listaDENC**) malloc(tamanho*sizeof(listaDENC*));

   	for (i = 0; i < tamanho; i++)
    	{
       		 s3[i] = inicializa();
    	}


	UNIAO(s1, s2, s3);


    for(i = 0;i < tamanho; i++)
    {
        if(s3[i]->inicio != NULL)
	{
            imprime_lista(s3[i]);
	}
  }

	return(0);
}

