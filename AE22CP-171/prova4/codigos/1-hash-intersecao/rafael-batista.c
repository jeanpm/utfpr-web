#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insere(int valor[], int quantidade)
{
	int i;
	for (i=0; i<quantidade; i++)
	{
		scanf ("%d ", &valor[i]);	
	}
}

int saoIguais(int saida[], int valor[], int quantidade)
{
    int i, k=0, j;

    for(i = 0;i < quantidade; i++)
    {
        for (j = i; k<quantidade; j++)
	{
		if (valor[i] == valor[j])
		{
			saida[k] = valor[j];
			k++;
		}
	}
    }
	quantidade = k;
    return 0;
}

int printaRepetido(int quantidade, int saida[])
{
    int i;

    for(i = 0; i<quantidade; i++)
    {
            printf("%d ", saida[i]);
    }
	printf ("\n");
}

int main()
{
	int i,quantidade;
	scanf ("%d", &quantidade);
	
	int valor [100];
	int saida[100];
	
	insere (valor, quantidade);
	
	saoIguais (saida, valor, quantidade);

	printaRepetido(quantidade, saida);
}
















