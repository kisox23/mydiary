#include <iostream>
#include <cstdlib>
#include <string.h>
#include "utils.hpp"
using namespace std;

struct Dati {
    char name[10];
    int code;
    bool empty = false;
};

static const auto DEFSIZE = sizeof(Dati);
static FILE *f;
char* nulls = empty_charr(new char[10]);

void write() {
    srand(time(NULL));
    int offset;
    Dati dato1;
    dato1.empty = true;
    dato1.code = rand() % 100 + 1;
    char name[10];
    strcpy(name, rand_string(10).c_str());
    strcpy(dato1.name, name);

    cout << "Enter the offset: ";
    cin >> offset;

    f = fopen("docex.cx", "r+b");
    fseek(f, offset*DEFSIZE, 0);

    fwrite(&dato1, DEFSIZE, 1, f);
    fclose(f);
}

void read() {
    int offset;
    f = fopen("docex.cx","rb");
    Dati dato[10];

    for (int i = 0; i < 10; i++) {
        fseek(f, i*DEFSIZE, 0);
        fread(&dato[i], DEFSIZE, 1, f);
        if (dato[i].empty == true)
            cout << "\nNome: " << dato[i].name << "\nCodice: " << dato[i].code << endl;
    }
    fclose(f);    
}

void edit() {
    int offset;
    cout << "\nEnter the offset: ";
    cin >> offset;
    f = fopen("docex.cx", "r+b");
    fseek(f, offset*DEFSIZE, 0);
    Dati dato;
    fread(&dato, DEFSIZE, 1, f);
    if (!dato.empty) {
        cout << "Empty record!" << endl;
        edit();
    }
    cout << "\nEnter new name: ";
    cin >> dato.name;
    cout << "\nEnter new code: ";
    cin >> dato.code;
    fseek(f, offset*DEFSIZE, 0);
    fwrite(&dato, DEFSIZE, 1, f);
    fclose(f);
}

void remove() {
    int offset;
    cout << "\nEnter the offset: ";
    cin >> offset;
    f = fopen("docex.cx", "r+b");
    Dati dato;
    fseek(f, offset*DEFSIZE, 0);
    fread(&dato, DEFSIZE, 1, f);
    if (!dato.empty) {
        cout << "\nEmpty record!" << endl;
        remove();
    }
    strcpy(dato.name, nulls);
    dato.code = 0;
    dato.empty = false;
    fseek(f, offset*DEFSIZE, 0);
    fwrite(&dato, DEFSIZE, 1, f);
    fclose(f);
}

int main(int argc, char *argv[]) {
    if (strcmp(argv[1], "w") == 0)
        write();
    else if (strcmp(argv[1], "r") == 0)
        read();
    else if (strcmp(argv[1], "e") == 0)
        edit();
    else if (strcmp(argv[1], "d") == 0)
        remove();
    else return 0;
}