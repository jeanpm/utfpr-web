#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE_NOME 20


typedef struct {
	int idade;
	long cpf;
	char nome[MAX_SIZE_NOME];
} Pessoa;

// Passagem de referência usando ponteiros `Pessoa* p`
void ler_pessoa(Pessoa* p)
{
	scanf("%s%d%ld", p->nome, &(p->idade), &(p->cpf));
}

int main() {
	Pessoa w;
	
	ler_pessoa(&w);
}
