#include <stdio.h>
#include <stdlib.h>
#define MAX 100  //como é estática eu defino o tamanho dela uma vez só

//LISTA SEQUENCIAL ALOCADA ESTATICAMENTE

typedef struct celula{
	int conteudo;
	char info;
}celula;

typedef struct ListaSEQ{
	int cont;
	celula dados[MAX];
}ListaSEQ;


ListaSEQ *cria_lista ()
{
	ListaSEQ *l;
	l = (ListaSEQ*) malloc(sizeof(ListaSEQ));
	if(l != NULL)
	{
		l->cont = 0;
	}
	return l;
}

int tamanho_lista(ListaSEQ *l)
{
	if(l == NULL)
	{
		return -1;
	}
	else
	{
		return (l->cont);
	}
}

int lista_cheia (ListaSEQ *l)
{
	if(l == NULL)
	{
		return -1;
	}
	return(l->cont == MAX);       //lista cheia
}

int lista_vazia (ListaSEQ *l)
{
	if(l == NULL)
	{
		return -1;
	}
	return (l->cont == 0);
}

int insere_inicio (ListaSEQ *l, celula A)
{
	int i;

	if(l == NULL)
	{
		return 0;
	}
	if(lista_cheia(l))
	{
		return 0;
	}
	for(i=l->cont-1; i>=0; i--)
	{
		l->dados[i+1] = l->dados[i];
	}

	l->dados[0] = A;
	l->cont++;
	return 1;
}

int insere_final(ListaSEQ *l, celula A)
{
	if(l == NULL)
	{
		return 0;
	}
	if(lista_cheia(l))
	{
		return 0;
	}

	l->dados[l->cont] = A;
	l->cont++;
	return 1;
}



/*
//ordenação por chave
void SelectionSort(lista *L)
{
    int i, j;
    elem aux;
    for(i = 1; i <= L->nElem - 1; i++)
    {
        for(j = i + 1; j <= L->nElem; j++)
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
*/
/*
//insere por chave de forma ordenada.
int inserirOrdenado(lista *L, elem *x, int chave)
{
    if(L->nElem == 0)
    {
        Inserir(L, x, 1);
        return 1;
    }
    else
    {
        int atual;
        if(L->A[L->nElem].chave < chave)
        {
            Inserir(L, x, (L->nElem + 1));
            return 1;
        }
        else
        {
            for(atual=L->nElem; atual >= 1; atual--)
            {
                L->A[atual+1] = L->A[atual];
                if(L->A[atual].chave > chave && L->A[atual-1].chave < chave)
                {
                    L->A[atual]= *x;
                    L->nElem++;
                    return 1;
                }
            }
        }

    }
    return -1;
}
*/
/*

//imprime igual por chave.
void imprimirIguais2(lista *L1, lista *L2)
{
    if(L1->nElem == 0 && L2->nElem == 0)
    {
        printf("\nNao ha elementos para imprimir.\n");
    }
    int atual;
    int atual2;
    for(atual = 1; atual <= L1->nElem; atual++)
    {
        for(atual2 = 1; atual2 <= L2->nElem; atual2++)
        {
            if(L1->A[atual].chave == L2->A[atual2].chave)
            {
                printf("\nElemento:%d \tPosicao L1:%d \tPosicao L2:%d\n", L1->A[atual].chave, atual, atual2);
            }
        }
    }
}
*/
/*
//questão 6.
void removerDuplicados(lista *L)
{
    if(L->nElem == 0)
    {
        printf("\nNao ha elementos para remover.\n");
    }
    int atual;
    int atual2;
    for(atual = 1; atual <= L->nElem; atual++)
    {
        for(atual2 = atual + 1; atual2 <= L->nElem; atual2++)
        {
            if(L->A[atual].chave == L->A[atual2].chave)
            {
                Remover(L, atual2);
            }
        }
    }
}
*/

/*
int trocarPosicao(lista *L, int p, int q)
{
    elem aux;
    int atual;
    if(p < 1 || p > L->nElem || q < 1 || q > L->nElem)
    {
        return -1;
    }
    else
    {
        aux = L->A[p];
        //Remover(L, p);
        //Inserir(L, &aux, q);
        //return 1;
        if(q > p)
        {
            for(atual = p; atual < q; atual++)
            {
                L->A[atual] = L->A[atual + 1];
            }
            L->A[atual] = aux;
            return 1;
        }
        else if(q < p)
        {
            for(atual = p; atual > q; atual--)
            {
                L->A[atual] = L->A[atual - 1];
            }
            L->A[atual] = aux;
            return 1;
        }
    }
}
*/
void apaga_lista (ListaSEQ *l)
{
	free(l);
}

int main (void)
{
    ListaSEQ *A,*B;
    A=cria_lista();
    B=cria_lista();
    char str1[100],str2[100];
    int i=0,j=0;
    celula a,b;
    int t1,t2,n;

    scanf("%s",&str1);
    scanf("%s",&str2);

    for(i=0;str1[i]!='\0';i++)
    {
        a.conteudo=str1[i];
        insere_final(A,a);
    }
    for(i=0;str2[i]!='\0';i++)
    {
        b.conteudo=str2[i];
        insere_final(B,b);
    }
    t1=tamanho_lista(A);
    t2=tamanho_lista(B);
	for(i =0 ; i < t1; i++)
	{
		for(j = 0; j < t2; j++)
		{
			if(A->dados[i].conteudo == B->dados[j].conteudo)
			{
				n=0;
				
			}
			else if(A->dados[i].conteudo > B->dados[j].conteudo)
			{
				n=1;
				return printf("A maior que B");
				
				
			}
			else
			{
				n=-1;
				return printf("A menor que B");
                
				
			}
		}
	}
	
    if(n==0)
    {
        printf("A igual a B");
    }
    return 0;

}

