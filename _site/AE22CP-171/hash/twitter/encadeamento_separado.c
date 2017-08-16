#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <iostream>

using namespace std;

#define MAX_STR_SIZE 200

typedef struct _item
{
	long quantidade;
	char nome[MAX_STR_SIZE];
	struct _item* prox;
	struct _item* ant;
} Palavra;


typedef struct
{
	Palavra* inicio;
	Palavra* fim;
	int tamanho;
} Lista;



Lista* novaLista()
{
	Lista* l = (Lista*) malloc(sizeof(Lista));
	l->inicio = NULL;
	l->fim    = NULL;
	l->tamanho = 0;
	
	return l;
}

Palavra* novaPalavra(char* nome)
{
	Palavra *i = (Palavra*) malloc(sizeof(Palavra));
	i->quantidade = 1;
	strncpy(i->nome, nome, MAX_STR_SIZE);
	i->prox  = NULL;
	i->ant  = NULL;
	return i;
}


// =============================================================================

void inserirInicio(Lista* l, Palavra* novo)
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


void inserirFim(Lista* l, Palavra* novo)
{
	// Se lista vazia
	if (l->fim == NULL) {
		inserirInicio(l, novo);
	} else {
		l->fim->prox = novo;
		novo->ant = l->fim;
		l->fim = novo;
		l->fim->prox = NULL;
	
		l->tamanho++;
	}
}

Palavra* removerInicio(Lista* l)
{
	assert(l->tamanho > 0);
	
	Palavra* removed = NULL;
	
	if (l->tamanho == 1)
	{
		removed = l->inicio;
		l->inicio = NULL;
		l->fim = NULL;
	} else {
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
	
	return removed;
}

void removerItem(Lista* lista, Palavra* i)
{
	if (i == lista->inicio)
		removerInicio(lista);
	else if (i == lista->fim)
		removerFim(lista);
	else {
		// Se não é início nem fim, o item possui antecessor e sucessor.
		// Então basta atualizar os ponteiros, removendo-o da lista.
		i->ant->prox = i->prox;
		i->prox->ant = i->ant;
		
		lista->tamanho--;
	} 
}


// =============================================================================

// Imprime e retorna a palavra com maior numero de ocorrencias
Palavra* printLista(Lista* l)
{
	Palavra* mais_frequente = l->inicio;
	
	Palavra* curr = l->inicio;
	long max_freq = 0;
	while(curr != NULL && curr != l->fim)
	{
		if (curr->quantidade > max_freq)
		{
			max_freq = curr->quantidade;
			mais_frequente = curr;
		}
		printf("(%s, %ld), ", curr->nome, curr->quantidade); 
		curr = curr->prox;
	}
	printf("\n");
	return mais_frequente;
}



// =============================================================================

void freeLista(Lista* l)
{
	while (l->inicio != NULL)
		free(removerInicio(l));
}

void freeTable(Lista** thash, int capacidade)
{
	for (int i = 0; i < capacidade; i++) {
		freeLista(thash[i]);
		free(thash[i]);
	}
	free(thash);
}

long djb2(char nome[MAX_STR_SIZE])
{
	long hash = 5381;
	for (int i = 0; nome[i] != '\0'; i++)
		hash = ((hash << 5) + hash) + (int) nome[i];
	return abs(hash);
}	

long sbdm(char nome[MAX_STR_SIZE])
{
	long hash = 0;
        int c;

        while ((c = *nome++))
            hash = c + (hash << 6) + (hash << 16) - hash;

        return abs(hash);
}	


long h(long matricula)
{
	return matricula;
}

long h_string(char nome[MAX_STR_SIZE])
{
	int c = 0;
	
	int n_len = strlen(nome);
	for (int i = 0; nome[i] != '\0'; i++)
		c = c +  (n_len - i) * (int) nome[i];
	
	return c;
}

void inserirProximo(Lista* l, Palavra* atual, Palavra* novo)
{
	assert(atual->prox != NULL);

	novo->prox = atual->prox;
	novo->ant = atual;

	atual->prox->ant = novo;
	atual->prox = novo;
		
	l->tamanho++;
}


int inserir(Lista** thash, int cap, char nome[MAX_STR_SIZE])
{
	int hvalue;
	
//	hvalue = h(matricula) % cap;
//	hvalue = h_string(nome) % cap;
//	hvalue = djb2(nome) % cap;	
	hvalue = sbdm(nome) % cap;
	
	Palavra* ptr = thash[hvalue]->inicio;
	
	while (ptr != NULL && strcasecmp(ptr->nome, nome) != 0)
		ptr = ptr->prox;	
	
	if (ptr != NULL && strcasecmp(ptr->nome, nome) == 0)
		ptr->quantidade++;
	else {
		Palavra* tmp = novaPalavra(nome);
		inserirFim(thash[hvalue], tmp);
	}
		
	return hvalue;
}

void imprimirTabelaHash(Lista** thash, int capacidade)
{
	double avg_len = 0.0;
	int non_zero = 0;
	
	Palavra* max_freq = NULL;
	long max_freq_idx = 0;
	long max_freq_val = 0;
	
	for (int i = 0; i < capacidade; i++) {		
		if (thash[i]->inicio != NULL)
		{	
			printf("%7d:", i);
			Palavra* curr = thash[i]->inicio;
			while(curr != NULL)
			{
				if (curr->quantidade > max_freq_val)
				{
					max_freq_val = curr->quantidade;
					max_freq = curr;
					max_freq_idx = i;
				}
				printf("(%s, %ld), ", curr->nome, curr->quantidade); 
				curr = curr->prox;
			}
				
			avg_len += thash[i]->tamanho;
			++non_zero;
			printf("\n");
		} 
	}
	printf("avg length = %f\n", avg_len / non_zero);
	printf("%ld:%s %ld\n", max_freq_idx, max_freq->nome, max_freq->quantidade);
}

long maiorFrequencia(Lista** thash, int capacidade)
{
	long max_freq_val = 0;
	
	for (int i = 0; i < capacidade; i++) {		
		if (thash[i]->inicio != NULL)
		{	
			Palavra* curr = thash[i]->inicio;
			while(curr != NULL)
			{
				if (curr->quantidade > max_freq_val)
					max_freq_val = curr->quantidade;
				curr = curr->prox;
			}			
		} 
	}
	return max_freq_val;
}



void filtrar(Lista** thash, int capacidade, int min)
{
	for (int i = 0; i < capacidade; i++) 
	{
		if (thash[i]->tamanho > 0)
		{	
			Palavra* curr = thash[i]->inicio;
			while(curr != NULL)
			{
				Palavra* tmp = curr;
				curr = curr->prox;
				if (tmp->quantidade < min || strcasecmp(tmp->nome, "RT")==0)
				{
					removerItem(thash[i], tmp);
					free(tmp);
				}
			}
		} 
	}
}


int main()
{
	int n; 	// Número de palavras no arquivo.
	
	// C++: Leitura de dois inteiros 
	cin >> n;
	
	// Capacidade da tabela hash. Assumindo-se espalhamento uniforme, este 
	// tamanho produziria listas de tamanho 5, em média.
	const int capacidade = n/50; 

	// Aloca um vetor de 'Palavra', contendo 'capacidade' posições.
	Lista** thash = (Lista**) malloc(sizeof(Lista*) * capacidade);
	for (int i = 0; i < capacidade; i++) 
		thash[i] = novaLista();

	char nome[MAX_STR_SIZE];
	
	for (int i = 0; i < n; i++) 
	{
		// C++: Leitura de um long e uma string (sem espaços)
		cin >> nome;
		
		// Inserir um novo elemento na tabela hash 'thash'
		inserir(thash, capacidade, nome);
	}
//	printLista(listaOrdenada(thash, capacidade));
	long maximo = maiorFrequencia(thash, capacidade);
	filtrar(thash, capacidade, maximo * 0.5);
	imprimirTabelaHash(thash, capacidade);
	freeTable(thash, capacidade);
}

