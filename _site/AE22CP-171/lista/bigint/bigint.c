
/*
Em geral, toda linguagem de programação possui um tipo de dados inteiro (int), 
que suporta operações básicas como: adição, subtração, multiplicação e divisão. 
Em grande parte dos computadores atuais, no entanto, essas operações são 
definidas somente para valores inteiros menores ou iguais a 2.147.483.647 
(INT_MAX). Deste modo, para aplicações específicas, em que valores maiores que 
INT_MAX precisem ser manipulados, o tipo int se torna inadequado. 

Uma forma alternativa de se representar inteiros maiores que INT_MAX, seria 
utilizar uma estrutura de dados lista, na qual cada item da lista armazene um 
único dígito (0-9) do inteiro em questão.

Utilize listas duplamente encadeadas para implementar a adição de inteiros 
grandes positivos!

	Lista* add(Lista* A, Lista* B);

Especificações:

Entrada:
	Considere que os inteiros grandes (positivos) estão incialmente armazenados
	em uma string cada.
	
	Ex.: 
		const char* x ="92233720368547758079223372036854775807"
     	const char* y ="2147483"

	Essas strings devem ser transformadas em listas por uma função.

	Lista* tolist(char* string);

Objetivo:

	Utilizar listas duplamente encadeadas como estrutura de dados para armazenar
	manipular inteiros grandes. 


Exemplo: 

	92233720368547758079223372036854775807
	+								     1
		
	92233720368547758079223372036854775808
*/
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>



//typedef struct _Item Item;
//typedef struct _Lista Lista;

typedef struct _item
{
	int valor;
	struct _item* prox;
	struct _item* ant;
} Item;


typedef struct _list
{
	Item* inicio;
	Item* fim;
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


void inserirFim(Lista* l, Item* novo)
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

Item* removerInicio(Lista* l)
{
	assert(l->tamanho > 0);
	
	Item* removed = NULL;
	
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


void printLista(Lista* l)
{
	if (l->inicio != NULL)
	{
		Item* curr = l->inicio;
		while(curr != l->fim)
		{
			fprintf(stdout, "%d", curr->valor); 
			curr = curr->prox;
		}
		fprintf(stdout, "%d", curr->valor); 
		fprintf(stdout, "\n");
	}
}


void freeLista(Lista* l)
{
	while (l->inicio != NULL)
		free(removerInicio(l));
}




Lista* tolist(char* x)
{
	int xlen = strlen(x);

	Lista* xlista = novaLista();
	for (int i = 0; i < xlen; i++)
	{
		int digito = (int) x[i] - '0';
		inserirFim(xlista, novoItem(digito));
	}
	return xlista;
}

/*

Condições:
	A lista A pode ser maior que a lista B, ou vice-versa;
Funcionamento:
	soma-se o item atual de A, o item atual de B e o carry
Exceção:
	1. Se A > B, os elementos que restarem de A serão somados apenas com o carry.
	2. Se ao fim de A, o carry ainda for > 0, ele é inserido na lista resultante.
*/
Lista* add(Lista* A, Lista* B)
{
	// Para identificar a maior lista.
	if (A->tamanho < B->tamanho)
		return add(B, A);
		
	Lista* result = novaLista();

	Item* acurr = A->fim;
	Item* bcurr = B->fim;

	int carry  = 0;
	int avalue = 0;
	int bvalue = 0;
	while (acurr != NULL)
	{	
		avalue = acurr->valor;
		bvalue = (bcurr != NULL) ? bcurr->valor : 0;
		
		int sum = (avalue + bvalue + carry) % 10;
		carry   = (avalue + bvalue + carry) / 10;
		inserirInicio(result, novoItem(sum));
		
		acurr = acurr->ant;
		bcurr = (bcurr != NULL) ? bcurr->ant : NULL;
	}
	
	if (carry > 0)
		inserirInicio(result, novoItem(carry));

	return result;
}

/*

Existe ainda outra forma de se fazer, sem utilizar listas temporárias,  para isso é preciso que a cada multiplicação atualize-se a lista que armazena os resultados parciais, até que todas multiplicações tenham sido feitas. 

   1 2 3                  
   x 1 1
   --------            R = 0 0 0 0 0 
   1 2 3              R = 0 0 1 2 3 
1 2 3 0              R = 0 1 3 5 3

Neste exemplo, quando eu multiplico o primeiro '1', o resultado dessa multiplicação já é somado com os valores que estão atualmente em R. Ao multiplicar o segundo '1', o resultado dessa multiplicação também é somado aos valores já em R. 

Por isso R é previamente inicializado como uma lista de tamanho |A| + |B|, preenchida por zeros. 

*/

Lista* mult(Lista* A, Lista* B)
{
	// Para identificar a maior lista.
	if (A->tamanho < B->tamanho)
		return add(B,A);

	// Inicializa a lista resultados com zeros
	Lista* result = novaLista();
	for (int i =0; i < A->tamanho + B->tamanho; i++)
		inserirInicio(result, novoItem(0));	

	Item* acurr = A->fim;
	Item* bcurr = B->fim;
	
	Item* cnext = result->fim;
	Item* ccurr = result->fim;

	int carry  = 0;
	int avalue = 0;
	int bvalue = 0;
	
	// Percorre a lista menor
	while (bcurr != NULL)
	{	
		bvalue = bcurr->valor;
		acurr  = A->fim;
		ccurr  = cnext;
		carry  = 0;
		
		// Percorre a lista maior
		while (acurr != NULL)
		{		
			avalue = acurr->valor;
		
			// Soma-se ao resultado anterior mais o possível carry. 
			int mult = avalue * bvalue + ccurr->valor + carry;
			
			ccurr->valor = mult % 10;
			carry = mult / 10;
		
			acurr = acurr->ant;
			ccurr = ccurr->ant;
		}
		
		if (carry > 0) 
			ccurr->valor += carry;
		
		bcurr = bcurr->ant;
		cnext = cnext->ant; 
	}
	
	if (result->inicio->valor == 0)
		removerInicio(result);	

	return result;
}

int main(int argc, char** argv)
{
	char* x = (char *)malloc(512000 * sizeof(char));
    char* y = (char *)malloc(512000 * sizeof(char));
    scanf("%s %s", x, y);

//	long al = atol(strA);
//	long bl = atol(strB);

	Lista* A = tolist(x);
	Lista* B = tolist(y);

	Lista* r = mult(A, B);
//	printf("%ld\n", al * bl);
	printLista(r);
}
