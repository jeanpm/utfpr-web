#include<stdio.h>
#define CAPACIDADE 1021

typedef struct Lista{
    long elemento;
}Lista;

int fHash(long elem)
{
    return elem%CAPACIDADE;
}

int inserir(Lista s[], long elem)
{
    //0 para sucesso
    //-1 para erro
    int repetido=0,i;
    
// Não se deve percorrer toda a tabela hash para procurar repetidos!
    for(i=0;i<CAPACIDADE;i++)
    {
        if(s[i].elemento==elem)repetido++;
    }

    if(s[fHash(elem)].elemento==-1&&repetido==0)
    {
        s[fHash(elem)].elemento=elem;
        return 0;
    }
    else if(repetido==0)
    {
        i=fHash(elem);
        while(s[i].elemento!=-1)
        {
            i++;
            if(i<=CAPACIDADE)i=0;
        }
        return 0;
    }
    return -1;
}

void inicializaLista(Lista s[])
{
    int i;
    for(i=0;i<CAPACIDADE;i++)
    {
        s[i].elemento=-1;
    }
}

int main()
{
    int qtd,i;
    long num;

    scanf("%d",&qtd);
//    fflush(stdin);
    Lista s[CAPACIDADE];

    inicializaLista(s);
//    fflush(stdin);
    
// INICIA EM ZERO, ENTÃO É < qtd    
//    for(i=0;i<qtd-1;i++)
	for (i=0; i < qtd; i++)
    {
        scanf("%ld",&num);
        inserir(s,num);
    }
    for(i=0;i<CAPACIDADE;i++)
    {
        if(s[i].elemento!=-1)printf("%ld ",s[i].elemento);
    }
}
