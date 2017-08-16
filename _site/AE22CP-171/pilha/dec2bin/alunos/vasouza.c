#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
   int valor;
   struct pilha *prev,*prox;
}q;

q *topo = NULL,*base = NULL;

void push(int valor)
{
   q *aux;
   if(topo == NULL)
   {
      base = (q *) malloc(sizeof(q));
      base->valor = valor;
      base->prox = NULL;
      base->prev = NULL;
      topo = base;
   }
   else
   {
      aux = (q *) malloc(sizeof(q));
      aux->valor = valor;
      aux->prev = topo;
      aux->prox = NULL;
      topo->prox = aux;
      topo = aux;
   }
}

int pop()
{
int valor;
   if(topo == NULL)
       return -1;
   else
   {
      valor= topo->valor;
      topo = topo->prev;
   }
   return valor;
}

void decimalParaBinario(long num)
{
   int r;
   while(num != 0)
   {
      r = num%2;
      push(r);
      num = num/2;
   }
}

void binario()
{
   int flag = 0;
   int long b;
   while(flag != 1)
   {

      b = pop();
      if(b == -1)
         flag = 1;
      else
         printf("%ld",b);
   }
}

int main()
{

// ESQUECEU DE LER O NUMERO
   int long num=11;
// CORREÇÃO
	scanf("%ld", &num);
   
   decimalParaBinario(num);
   binario();

   return 0;
}

