#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

#define TAMANHO 50
long result=0;

// Não precisa receber um ponteiro
// void transforma(long *num)
void transforma(long num)
{
// Não é preciso converter para int
//    int i=(int)num;
    int aux;
    stack<int> *pilha;
    pilha = new stack<int>;
    while(num!=0)
    {
//		aux=(i%2);    
        aux=(num%2);
        pilha->push(aux);
//      i=(*num)/2;
//		i = num/2;
//        (*num)=i;
		num = num/2;
//        cout<<i<<endl;
    }
//    while(pilha->empty()==0)
	while(pilha->empty()!=0)
    {
        aux=pilha->top();
        cout<<aux;
        pilha->pop();
    }
    cout<<endl;
}
int main()
{
    long n, rest;
    cin >> n;
//    transforma(&n);
	transforma(n);
    cout<<rest<<endl;
}

