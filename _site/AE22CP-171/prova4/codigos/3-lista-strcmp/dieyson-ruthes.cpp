#include<cstdio>
#include<iostream>
#include<list>

using namespace std;

list<char> strParaLista(string a)
{
    list<char> List;
    int i=0;
    char aux;
    while(i<a.size()){
        aux=a[i];
        List.push_back(aux);
        ++i;
    }
    return List;
}
void printList(list<int> la){
    list<int>::iterator it;
    for(it = la.begin(); it != la.end(); ++it){
        cout << *it;
    }
    cout << '\n';
}
int strcmplist(list<char> A,list<char> B)
{
    list<char>::iterator itB=B.begin();
    for(list<char>::iterator it=A.begin();it!=A.end();it++)
    {
        if(it==itB) return 0;
        else if(*it<*itB) return -1;
        else if(*it>*itB) return 1;
        itB++;
    }
    return 0;
}

int main()
{
    string A;
    string B;
    int i;

    list<char> lista;
    list<char> listb;

    cin >> A >> B;

    lista = strParaLista(A);
    listb = strParaLista(B);
    i=strcmplist(lista,listb);
    if(i==0) cout<<"A igual a B"<<endl;
    else if(i<0) cout<<"A menor que B"<<endl;
    else cout<<"A maior que B"<<endl;


}

