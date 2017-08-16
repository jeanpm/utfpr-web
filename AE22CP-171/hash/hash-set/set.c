#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE 1021


typedef struct _Item Item;
typedef struct _Lista Lista;

struct _Item
{
    long valor;
    Item* prox;
    Item* ant;
};


struct _Lista
{
    Item* inicio;
    Item* fim;
    int tamanho;
};


typedef struct
{
    Lista* tabela_hash[CAPACIDADE];
    long n_elementos;
} Set;


Set* intersecao(Set* a, Set* b)
{
    Set* u = novoSet();
    for (int i = 0; i < CAPACIDADE; i++)
    {
        Item* curr = a->tabela_hash[i]->inicio;
        while (curr != NULL) {
            if (get(b, curr->valor) > 0)
                inserir(u, curr->valor);
            curr = curr->prox;
        }
    }
    return u;
}



Lista* novaLista()
{
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->inicio = NULL;
    l->fim    = NULL;
    l->tamanho = 0;

    return l;
}

Item* novoItem(int value)
{
    Item *i = (Item*) malloc(sizeof(Item));
    i->valor = value;
    i->prox  = NULL;
    i->ant  = NULL;
    return i;
}

void inserirInicio(Lista* l, Item* novo)
{
    // Se lista vazia
    if (l->inicio == NULL) {
        l->inicio = novo;
        l->fim = l->inicio;
    } else {
        l->inicio->ant = novo;
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    l->tamanho++;
}


Set* novoSet()
{
    Set* s = (Set*) malloc(sizeof(Set));
    s->n_elementos = 0;

    for (int i = 0; i < CAPACIDADE; i++)
        s->tabela_hash[i] = novaLista();

    return s;
}



int h(long key)
{
    return key % CAPACIDADE;
}


long get(Set* s, long ra)
{
    int hash_ra = h(ra);

    Item* curr = s->tabela_hash[hash_ra]->inicio; 

    while (curr != NULL) {
        if (curr->valor == ra) 
            return curr->valor;
        curr = curr->prox;		
    }

    return -1;
}

// Tratamento de colisões por encadeamento.
// Elementos com chaves repetidas não são inseridos.
int inserir(Set* s, long ra)
{
    int hash_ra = h(ra);

    Item* curr = s->tabela_hash[hash_ra]->inicio; 

    while (curr != NULL) {
        if (curr->valor == ra) return -1;
        curr = curr->prox;		
    }

    inserirInicio(s->tabela_hash[hash_ra], novoItem(ra));
    s->n_elementos++;

    return 1;
}

Set* uniao(Set* a, Set* b)
{	
    Set* u = novoSet();
    for (int i = 0; i < CAPACIDADE; i++)
    {
        Item* curr = a->tabela_hash[i]->inicio;
        while (curr != NULL) {
            inserir(u, curr->valor);
            curr = curr->prox;
        }
        curr = b->tabela_hash[i]->inicio;
        while (curr != NULL) {
            inserir(u, curr->valor);
            curr = curr->prox;
        }
    }
    return u;
}


void printSet(Set* s)
{
    //	printf("{");
    for (int i = 0; i < CAPACIDADE; i++)
    {		
        if (s->tabela_hash[i]->inicio != NULL)
        {
            Item* curr = s->tabela_hash[i]->inicio;		
            while(curr != NULL)
            {
                fprintf(stdout, "%ld ", curr->valor); 
                curr = curr->prox;
            }
        }
    }
    printf("\n");
}

#include <math.h>
#include <time.h>

// Gera um arquivo de entrada aleatoriamente, para testar a função inserir.
void random_input_for_inserir(int max_len, int max_value)
{
    int set_size = rand() % max_len;
    printf("%d\n", set_size);
    while (set_size-- > 0) 
        printf("%d ", rand() % max_value);
    printf("\n");
}


// Gera um arquivo de entrada aleatoriamente, para testar a função uniao.
void random_input_for_uniao(int max_len, int max_value)
{
    int set_size = rand() % max_len;
    printf("%d\n", set_size);
    while (set_size-- > 0) 
        printf("%d ", rand() % max_value);
    printf("\n");

    set_size = rand() % max_len;
    printf("%d\n", set_size);
    while (set_size-- > 0) 
        printf("%d ", rand() % max_value);
    printf("\n");
}


void read_set(Set* s)
{
    int set_size;
    int set_item;
    scanf("%d", &set_size);
    while (set_size-- > 0) 
    {
        scanf("%d", &set_item);
        inserir(s, set_item);
    }
//    printSet(s);
}


int main()
{
    srand(time(NULL));

    Set* s = novoSet();
    Set* w = novoSet();


    // GERAR inputs	
//    random_input_for_inserir(1000, 200);
//    random_input_for_uniao(1000, 200);
    // FIM

    read_set(s);
    //printSet(s);
    read_set(w);		
    //printSet(w);

//    Set* u = uniao(s,w);
//    printSet(u);
    Set* i = intersecao(s,w);
    printSet(i);
}
