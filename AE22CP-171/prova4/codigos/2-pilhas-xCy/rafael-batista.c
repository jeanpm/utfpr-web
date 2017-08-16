#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct Elemento
{
	char vInfo;
	struct Elemento *pAnterior;
}tsElemento;

typedef struct
{
    tsElemento *pFim;
    int vTamanho;
} tsPilha;

void criapilha(tsPilha *vPilha)
{
    vPilha->pFim = NULL;
    vPilha->vTamanho = 0;
}

tsElemento *CriaElemento(char vInfo){

	tsElemento *pElemento = malloc(sizeof(tsElemento));

	pElemento->vInfo = vInfo;

	return pElemento;
}

void Insere(tsPilha string, char A[])
{   
	int i = 0; 

	while (A[i] != '\0')
	{
		string.pFim = A[i];
		string.vTamanho++;
		i++;
	}
}

int palindromo(char *A)
{
	int x=0, y=0, i=0;
	while (A[i] != '\0')
	{
		i++;
		if (A[i] == 'C')
		{
			x = i;
		}

	}
	i = i-1;
	
	y = i-x;

	if (x != y)
	{
		printf ("NÃO\n");
		return 0;
	}

	for (x=0; x<i; x++)
	{
		if (A[x] != A[i])
		{
			printf ("NÃO\n");
			return 0;
		}
	i--;

	}
	printf ("SIM\n");
}

int main (void)
{
	char A[100];
	gets (A);
	tsPilha string;
	
	Insere (string, A);

	palindromo (A);

}

