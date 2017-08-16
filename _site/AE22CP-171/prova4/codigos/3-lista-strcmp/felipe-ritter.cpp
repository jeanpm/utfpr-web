#include<cstdio>
#include<iostream>
#include<list>

using namespace std;

list<char> tolist(list<char> L, string A){
    int i=0;
    while(A[i]!='\0'){
        L.push_back(A[i]);
        ++i;
    }
    return L;
}

int strcmplist(list<char> A, list<char> B){
    if(A.size() < B.size()) B.swap(A);

    list<char>::iterator ia = A.begin(), ib = B.begin();

    while(ia != A.end()){
        if((int)*ia < (int)*ib) return -1;
        else if((int)*ia > (int)*ib) return 1;
        ia++;
        ib++;
    }
    //cout << "A igual a B";
    return 0;
}

int main(){
    list<char> A, B;
    string a, b;
    cin >> a >> b;

    A = tolist(A, a);
    B = tolist(B, b);

    if(strcmplist(A,B) == -1){
        cout << "A menor que B";
    }else if(strcmplist(A,B) == 1){
        cout << "A maior que B";
    }else cout << "A igual a B";


    return 0;
}

