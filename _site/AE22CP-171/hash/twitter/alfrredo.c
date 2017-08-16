#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
// valor = 0.7 * max --> palavra mais frequente.

typedef struct Palavra
{
	long quantidade;
    char nome[200];
    struct Palavra *prox;
    struct Palavra *ant;
}Palavra;

typedef struct Lista
{
	Palavra *inicio;
	Palavra *fim;
	int tamanho;
}Lista;

Lista* novaLista() // CHECK
{
	Lista *l = (Lista*) malloc(sizeof(Lista));
	l->inicio = NULL;
	l->fim = NULL;
	l->tamanho = 0;
	return l;
}

Palavra *novaPalavra(char nome[]) // CHECK
{
	Palavra *A = (Palavra*) malloc(sizeof(Palavra));
	A->quantidade = 0;
	strcpy(A->nome, nome);
	A->prox = NULL;
	A->ant = NULL;
	return A;
}

void inserirFim(Lista *l, Palavra *novo)
{
	if (l->fim == NULL)
    {
        if (l->inicio == NULL)
        {
            l->inicio = novo;
            l->fim = l->inicio;
        }
        else
        {
            l->inicio->ant = novo;
            novo->prox = l->inicio;
            l->inicio = novo;
        }
	}
	else
    {
		l->fim->prox = novo;
		novo->ant = l->fim;
		l->fim = novo;
		l->fim->prox = NULL;
	}
	l->tamanho++;
}

long sbdm(char nome[], long CAPACIDADE)
{
	long hash = 0;
        int c;

        while ((c = *nome++))
            hash = c + (hash << 6) + (hash << 16) - hash;

        return abs(hash) % CAPACIDADE;
}

int inserir(Lista *tabelaHash[], char nome[], int CAPACIDADE)
{
    int valida=0; // ~~~~~~~~~~~~~~~~~~~~~~~~~~ TIRAR DPS
    int Hash = sbdm(nome, CAPACIDADE);
    Palavra *p = tabelaHash[Hash]->inicio;

    while(p != NULL)  // pq n funfa assim: while(p != NULL || (strcmp(p->nome, nome) == 0))
    {
        if((strcmp(p->nome, nome) == 0))
        {
            p->quantidade++;
            valida=1; // ~~~~~~~~~~~~~~~~~~~~~~~~~~ TIRAR DPS
        }
        p = p->prox;
    }
    if(valida == 0) // n gostei === ARRUMAR PARA O CASO DE CIMA
    {
        Palavra *A = novaPalavra(nome);
        inserirFim(tabelaHash[Hash], A);
    }
    return 1;
}

void ImprimiLista(Lista *L[], int i)
{
    if(L[i]->inicio != NULL)
    {
        Palavra *A = L[i]->inicio;
        while(A != L[i]->fim)
        {
            printf("(%s, %ld), ", A->nome, A->quantidade);
            A = A->prox;
        }
        printf("(%s, %ld)\n", A->nome, A->quantidade);
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ REMOVER

Palavra* removerInicio(Lista* l)
{
	assert(l->tamanho > 0);

	Palavra* removed = NULL;

	if (l->tamanho == 1)
	{
		removed = l->inicio;
		l->inicio = NULL;
		l->fim = NULL;
	}
	else
    {
		removed = l->inicio;
		l->inicio = removed->prox;
		l->inicio->ant = NULL;
	}
	l->tamanho--;
	return removed;
}

Palavra* removerFim(Lista* l)
{
	assert(l->tamanho > 0);

	Palavra* removed = NULL;

	if (l->tamanho == 1)
	{
		removed = l->fim;
		l->fim = NULL;
		l->inicio = NULL;
	} else {
		removed = l->fim;
		l->fim = removed->ant;

		l->fim->prox = NULL;
	}
	l->tamanho--;

	return(removed);
}

void removerItem(Lista* lista, Palavra* escolhido)
{
	if(escolhido == lista->inicio)
    {
        removerInicio(lista);
    }
    else if(escolhido == lista->fim)
    {
        removerFim(lista);
    }
	else
    {
		// Se não é início nem fim, o item possui antecessor e sucessor.
		// Então basta atualizar os ponteiros, removendo-o da lista.
		Palavra* aux;
		Palavra* aux2;
		aux = escolhido->ant;
		aux2 = escolhido->prox;
		aux->prox = aux2;
		aux2->ant = aux;
		lista->tamanho--;
	}
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MAIN

int main(void)
{
    int CAPACIDADE, i;
    char String[200];
    long palavras;

    scanf("%ld", &palavras);
    CAPACIDADE = palavras/50; // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~arrumar dps de terminar teste 50

    Lista *Tabela_Hash[CAPACIDADE]; // Declaração da tabelaHash depois da declaracao do tamanho
    for(i=0 ; i<CAPACIDADE ; i++) // seta NULL
    {
        Tabela_Hash[i] = novaLista();
    }

    for(i=0 ; i<palavras ; i++)
    {
        scanf("%s", String);
        inserir(Tabela_Hash, String, CAPACIDADE);
    }

    long maior=0;
    for(i=0 ; i<CAPACIDADE ; i++)
    {
        //printf("%d:", i);
        //ImprimiLista(Tabela_Hash, i);
        //printf("\n");

        Palavra *P = Tabela_Hash[i]->inicio;
        while(P != NULL)
        {
            if(maior < P->quantidade)
            {
                maior = P->quantidade;
            }
            P = P->prox;
        }
    }
    //printf("\n\nMaior: %ld\n", maior);

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~REMOVE
    long valor = maior * 0.7;
    for(i=0 ; i<CAPACIDADE ; i++)
    {
        Palavra *P = Tabela_Hash[i]->inicio;
        while(P != NULL)
        {
            if(P->quantidade < valor)
            {
                removerItem(Tabela_Hash[i], P);
            }
            P = P->prox;
        }
    }

    // ~~~~~~~~~~~~~~~~~~~~~PRINTA DNV
    for(i=0 ; i<CAPACIDADE ; i++)
    {
        ImprimiLista(Tabela_Hash, i);
//        printf("\n");
    }
}


