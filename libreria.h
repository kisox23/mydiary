#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <cstddef>
#include <unistd.h>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <sstream>
using namespace std;

void swap(int arr[], int size) {
    int i, j, dep;
    for (i=0; i<size-1; i++) {
        for (j=i+1; j<size; j++) {
            if (arr[i] > arr[j]) {
                dep = arr[i];
                arr[i] = arr[j];
                arr[j] = dep; }
        }
    }
}

void search(int arr[], int q) {
    cout << "\n(Si ricorda che l'array deve essere ordinato)\nInserisci il valore da trovare: ";
    int fi, mid, sx = 0, dx = q - 1, exit = 0;
    cin >> fi;
    do {
        mid = (sx + dx) / 2;
        if (arr[mid] == fi) {
            exit = 1;
        } else {
            if (arr[mid] < fi) {
                sx = mid + 1;
            } else {
                dx = mid - 1;
            }
        }
    } while (exit == 0 and sx <= dx);

    if (exit != 1) {
        cout << "\nIl valore cercato non e' presente nell'array." << endl;
    } else {
        cout << "\nIl valore cercato e' presente nell'array." << endl;
    }
}

