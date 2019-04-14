#include <cstdlib>
#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
    int somma = 0;
    int max;
    int m, n;
    cout << "\n\nQUANTI NUMERI (CASUALI) VUOI SOMMARE? > " << endl;
    cin >> max;
    cout << "\n\nQUAL E' IL NUMERO MASSIMO? > " << endl;
    cin >> n;
    cout << "GENERANDO I NUMERI...";
    unsigned int sleep(2);
    for (int i = 1; i < (max + 1); i++)
    {
        m = (1 + (std::rand() % n));
        somma += m;
        cout << m << endl;
    }
    cout << "\n\nLA SOMMA E': " << somma << endl;
}