#include "../libreria.h"

int main() {
    system("clear");
    cout << "Classico  (9x10)           Alternativo (6x15)\n" << endl;
    cout << "Scegli un formato per la visualizzazione del tabellone: ";
    int vis;
    cin >> vis;
    switch (vis) {
        case 1:
        vis = 10;
        break;
        case 2:
        vis = 15;
        break;
        default:
        vis = 10;
        break;
    }

    int trap = 0, stack = 1;
    bool ch;

    int tabellone[90];
    for (int j=0; j<90; j++) {
        tabellone[j] = 0;
    }
    while (stack < 91) {
        system("clear");
        for (int i=1; i<91; i++) {
            cout << tabellone[i - 1] << " ";
            if ((i % vis)==0) { cout << endl << endl; }
        }
        cout << endl;
        cout << "\nEstrai numero (1), vedi numeri usciti (2), termina (altro) >> ";
        int t;
        cin >> t;
        cout << endl;
        int num;
        if (t == 1) {
            stack += 1;
            flag:num = randintno0(90);
            ch = checker(tabellone, 90, num);
            if (ch == true) {
                goto flag;
            } else {
                tabellone[num - 1] = num;
                continue;
            }
        }
        if (t == 2) {
            system("clear");
            cout << "Numeri usciti (in ordine crescente): ";
            for (int j=0; j<90; j++) {
                if (tabellone[j] != 0) {
                    cout << tabellone[j] << " - ";
                }
            }
            cout << "\nPremi invio per continuare";
            getchar();
            cin.ignore();
            continue;
        } else {
            system("clear");
            exit(0);
        }
    }

    system("clear");
        for (int i=1; i<91; i++) {
            cout << tabellone[i - 1] << " ";
            if ((i % vis)==0) { cout << endl << endl; }
        }
    fff:cout << "Tutti i numeri sono usciti! Vuoi ricominciare (s/n)? ";
    string a;
    cin >> a;
    if (a == "s" || a == "S") { main(); }
    if (a == "n" || a == "N") { system("clear"); exit(0); }
    else { goto fff; }
}