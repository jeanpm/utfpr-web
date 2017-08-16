#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <list>

using namespace std;

void printList(list<char> la){
    list<char>::iterator it;
    for(it = la.begin(); it != la.end(); ++it){
        cout << *it;
    }
    cout << '\n';
}

bool palindromo(string s){
    list<char> P;
    int i=0, k=0;
    while(s[i] != 'C'){
        P.push_back(s[i]);
        //printList(P);
        i++;
        k++;
    }
    i=i+1;
    k=k+1;

    list<char>::iterator it = P.end();
    while(s[i] != '\0'){
        --it;
        //cout << s[i];
        if(s[i] == *it){
                //cout << "foi\n";
            k++;
        }
        i++;
    }
    //cout << i << ' ' << k;
    if(i == k){
            return true;
    }else return false;
    //cout << "err";
}

int main() {
    string str;
    cin >> str;
    if(palindromo(str) == true){
        cout << "SIM";
    }else cout << "NÃO";

    cout << "\n";
    return 0;
}

