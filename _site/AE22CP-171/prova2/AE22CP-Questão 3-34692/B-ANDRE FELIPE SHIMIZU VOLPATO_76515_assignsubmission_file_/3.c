/*Resposta Da quest�o B
Na estrutura estatica tinhamos de definir um MAX para uma dala lista, j� na dinamica utilizamos o malloc para uma aloca��o dinamica tomando assim menos espa�o na memoria.
Outro ponto interesante e que quando realizarmos a uni�o as duas Listas nao precisamos copiar seus valores, apenas fazemos com que seu se valor "aponte" para o prox ou para seu "anterior".
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>


typedef struct _Item Item;
typedef struct _Lista Lista;

struct _Item
{
	int valor;
	struct _Item* prox;
	struct _Item* ant;
};


struct _Lista
{
	Item* inicio;
	Item* fim;
	int tamanho;
};
