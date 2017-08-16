#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAPACIDADE 1021
typedef struct Aluno
{
    long elemento;
    struct Aluno* proximo;
    struct Aluno* anterior;

} Aluno;

typedef struct Lista
{
    Aluno* inicio;
    Aluno* fim;
    int tamanho;
}Lista;


Lista* NovaLista()
{
	Lista* l = (Lista*) malloc(sizeof(Lista));
	l->inicio = NULL;
	l->fim    = NULL;
	l->tamanho = 0;

	return l;
}

Aluno* NovoElemento(long elemento)
{
    Aluno *A = (Aluno*) malloc(sizeof(Aluno));

    A->elemento = elemento;

    A->proximo = NULL;
    A->anterior = NULL;

    return A;
}

int h(long matricula, int n)
{
    return matricula % n;
}

int rh(long h_mat, int n) {
    return (h_mat + 1) % n;
}

void InserirInicio(Lista *l, Aluno *novo)
{
    if(l->inicio == NULL)
    {
        l->inicio = novo;
        l->fim = l->inicio;
    }
    else
    {
        l->inicio->anterior = novo;
        novo->proximo = l->inicio;
        l->inicio = novo;
    }
    l->tamanho++;
}

void InserirFim(Lista* l, Aluno* novo)
{
    if(l->fim == NULL)
    {
        InserirInicio(l, novo);
    }
    else
    {
        l->fim->proximo = novo;
        novo->anterior = l->fim;
        l->fim = novo;
        l->fim->proximo = NULL;
        l->tamanho++;
    }
}

void Inserir(Lista** thash, long elemento, int n)
{
    int x = h(elemento,n);
    int cont=0;
    Aluno* aux = NovoElemento(elemento);


    while ( thash[x]->inicio->elemento != -1 && cont < n)
    {
      x = rh(x,n);
      cont++;
    }
    if (thash[x]->inicio->elemento == elemento)
    {
      InserirInicio(thash[x],aux);
      break;
    }

    if(cont <= n)
    {
      thash[x] ->inicio->elemento = aux;
    }
}


void PrintLista(Lista* l)
{
    Aluno* curr = l->inicio;
    while (curr != l->fim)
    {
        printf("%ld, ", curr->elemento);
        curr = curr->proximo;
    }
    printf("%ld\n", curr->elemento);
}

void PrintHash(Lista** th, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
      if(th[i]->inicio->elemento == -1)
         printf("%d\n", th[i]->inicio->elemento);
 }
}


int main()
{
    int capacidade;
    scanf("%d",&capacidade);

    Lista** thash = (Lista**) malloc(capacidade * sizeof(Lista*));

    long elemento;

    for(int i=0; i<capacidade; i++)
    {
        thash[i]=NovaLista();
        InserirInicio(thash[i],NovoElemento(-1));
    }

    for(int i=0; i<n; i++)
    {
        scanf("%ld",&elemento);
        Inserir(thash, elemento, capacidade);
    }

    PrintHash(thash, capacidade);

    return 0;
}

