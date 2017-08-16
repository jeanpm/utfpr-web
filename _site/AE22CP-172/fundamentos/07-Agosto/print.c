#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

    if (argc < 3) {
        printf("Inicio e fim da sequencia faltando\n");
        return 0;
    }

    int inicio = atoi(argv[1]);
    int fim    = atoi(argv[2]);

    for (int i = inicio; i <= fim; i++)
        printf("%d ", i);
    printf("\n");
}
