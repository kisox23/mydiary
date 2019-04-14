#include "mylib.h"
using namespace std;

int main()
{
    system("clear");
    int num, c=0;
    float somma=0;
    
    cout << "Inserisci la quantita' di numeri da usare: ";
    cin >> num;
    int vect[num];
    
    for (int v = 0; v < num; v++)
    {
        int c = c + 1;
        cout << "Inserisci il " << c << "° numero del vettore: ";
        cin >> vect[v];
        somma = somma + vect[v];
        cout << endl;
    }
    printf("I valori inseriti sono: \n");
    for (int i = 0; i < num; i++)
    {
        cout << vect[i] << "   ";
    }
    float media = somma/num;
    cout << "\nLa media del vettore e': " << media << endl;
    
    trel();
    
    printf("\nRiavviare? (1) -Si   (2) -No > ");
    int redo;
    cin >> redo;
    if (redo == 1) {
        main();
    }
    if (redo == 2) {
        crediti();
        exit(0);
    }
}