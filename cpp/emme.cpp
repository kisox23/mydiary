#include "mylib.h"

char parola[20];
char lettera;
int esci = 0;

int main() {
    system("clear");
    cout << "Letters research: insert a word (max 20 charachters): ";
    cin >> parola;
    cout << parola << endl;

    cout << "Che lettera vuoi cercare?  > ";
    cin >> lettera;
    int i = 0;
    while (i < 20 and esci == 0) {
        if (lettera == parola[i]) {
            esci = 1;
        }
        else {
            i = i + 1;
        }
    }
    if (esci == 1) {
        cout << "Lettera trovata!\n\n\n" << endl;
    }
    else {
        cout << "Lettera non trovata!\n\n\n" << endl;
    }
}
