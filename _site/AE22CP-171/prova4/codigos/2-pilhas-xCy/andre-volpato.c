# include <stdio.h>
# include <stdlib.h>
# define  MAX 100

typedef struct
{
    char c;
}elem;

typedef struct
{
    elem P[MAX];
    int quant;
}Pilha;


void criaPilha(Pilha*p)
{
    p->quant=0;
}

int insere(Pilha *x,elem *e, int pos)
{
    int i;
    if(x -> quant == MAX)
    {
        return -1;
    }
    else if(pos > x-> quant)
    {
        return -2;
    }
    else
    {
        if (x->quant == pos)
        {
            x->P[pos] = *e;
        }
        else
        {
            int i;
            for(i=x->quant ; i>pos ; i--)
            {
                x->P[i]=x->P[i-1];
            }
            x->P[pos]=*e;
        }
        x->quant++;
    }
    return 1;
}


int push(Pilha*p,elem*e)
{
    int res;
    res=insere(p,e,p->quant);
    return res;
}

void remover(Pilha *p,int pos)
{
    int i;

    for(i=pos; i<p->quant ; i++)
    {
        p->P[i] = p->P[i+1];
    }
    p->quant--;
}

void pop(Pilha *p)
{
    remover(p,p->quant-1);
}

void imprime(Pilha*p)
{
    int i;
    for(i=0 ; i< p->quant ; i++)
    {
        printf("\ncaracter: %c",p->P[i].c);
    }
}

int main()
{
    char* x = (char *)malloc(512000 * sizeof(char));
    scanf("%s",x);

    Pilha p;
    Pilha q;

    criaPilha(&p);
    criaPilha(&q);

    int i,cont=0;

    /*for(i=0 ; x[i]!='\0' ; i++)
    {
        cont++;
    }*/

    for(i=0 ; x[i]!='C'; i++)
    {
        cont++;
        char y = x[i];
        push(&p,&y);
    }
     cont = cont-1;
     int cont2 = cont+2;
    // printf("\ncont:%d\n\n",cont);
    for(i=cont2 ; x[i]!='\0' ;i++)
    {
       // printf("%c e %c",x[i],p.P[cont].c);

        if(x[i] == p.P[cont].c)
        {
            pop(&p);
        }
        cont--;
    }

    //imprime(&p);

    if(p.quant == 0)
    {
        printf("SIM");
    }
    else if(p.quant != 0)
    {
        printf("NÃO");
    }

    //imprime(&p);
    //imprime(&q);
}

