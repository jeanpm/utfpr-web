#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE_NOME 20

#ifndef NUM_PESSOAS
  #define NUM_PESSOAS 5163
#endif

typedef struct {
	int idade;
	long cpf;
	char nome[MAX_SIZE_NOME];
} Pessoa;

void print_lista(Pessoa p[])
{
	for (int i = 0; i < NUM_PESSOAS; i++)
		printf("nome = %s,\tidade = %d,\tcpf = %ld\n", 
			p[i].nome, p[i].idade, p[i].cpf);
}

float media_idade(Pessoa p[])
{
	float media = 0.0;
	for (int i = 0; i < NUM_PESSOAS; i++)
		media += p[i].idade;
		
	return media/NUM_PESSOAS;
}

float desvio_padrao_idade(Pessoa p[])
{
	float media = media_idade(p);
	float sd = 0;
	for (int i = 0; i < NUM_PESSOAS; i++)
		sd += (p[i].idade - media) * (p[i].idade - media);
	return sqrt(sd/NUM_PESSOAS);
}

void gerar_nova_entrada(Pessoa p[])
{
	int max_idade = rand() % 60;
	for (int i = 0; i < NUM_PESSOAS; i++) {
		int idade = rand() % max_idade;
		printf("%-15s\t%d\t%ld\n", p[i].nome, idade, p[i].cpf);
	}
}

int main(int argc, char** argv)
{
	assert(argc > 1);
	
	srand(time(NULL));
	
	int option = atoi(argv[1]);
	
	Pessoa lista[NUM_PESSOAS] = {0};
	
	for (int i = 0; i < NUM_PESSOAS; i++)
		scanf("%s%d%ld", lista[i].nome, &lista[i].idade, &lista[i].cpf);

	// option
	switch (option) {
		case 0 : gerar_nova_entrada(lista); break;
		case 1 : printf("%f", media_idade(lista)); break;
		case 2 : printf("%f", desvio_padrao_idade(lista)); break;
	}
	
	return 0;
}


