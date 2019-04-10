#include "../libreria.h"

int main() {
    
    int vett[100];
    int n, dep, j, i, q, ex=0;
    cout << "Vettore: ";
    cin >> n;
    for (int i=0; i<n; i++) {
        cout << "valore: ";
        cin >> vett[i];
    }

    i=0;
    for (i=0; i<n-1; i++) {
        for (j=i+1; j<n; j++) {
            if (vett[i] > vett[j]) {
                dep = vett[i];
                vett[i] = vett[j];
                vett[j] = dep;
            }
        }
    }

    int mid, dx=n-1, sx=0;
    cout << "\nCerchi: ";
    cin >> q;
    do {
        mid = (sx + dx) / 2;
        if (vett[mid] == q) {
            ex = 1;
        } else {
            if (vett[mid] < q) {
                sx = mid +  1;
            } else {
                dx = mid - 1;
            }
        }
    } while (ex == 0 and sx <= dx);

    if (ex != 0) {
        cout << "Numero trovato!";
        exit(1);
    } else {
        cout << "NOT FOUND";
        exit(1);
    }
}