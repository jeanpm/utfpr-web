#include <stdio.h>

#define CAPACIDADE 100	

int h(long key)
{
	return key % CAPACIDADE;
}

int rh(int hash_ra)
{
	return (hash_ra + 1) % CAPACIDADE;
}

// Tratamento de colisões por reespalhamento
// Teste linear ou endereçamento aberto.
int inserir(long tabela_hash[], long ra)
{
	int hash_ra = h(ra);
	
	int n_ocupadas = 0;
	while ( tabela_hash[hash_ra] > 0  && n_ocupadas < CAPACIDADE)
	{
		hash_ra = rh(hash_ra);
		n_ocupadas++;
	}
	
	if (n_ocupadas < CAPACIDADE) {
		tabela_hash[hash_ra] = ra;
		return 1;
	}
		
	return -1;
}

int main()
{

	long tabela_hashA[CAPACIDADE];
	long tabela_hashB[CAPACIDADE];
	long tabela_hashC[CAPACIDADE];
	int contTabelaC = 0;
    int qnt, j;
    long num;
	
	for (int i = 0; i < CAPACIDADE; i++)
	{
		tabela_hashA[i] = -1;
		tabela_hashB[i] = -1;
		tabela_hashC[i] = -1;
	}
    
    scanf("%d", &qnt);
    for(int i=0; i<qnt; i++)
    {
        scanf("%ld", &num);
        inserir(tabela_hashA, num);
    }
    scanf("%d", &qnt);
    for(int i=0; i<qnt; i++)
    {
        scanf("%ld", &num);
        inserir(tabela_hashB, num);
    }
	for (int i = 0; i < CAPACIDADE; i++)
	{
		if(tabela_hashA[i] == tabela_hashB[i] && tabela_hashA[i] != -1)
		{
			j=tabela_hashA[i];
			inserir(tabela_hashC, j);
            printf("%ld\n",tabela_hashC[i]);
		}
    }
}

/* Enter your code here. Read input from STDIN. Print output to STDOUT */
