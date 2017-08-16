#include <stdio.h>
#include <stdlib.h>
#include <math.h> //compilar com: gcc source.c -o exec -lm

//typedef -- redefine o nome de um tipo de dado ex\:: typedef int inteiro;;
#define MAX_SIZE 20
#define NUM_PESSOA 5163


/*struct pessoa{
char nome[MAX_SIZE];
int idade;
long cpf;
};*/

typedef struct{
char nome[100];
int idade;
long cpf;
} pessoa;

void print_lista(pessoa p[])
{
	for(int i=0; i<	NUM_PESSOA; i++)
	printf("nome= %s\tidade= %i\tcpf= %ld\n",p[i].nome, p[i].idade, p[i].cpf);
}

float mmedia(pessoa p[])
{
    int i;
    float media = 0.0;
    for( i=0; i<NUM_PESSOA; i++)
    {
        media+= p[i].idade;
    }
    return (media/NUM_PESSOA);
}

float desvio(pessoa p[], int media)
{
    int i;
    float desvio_01=0.0;
    for(i=0; i<NUM_PESSOA; i++)
    {
        desvio_01 += (p[i].idade - media)*(p[i].idade - media);
    }
    
    return (sqrt(desvio_01/NUM_PESSOA));
}

void print_idade(pessoa p[], int idade)
{
    for(int i=0; i<NUM_PESSOA; i++)
    {
        if(p[i].idade==idade)
        {
            printf("nome= %s\tidade= %i\tcpf= %ld\n",p[i].nome, p[i].idade, p[i].cpf);
        }
    }
}

void maior_idade(pessoa p[])
{
    int i, maior, mm;
    for(i=0; i<NUM_PESSOA; i++)
    {
        if(i==0)
            maior=p[i].idade;
            
        else if(p[i].idade>maior)
        {
            maior=p[i].idade;
            mm=i;
        }
    }
    printf("nome= %s\tidade= %i\tcpf= %ld\n",p[mm].nome, p[mm].idade, p[mm].cpf);
    
}

void idade_par(pessoa p[])
{
    for(int i=0; i<NUM_PESSOA; i++)
    {
        if(p[i].idade%2==0)
        {
            printf("nome= %s\tidade= %i\tcpf= %ld\n",p[i].nome, p[i].idade, p[i].cpf);
        }
    }
}

int cpf_repetido(pessoa p[])
{
    for(int i=0; i<NUM_PESSOA; i++)
    {
        for(int j=0; j<NUM_PESSOA; j++)
        {
            if(i!=j)
            {
                if(p[i].cpf==p[j].cpf)
                {
                    return (1);
                }
            }
        }
    }
}

void contar(int freq[], pessoa p[])
{
    int cont;
    for(int i=0; i<100; i++)
    {
        cont=0;
        for(int j=0; j<NUM_PESSOA; j++)
        {
            if(i==p[j].idade)
                cont++;
        }
        freq[i]=cont;
    }
}

int main()
{

	//struct pessoa p[NUM_PESSOA];

	pessoa p[NUM_PESSOA];

	for(int i= 0; i<NUM_PESSOA; i++)
	{
		scanf("%s %i %ld", p[i].nome,& p[i].idade,& p[i].cpf);
	}
//	print_lista(p);

    printf("\n\nMedia de idade = %.3f", mmedia(p));
    printf("\nDesvio padrao da idade = %.3f",desvio(p,mmedia(p)));
    
    int k=20;
    printf("\n\nInsira idade: ");
    fflush(stdin);
    int result = scanf("%d", &k);
    if (result == EOF) {
    	clearerr(stdin);
    	result = scanf("%d", &k);
    }
   	
    printf("%d\n", result == EOF);
    

    
    print_idade(p,k);
return 0;
    
    printf("\n\n Maior idade::\n");
    maior_idade(p);
    printf("\n\n Idade par::\n");
    idade_par(p);

    if(cpf_repetido(p)==1)
        printf("\n\nCPF repetido\n");
    
    int freq[100];
    contar(freq,p);
    for(int i=0; i<100; i++)
    {
        printf("%i :: %i\n",i,freq[i]);
    }
    return 0;
}
