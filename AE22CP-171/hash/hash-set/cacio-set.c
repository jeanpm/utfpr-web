//questão 1 prova sub

#include <stdio_ext.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define CAPACIDADE 1021


typedef struct Item
{
    long  valor;
    struct Item* prox;
    struct Item* ant;
}Item;

typedef struct Lista
{
   struct Item* inicio;
    struct Item* fim;
    int qt;
}Lista;

typedef struct 
{
    Lista* tabela_hash[CAPACIDADE];
} Set;


//lista de funções 
Lista* novalista();
Item* novoItem(int valor);
void printLista(Lista* l);
void inserir(Lista* l[], long valor, int i);
Set* intersecao(Set* A, Set* B);
Set* Cc();
int hash(long h);
//*****************************MAIN

int main(int argc, char const *argv[])
{
    int i; 

    //Criando conjuntos
    Set* A;
    Set* B;

    //printf("antes de Cc\n");
    A = Cc();
    B = Cc();
    //printf("DCc\n");

    // Unindo os conjuntos
    
    Set* C = intersecao(A,B);
    //printf("depois de unir\n");

    for(i=0; i<CAPACIDADE; i++)
    {
        Lista* Ti = C->tabela_hash[i]; 
        //printf("definiu ponteiro\n");
        printLista(Ti);    
    }    
    
    return 0;
}

// funções
int hash(long h)
{
    return (h % CAPACIDADE);
}

//funções de conjunto
Set* Cc()
{
    Set* tmp;
    
    int i, qte, tmph;
    long num;;

    for (i=0; i<CAPACIDADE-1; i++)
    {
        Lista* Th = tmp->tabela_hash[i];
        Th = novalista();
    }

    scanf("%d", &qte);

    for (i=0; i<qte; i++)
    {
        scanf("%ld", &num);
        tmph = hash(num);
        Lista* Th = tmp->tabela_hash;
        inserir(Th,num,i);
        
    }

    return tmp;
}


//funções de listas
Lista* novalista()
{
    Lista* l = malloc(sizeof(Lista));
    l->inicio = NULL;
    l->fim    = NULL;
    l->qt = 0;
    
    return l;
}

Item* novoItem(int valor)
{
    Item *i = malloc(sizeof(Item));
    i->valor = valor;
    i->prox  = NULL;
    i->ant  = NULL;
    return i;
}

void inserir(Lista* l[], long valor, int i)
{
    //novo item a ser inserido
    Item* novo = novoItem(valor);

    // Se lista vazia
    if (l[i]->inicio == NULL) 
    {
        l[i]->inicio = novo;
        l[i]->fim = l[i]->inicio;
    } 
    
    // Se não estiver vazia, ocorreu colisão:
    else 
    {
        Item* aux;
        aux= l[i]->inicio; 
        //printf("criou e apontou para o inicio %ld\n",aux->valor);

        while (aux != NULL) 
        {
            if(aux->valor == valor)
            {
                return;
            }
            aux = aux->prox;
            //printf("aux avançou...\n");
        }

        l[i]->inicio->ant = novo;
        novo->prox = l[i]->inicio;
        l[i]->inicio = novo;
    }
        
    l[i]->qt++;
}

void printLista(Lista* l)
{
    Item* curr = l->inicio;
    while(curr != NULL)
    {
        fprintf(stdout, "%d ", curr->valor); 
        curr = curr->prox;
    }
    //fprintf(stderr, "\n");
}

Set* intersecao(Set* A, Set* B)
{
    int i;

    Set* U;
    for (i=0; i<CAPACIDADE; i++)
    {
        U->tabela_hash[i] = novalista();
    
        Item* v1 = A->tabela_hash[i]->inicio;
        int qta = A->tabela_hash[i]->qt;
        //printf("%d -> qta\n",qta );

        //Se o ponteiro apontar para NULL, então a lista na posição i esta vazia
        if (v1 != NULL)
        {
            //Se houver elementos na lista de A, testa a lista em B

            Item* v2 = B->tabela_hash[i]->inicio;
            int qtb = B->tabela_hash[i]->qt;
            //se houver itens em B, testa se há repetição de valor
            int k=0;
            while (v2 != NULL || k!=0)
            {
                if(v1->valor == v2->valor)
                {
                    Lista* Ti = U->tabela_hash[i];
                    inserir(Ti,v2->valor, i);
                    k=1;
                }
                else 
                {
                    v2 = v2->prox;
                }
            }
        }
    }

    return U;
}

