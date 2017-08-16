#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_SIZE_NOME 20

#ifndef NUM_PESSOAS
  #define NUM_PESSOAS 5163
#endif

typedef struct {
	int idade;
	long cpf;
	char nome[MAX_SIZE_NOME];
} Pessoa;



void ler_pessoa(Pessoa* p)
{
	scanf("%s%d%ld", p->nome, &(p->idade), &(p->cpf));
}

int main()
{
	Pessoa p;
	
	ler_pessoa(&p);
}
