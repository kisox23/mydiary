#include "mylib.h"

int value, scelta;
const int maxx = 20;

int struttura()
{
    typedef struct Persona {
    string nome;
    string cognome;
    int eta;
    int cap;
    } pers;

    pers antonio = {"Antonio", "Clementi", 55, 90140};
    pers andrea = {"Andrea", "Clementi", 15, 90135};
    pers giorgio = {"Giorgio", "Clementi", 12, 90135};
    pers gabriella = {"Gabriella", "Giordano", 50, 90135};


    exit(0);
}

int main()
{
    system("clear");
    do {
    cout << "Sviluppo di matrice quadrata: inserire il valore massimo > ";
    cin >> value;
    } while (value > maxx);

    int matrix[value][value];
    for (int i=0; i<value; i++) {
        for (int j=0; j < value; j++) {
            cout << "Inserisci il numero nella riga " << i << " e nella colonna " << j << ": ";
            cin >> matrix[i][j];
            }
        }
    cout << "Vuoi avviare la funzione di struct? (s-1/n-altro) > ";
    cin >> scelta;
    if (scelta == 1) {
        struttura();
    }
    else {
        cout << "Ciao ciao!" << endl;
        exit(1);}
}
