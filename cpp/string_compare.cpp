#include "mylib.h"

int numero, i, somma;

int main()
{
    srand(time(NULL));
    
    for (i=0; i<9; i++)
    {
        numero = rand() % 10;
        cout << "Numero casuale: " << numero << endl;
        somma = somma + numero;
    }
    
    printf("\nVuoi sommare i numeri generati? Se si', invia 1. Se no invia 2. >>> ");
    int sc;
    cin >> sc;
    
    switch (sc)
    {
        case 1:
        cout << somma << endl;
        
        case 2:
        exit(0);
        
        default:
        exit(0);
    }
}