#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

#define CAPACIDADE 1021

struct aluno
{
	long elemento;
};
int h(long chave)
{
	return chave % CAPACIDADE;
}

long rh(long hash_n)
{
	return (hash_n + 1) % CAPACIDADE;
}
bool inserir(list<aluno>* s[], long elemento)
{
	long hash_n= h(elemento);
    int cont=0;
	int n_ocupadas = 0;
	while (s[hash_n] > 0  && n_ocupadas < CAPACIDADE)
	{
		hash_n = rh(hash_n);
		n_ocupadas++;
	}

	if (n_ocupadas <= CAPACIDADE)
    {
        aluno a;
        a.elemento= elemento;
        for(list<aluno>::iterator it= s[hash_n]->begin();it!= s[hash_n]->end();it++)
        {
            if(it->elemento==a.elemento)
            {
                cont++;
            }
        }
        if(cont==0)
        {
            s[hash_n]->push_front(a);
            return true;
        }
	}
	return false;
}
void intersecao(list<aluno>* La[],list<aluno>* Lb[],list<aluno>* Resulta[])
{
    for(int i=0;i<CAPACIDADE;i++)
    {

        for(list<aluno>::iterator it=La[i]->begin();it != La[i]->end();it++)
        {

            for(list<aluno>::iterator itB=Lb[i]->begin(); itB!= Lb[i]->end();itB++){
                    if(it->elemento==itB->elemento){
                        aluno a;
                        a.elemento=it->elemento;
                        inserir(Resulta,a.elemento);
                    }
            }
        }
    }
}
int main()
{
    char nome[100];
    long matricula;
    int i,antivirg;
    int a,capacidade;
    long n;
    list<aluno>* tabela_hash1[CAPACIDADE];
    list<aluno>* tabela_hash2[CAPACIDADE];
    list<aluno>* Resultado[CAPACIDADE];
    for(i=0;i<CAPACIDADE;i++)
    {
        tabela_hash1[i] = new list<aluno>;
        tabela_hash2[i] = new list<aluno>;
        Resultado[i] = new list<aluno>;
    }
    cin>>capacidade;
    for(i=0;i<capacidade;i++)
    {
        cin>>n;
        a= inserir(tabela_hash1,n);
    }
    cin>>capacidade;
    for(i=0;i<capacidade;i++)
    {
        cin>>n;
        a= inserir(tabela_hash2,n);
    }
    intersecao(tabela_hash1,tabela_hash2,Resultado);
    for(i=0;i<CAPACIDADE;i++)
    {
        for(list<aluno>::iterator it=Resultado[i]->begin();it != Resultado[i]->end();it++)
        {
            cout<<it->elemento<<" ";

        }
    }
    cout << endl;
    return 0;
}


