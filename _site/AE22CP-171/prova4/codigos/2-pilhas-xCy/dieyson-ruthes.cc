#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
void palindromo(string A){
    int i=0;
    stack<char> *pilha;
    pilha = new stack<char>;
    char au;
    while(A[i] != 'C')
    {
        pilha->push(A[i]);
        i++;
    }
    ++i;
    while(i<A.size())
    {
        au=pilha->top();
        if(A[i]==au){
            pilha->pop();
        }
        i++;
    }
    if(pilha->size()==0) cout<<"SIM"<<endl;
    else cout<<"NÃO"<<endl;
}
int main(){
    string c;
    cin>>c;
    palindromo(c);
}

