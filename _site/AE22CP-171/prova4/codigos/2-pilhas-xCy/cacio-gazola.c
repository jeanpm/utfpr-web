#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

//Item da pilha
typedef struct
{
    char num;
    struct Num* prox;
    struct Num* ant;
    
}Num;


Num* novoItem(char dig)
{
	Num* i = (Num*) malloc(sizeof(Num));
	i->num = dig;
	i->prox  = NULL;
	i->ant  = NULL;
	return i;
}
//Pilha
typedef struct 
{
    int qt;
    Num* inicio;
    Num* fim;
}Lista;

Lista* novaLista()
{
	Lista* l = (Lista*) malloc(sizeof(Lista));
	l->inicio = NULL;
	l->fim    = NULL;
	l->qt = 0;
	
	return l;
}

// funções de pillha 
// topo da pilha é o fim da lista : l->fim = topo da pilha 


//insere elemento do top da pilha 
void pop(Lista* l, Num* novo)
{
	// Se lista vazia
	if (l->fim == NULL) 
	{
		l->inicio = novo;
		l->fim = l->inicio;	
	} 
	else
    {
		l->fim->prox = novo;
		novo->ant = l->fim;
		l->fim = novo;
		l->fim->prox = NULL;
	}
	l->qt++;
}

//remove elemento da pilha 
Num* push(Lista* l)
{
	//se pilha vazia, não há o que remover 
	if(l->fim == NULL)
	{
		return -1;
	}

	Num* aux;
	aux = l->fim;
    
	l->fim = l->fim->ant;
	l->fim->prox = NULL;
	l->qt--;

	aux->ant= NULL;

	return aux;
}

void isPalindrome(char* str) 
{
    int ok=0;
    //criando a pilha
    Lista* Pilha = novaLista();
    
    int i=0;
    
    while(str[i] != 'C' && str[i] != '\0')
    {
        //enquanto não encontrar o C ou o fim da string, insere os caracteres na pilha, um a um
        
        Num* aux; 
        aux = novoItem(str[i]);
        pop(Pilha,aux);
        i++;
    }
    
    if(str[i]=='C')
    {
        i++;
        
        while(str[i]!= '\0' || ok==0)
        {
            Num* aux2;
            aux2 = push(Pilha);
            if(str[i] != aux2->num)
            {
                ok=1;
            }
            i++;
        }
    }
    if(ok==1 || Pilha->qt !=0)
    {
        printf("NÃO");
    }
    else 
    {
        printf("SIM");
    }
}


int main() {
    char str[100];
    scanf("%s", str);
    isPalindrome(str);
    return 0;
}

