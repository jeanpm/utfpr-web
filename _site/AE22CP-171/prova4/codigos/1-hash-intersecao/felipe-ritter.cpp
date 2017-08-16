#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <cstring>

using namespace std;

#define capacidade 1021

typedef struct Aluno{
    long matricula;
}Aluno;

int h(long mat){
    return mat % capacidade;
}

void printList(list<Aluno> a){
    list<Aluno>::iterator ia;
    if(a.empty()){
        return;
    }else{
        //int i = 0;
        for(ia = a.begin(); ia != a.end(); ia++){
            Aluno a;
            a.matricula = ia->matricula;
            cout << a.matricula << ' ';
            //i++;
            /*if(i < a.size()){
                cout << ", ";
            }*/
        }
    }
}

void inserir(list<Aluno>* L, long matricula){
    int hnum = h(matricula);
    Aluno A;
    A.matricula = matricula;

    for(list<Aluno>::iterator it = L[hnum].begin(); it != L[hnum].end(); it++){
        if(it->matricula == matricula) return;
    }

    L[hnum].push_front(A);
}

bool I(list<Aluno> C, long item){
    int i=0, H = h(item);
    for(list<Aluno>::iterator it = C.begin(); it != C.end(); it++){
        Aluno a;
        a.matricula = it->matricula;
        if(a.matricula == item){
                return true;
        }else return false;
        i++;
    }
    return false;
}

list<Aluno> insercao(list<Aluno>* A, list<Aluno>* B){
    list<Aluno> C, D;
    int i=0;
    Aluno a;

    for(list<Aluno>::iterator it = A->begin(); it != A->end(); it++){
        a.matricula = it->matricula;
        C.push_front(a);
        printList(C);
        i++;
    }
    for(list<Aluno>::iterator it = B->begin(); it != B->end(); it++){
        a.matricula = it->matricula;
        bool b = I(C, a.matricula);
        if(b == true) D.push_front(a);
    }

    return D;
}


/*list<Aluno> E(list<Aluno>* a, list<Aluno>* b){
    list<Aluno>::iterator ia = a.end(), ib = b.end();
    list<Aluno> c;

    if(a.size() > b.size()) a.swap(b);

    int mult, resto=0, zero=0;

    while(ia != a.begin()){
            --ia;
            while(ib != b.begin()){
                --ib;
                int a = h(ia.matricula);
                int b = h(ib.matricula);

                if(ia.matricula == ib.matricula){
                        c.push_front(ib.matricula);
                }
            }

    }

    return c;
}
*/



int main(){
    int n;

    list<Aluno> thash[capacidade], thash2[capacidade];

    long matricula;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> matricula;
        inserir(thash, matricula);
    }
    //cout << "\n";
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> matricula;
        inserir(thash2, matricula);
    }

    /*for(int i=0; i<capacidade; i++){
        printList(thash[i]);
        printList(thash2[i]);
    }*/


    cout << "\n";
    printList(insercao(thash, thash2));
    cout << "\n";
    return 0;
}

