#include <cstdlib>
#include <ctime>
#include <stack>
#include <iostream>

using namespace std;

bool is_xCx(const char* in)
{
    stack<int> p;
    int i;
    for (i = 0; in[i] != 'C'; i++)
        p.push(in[i]);
    
    i++;

    char c;
    while (!p.empty() && in[i] != '\0')
    {
        c = p.top(); p.pop();
        if (c != in[i++])
            return false;
    }
    
    if (p.empty() && in[i] == '\0')
        return true;

    return false;
}

void gerarInput(const int MAXSIZE)
{
    bool palindromo = rand() % 2;
    int size = rand() % MAXSIZE;
    
    stack<int> p;
    for (int i = 0; i < size; i++)
    {
        int c = rand() % 10;
        cout << c;
        if (palindromo)
            p.push(c);
    }

    cout << 'C';
    
    if (!palindromo)
        size = rand() % MAXSIZE;

    for (int i = 0; i < size; i++)
    {
        int c;
        if (palindromo)
        {
            c = p.top(); p.pop();
            cout << c;
        } else {
            c = rand() % 10;
            cout << c;
        }
    }


}

int main(int argc, char** argv)
{
    if (argc > 1) 
    {
        srand(time(NULL));
        gerarInput(atol(argv[1]));
    } else {
        string input;
        cin >> input;

        cout << (is_xCx(input.c_str()) ? "SIM" : "NÃO") << endl;
    }
}
