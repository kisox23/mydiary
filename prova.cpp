#include "../libreria.h"

int main() {
    int trap = 0, stack = 0;
    bool ch;

    int tabellone[90];
    for (int j=0; j<90; j++) {
        tabellone[j] = 0;
    }
    while (stack < 90) {
        system("clear");
        for (int i=1; i<91; i++) {
            cout << tabellone[i - 1] << " ";
            if ((i % 10)==0) { cout << endl << endl; }
        }
        cout << endl;
        cout << "\nEstrai numero (1), vedi numeri usciti (2), termina (altro) >> ";
        int t;
        cin >> t;
        cout << endl;
        int num;
        if (t == 1) {
            flag:num = randintno0(90);
            ch = checker(tabellone, 90, num);
            if (ch == true) {
                goto flag;
            } else {
                tabellone[num - 1] = num;
                stack ++;
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

    fff:cout << "Tutti i numeri sono usciti! Vuoi ricominciare (s/n)? ";
    string a;
    cin >> a;
    if (a == "s" || a == "S") { main(); }
    if (a == "n" || a == "N") { exit(0); }
    else { goto fff; }
}