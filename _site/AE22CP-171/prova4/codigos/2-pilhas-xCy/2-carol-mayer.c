#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//PILHA (LIFO/Last-In-First-Out) ALOCADA DINAMICAMENTE

typedef struct celula{
	int conteudo;
	struct celula*prox;
}celula;
typedef struct pilhaD{
	celula*inicio;
	int cont;
}pilhaD;

void inicializa(pilhaD *p)
{
	p->inicio = NULL;
	p->cont = 0;
}

celula *cria(int conteudo)
{
	celula *p = malloc(sizeof(celula));
	p->conteudo = conteudo;
	p->prox = NULL;
	return p;
}

int pilha_vazia(pilhaD *p)
{
	if(p == NULL || p->inicio == NULL)
	{
		//printf("Pilha vazia\n");
		return 1;
	}
	return 0;
}

int empilha(pilhaD *p, int conteudo)
{
	if(p == NULL)
	{
		return 0;
	}
	celula *novo = cria(conteudo);
	if(novo == NULL)
	{
		return 0;
	}

	novo-> conteudo = conteudo;
	novo->prox = p->inicio;
	p->inicio = novo;
	p->cont++;
	return 1;
}


char desempilha(pilhaD *p)
{
	if(p == NULL || p->inicio == NULL)
	{
		printf("Nao ha elementos na pilha\n");
		return 0;
	}

	int ret = p->inicio->conteudo;

	celula *rmv = p->inicio;
	p->inicio = p->inicio->prox;
	free(rmv);
	p->cont--;
	return(ret);
}

celula *busca_topo (pilhaD *p)
{
	celula *novo = p->inicio;
	printf("\n Topo: %d\n\n",novo->conteudo);
	return novo;
}

void imprime_pilha (pilhaD *p)
{
	celula *novo;
	for(novo = p->inicio;novo != NULL;novo = novo->prox)
	{
      		printf("%c\n", novo->conteudo);
	}
}


void apaga_pilha (pilhaD *p)
{
	int i=0;

	celula *ant = p->inicio;
	celula *atual = p->inicio;

	while (atual != NULL)
	{
		ant = atual;
		atual = atual->prox;
		free(ant);
	}
	p->inicio = NULL;
	p->cont = 0;
}

int main(void)
{
    char palavra[100];
	pilhaD p;
	int i=0;


	//celula *A = cria(0);

	inicializa(&p);
	//printf("\ndigite a palavra:");
	scanf("%s",&palavra);

	while(palavra[i]!='C')
    {
        empilha(&p,palavra[i]);
        i++;
    }
    empilha(&p,palavra[i]);
 //  imprime_pilha (&p);


  // printf("\n%s",palavra);
    while(pilha_vazia(&p)!=1)

    {
        //if(pilha_vazia(&p)!=0)
        //{
          if(desempilha(&p)==palavra[i])
            {
                i++;


            }
            else
            {
                printf("NÃO");
                return -1;


            }
       // }
       // else
       // {
         //   printf("NAO");
         //   return -1;
      //  }

    }


if(pilha_vazia(&p)==1)
{
    printf("SIM");

}
else
{
    printf("NÃO");
}

    return 0;
}










