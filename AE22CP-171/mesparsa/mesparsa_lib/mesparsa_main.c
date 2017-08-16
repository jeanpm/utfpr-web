#include <assert.h>
#include <stdlib.h>  
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "mesparsa.h"

void info()
{
	printf("%15s %10s", "put i j x", "- insere o valor x na posição (i,j).\n");
	printf("%15s %10s", "get i j", "- obtém o valor da posição (i,j), zero se não existente.\n");
	printf("%15s %10s", "add_to_col j x", "- adiciona x aos elementos da coluna (,j).\n");
	printf("%15s %10s", "add_to_row i x", "- adiciona x aos elementos da linha (i,).\n");
	printf("%15s %10s", "print_col j", "- imprime os elementos não vazios da coluna (,j).\n");
	printf("%15s %10s", "print_row i", "- imprime os elementos não vazios da linha (i,).\n");
	printf("%15s %10s", "print", "- imprime a matriz completa, elementos vazios representados por '-'.\n");
}


bool indicesPermitidos(int i, int j)
{
	if (i < 0 || i >= CAPACIDADE || j < 0 || j >= CAPACIDADE) {
		printf("Índices (%d %d) fora das dimensões da matriz.\n", i, j);
		return false;
	}
	return true;
}

int main()
{

	Matriz* m = new_matrix();	
	
	char cmd[30];
	int i;
	int j;
	float v;
	
	do
	{
		printf("> ");
		scanf("%s", cmd);
		
		if (strcmp(cmd, "put") == 0)
		{
			scanf("%d %d %f", &i, &j, &v);
			if (indicesPermitidos(i,j)) {
				put(m, i, j, v);
				printf("\r(%d,%d) <= %.1f\n", i, j, v);
			}
		} else if (strcmp(cmd, "get") == 0) 
		{
			scanf("%d %d", &i, &j);
			if (indicesPermitidos(i,j)) {
				v = get(m, i, j);
				printf("\r(%d,%d) = %.1f\n", i,j,v);
			}
		} else if (strcmp(cmd, "add_to_col") == 0)
		{
			scanf("%d %f", &j, &v);
			if (indicesPermitidos(0,j)) {
				add_to_col(m, j, v);
			}
		}  else if (strcmp(cmd, "add_to_row") == 0)
		{
			scanf("%d %f", &i, &v);
			if (indicesPermitidos(i,0)) {
				add_to_row(m, i, v);
			}
		} else if (strcmp(cmd, "print_col") == 0) {
			scanf("%d", &j);
			if (indicesPermitidos(0,j))
				print_col(m, j);
		} else if (strcmp(cmd, "print_row") == 0) {
			scanf("%d", &i);
			if (indicesPermitidos(i, 0))
				print_row(m, i);
		} else if (strcmp(cmd, "print") == 0) {
			print_matrix(m);
		}		
		
	} while (strcmp(cmd, "exit") != 0);
	
	freeMatriz(m);
	
	return 1;
}
