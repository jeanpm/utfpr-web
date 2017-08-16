#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct letra {
    char l;
} elem;

typedef struct {
    elem L[MAX];
    int qnt;
} Lista;

//Uma pilha também é uma lista, só que inserimos e removemos apenas do topo
typedef Lista Pilha;

void criaPilha(Pilha *p)
{
    p->qnt = 0;
}

int Inserir(Lista *x, elem *e, int pos)
{
    if (x-> qnt == MAX)
        return -1;
    else if ( pos > x-> qnt)
        return -2;
    else {
        if (x->qnt != pos)
        {
            int i;
            for (i = x->qnt; i > pos; i--)
                x->L[i] = x->L[i - 1];
        }
        x->L[pos] = *e;
        x->qnt++;
    }
    return 1;
}

int push(Pilha *p, elem *e)
{
    return Inserir(p,e,p->qnt);
}

int Remover( Lista *x, int pos)
{
    int i;
    if (pos > x->qnt)
        return -1;
    for (i = pos; i < x->qnt; i++) {
        x->L[i] = x->L[i + 1];
    }
    x->qnt--;
    return 1;
}

int pop(Pilha *p)
{
    return Remover(p,(p->qnt)-1);
    // 0     1       2       3       4
    // x1|  x2 |  x3  | x4  |       |
    //qnt=4, mas a pos esta em 3, portanto (p->qnt) - 1
}

void isPalindrome(char* str) {
    // Complete this function
}

int main() {
    char* str = (char *)malloc(512000 * sizeof(char));
    scanf("%s", str);
    isPalindrome(str);
    return 0;
    int i;
    Pilha P1;
    criaPilha(&P1);
    elem p;
    char* palavra[20];
    scanf("%s", &palavra);
    fflush(stdin);
    while(palavra[i] != 'C')
    {
        Inserir(&P1, palavra[i], i);
        i++;
        printf("%c", P1->L[1].l);
    }
}

