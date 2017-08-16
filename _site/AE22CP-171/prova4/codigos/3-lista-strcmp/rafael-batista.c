#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//Q U A L I D A D E

typedef struct Elemento
{
    int vChave;
    char vInfo[30];
    struct Elemento *pProximo;

} tsElemento;

typedef struct
{
    tsElemento *pInicio;
    int vTamanho;

} tsLDSE;

void CriaLDSE(tsLDSE *pLista) // Cria uma lista vazia
{
    pLista->pInicio = NULL;
    pLista->vTamanho = 0;
}


tsElemento *CriaElemento(int vChave, char vInfo[]){

	tsElemento *pElemento = malloc(sizeof(tsElemento));

	pElemento->vChave = vChave;
	strcpy(pElemento->vInfo, vInfo);

	return pElemento;
}

void Insere(tsLDSE *pLista, int vPosicao, tsElemento *pNovo)
{
    tsElemento *pAnterior;
    int cElementos = 1;

    if ((vPosicao > pLista->vTamanho) || (vPosicao < 0)) // Quando for inserir numa posicao que nao exista (maior que o tamanho da lista ou menor que zero)
    {
	free(pNovo);
	pNovo = NULL;
	printf("\nNao eh possivel inserir nesta posicao.\n");

    } else if ((pLista->vTamanho == 0) || (vPosicao == 0)) // Quando for inserir o/no primeiro elemento
    {
	pNovo->pProximo = pLista->pInicio; //
	pLista->pInicio = pNovo;           //
	pLista->vTamanho++;                // funcao InserePrimeiro

    } else
    {
	pAnterior = pLista->pInicio;

	while(cElementos < vPosicao)
	{
	    pAnterior = pAnterior->pProximo;
	    cElementos++;
	}

	pNovo->pProximo = pAnterior->pProximo;
	pAnterior->pProximo = pNovo;
	pLista->vTamanho++;

    }
}

void Remove(tsLDSE *pLista, int vPosicao)
{
    tsElemento *pAnterior, *pAtual;
    int cElementos = 1;

    pAnterior = pLista->pInicio;

    if((vPosicao >= pLista->vTamanho) || (vPosicao < 0) || (pLista->vTamanho == 0)) // Quando for remover uma posicao inexistente (maior que o tamanho da lista ou menor que zero ou lista vazia)
    {
	printf("\nO elemento nao existe e nao eh possivel remove-lo.\n");

    } else if(vPosicao == 0) // Quando for remover o primeiro elemento
    {
	pLista->pInicio = pAnterior->pProximo;
	free(pAnterior);
	pAnterior = NULL;
	pLista->vTamanho--;

    } else
    {
	while(cElementos < vPosicao)
	{
	    pAnterior = pAnterior->pProximo;
	    cElementos++;
	}

	pAtual = pAnterior->pProximo;
	pAnterior->pProximo = pAtual->pProximo;
	free(pAtual);
	pAtual = NULL;
	pLista->vTamanho--;

    }
}


int BuscaPorChave(tsLDSE *pLista, int vChave, tsElemento **ppElemento)
{
    if (pLista->vTamanho == 0)
    {
	return 0;
    } else
    {
	*ppElemento = pLista->pInicio;
	while(ppElemento != NULL)
	{
	    if((*ppElemento)->vChave == vChave)
	    {
		return 1;
	    }

	    *ppElemento = (*ppElemento)->pProximo;
	}
    }
    return 0;
}

void ImprimeLD(tsLDSE *vLista)
{
    if(vLista->vTamanho == 0)
    {
	printf("\nA lista nao contem nenhum elemento.");
    } else
    {
	tsElemento *pAux;
	pAux = vLista->pInicio;
	while(pAux != NULL)
	{
	    printf("Posicao: %d\n", pAux->vChave);
	    pAux = pAux->pProximo;
	}
    }
}

int ComparaLista (tsLDSE vLista1, tsLDSE vLista2)
{

	tsElemento *pAux1;
	tsElemento *pAux2;

	pAux1 = vLista1.pInicio;
	pAux2 = vLista2.pInicio;

	while ((pAux1 != NULL) || (pAux2 != NULL))
	{
		if (pAux1->vChave == pAux2->vChave)
		{
			pAux1 = pAux1->pProximo;
			pAux2 = pAux2->pProximo;	
		}
		else if (pAux1->vChave > pAux2->vChave)
		{
			printf ("A maior que B\n");
			return 0;
		}
		else if (pAux2->vChave > pAux1->vChave)
		{
			printf ("A menor que B\n");
			return 0;
		}
	}
	printf ("A igual a B\n");
	return 0;
}


int main(void)
{
    tsLDSE vLista1, vLista2;
    CriaLDSE(&vLista1);
    CriaLDSE(&vLista2);
	int i = 0;

	char string1[100], string2[100];


	gets (string1);
	gets (string2);

	while (string1[i] !='\0' || string2[i] != '\0')
	{
		i++;

	}

	while (i !=0)
	{

		i--;
		Insere(&vLista1, 0, CriaElemento (string1[i],"%c")), i, string1[i];
		Insere(&vLista2, 0, CriaElemento (string2[i],"%c")), i, string2[i];
	}

    ComparaLista (vLista1, vLista2);

}
