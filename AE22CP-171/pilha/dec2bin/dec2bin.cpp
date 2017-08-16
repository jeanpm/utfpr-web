#include <stack>
#include <iostream>

using namespace std;

void dec2bin_stack(long dec)
{
    stack<int> bin;

    do {
        bin.push(dec % 2);
        dec /= 2;
    } while (dec > 0);

    while (!bin.empty()) {
        cout << bin.top();
        bin.pop();
    }
    cout << endl;
}


int main()
{
    long num_10;
    cin >> num_10;
    dec2bin_stack(num_10);
}
