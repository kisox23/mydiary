#include "../libreria.h"
#if defined (_WIN32)
    #define CMD "CLS"
    #define DELCMD "DEL "
    #define PATH "C:\\magaz\\"
#elif defined (_WIN64)
    #define CMD "CLS"
    #define DELCMD "DEL "
    #define PATH "C:\\magaz\\"
#elif defined (__linux__)
    #define CMD "clear"
    #define DELCMD "rm "
    #define PATH "/root/magaz/"
#endif
namespace fs = boost::filesystem;

typedef struct Prod {
    int codice;
    string nome;
    int quantita;
    int tag;

    int rettag() {
        return tag;
    }
    int retcod() {
        return codice;
    }
    string retnam() {
        return nome;
    }
} item;

string depos;

int main();
void crea();
void apri();
void elimina();
void gestione();

void crea() {
    system(CMD);
    cout << "Inserisci il nome del nuovo deposito: ";
    string filename;
    cin >> filename;
    filename += ".dpst";
    const char * groom = filename.c_str();
    if (fs::exists(groom) == false) {
        fstream f;
        f.open(filename, ios::out | ios::binary);
        f.close();
        string cc = "chmod 777 ";
        cc += filename;
        const char * ccp = cc.c_str();
        system(ccp);
        sleep(1);
        main();
    } else {
        cout << "\nIl deposito e' gia' presente!" << endl;
        cin.get();
        cin.ignore();
        main();
    }

}

void apri() {
    system(CMD);
    cout << "Inserisci il nome del deposito: ";
    string dep;
    cin >> dep;
    depos = dep;
    depos += ".dpst";
    const char * groom = depos.c_str();
    if (fs::exists(groom) == true) {
        sleep(1);
        gestione();
    } else {
        cout << "\nIl deposito non esiste!" << endl;
        cin.get();
        cin.ignore();
        main();
    }
}

void elimina() {
    system(CMD);
    cout << "Inserisci il nome del deposito da eliminare: ";
    string del;
    cin >> del;
    del += ".dpst";
    string del2 = (DELCMD);
    del2 += del;
    const char * groom = del.c_str();
    if (fs::exists(groom) == true) {;
        const char * permdel = del2.c_str();
        system(permdel);
        sleep(1);
        main();
    } else {
        cout << "\nIl deposito non esiste!" << endl;
        cin.get();
        cin.ignore();
        main();
    }
}

void aggiungi() {
    item p;
    fstream f;
    f.open(depos, ios::out | ios::in | ios::binary);
    system(CMD);
    cout << "Inserisci il nome del prodotto da aggiungere: ";
    cin >> p.nome;
    cout << "\nInserisci il codice del prodotto: ";
    cin >> p.codice;
    cout << "\nInserisci la quantita': ";
    cin >> p.quantita;
    cout << "\nInserisci un numero uninvoco per la ricerca del prodotto: ";
    cin >> p.tag;

    f.seekp((p.tag - 1) * sizeof(Prod), ios::beg);
    f.write((char*)&p, sizeof(p));
    f.close();
    cout << "Fatto!" << endl;
    cin.get();
    cin.ignore();
    gestione();
}

void rimuovi() {
    int ttt;
    item p;
    p.codice = 0;
    p.quantita = 0;
    fstream f;
    f.open(depos, ios::out | ios::in | ios::binary);
    system(CMD);
    cout << "Inserisci il tag del prodotto da rimuovere: ";
    cin >> ttt;
    f.seekp((ttt - 1) * sizeof(Prod), ios::beg);
    f.write((char*)&p, sizeof(p));
    f.close();
    cout << "\nFatto!" << endl;
    cin.get();
    cin.ignore();
    gestione();
}

void modifica() {
    int ttt;
    item p;
    fstream f;
    f.open(depos, ios::out | ios::in | ios::binary);
    system(CMD);
    cout << "Inserisci il tag del prodotto da modificare: ";
    cin >> ttt;
    int minus = ttt;
    ttt = (ttt - 1) * sizeof(Prod);
    cout << "\nInserisci il nuovo nome: ";
    cin >> p.nome;
    cout << "\nInserisci il nuovo codice: ";
    cin >> p.codice;
    cout << "\nInserisci la nuova quantita': ";
    cin >> p.quantita;
    p.tag = minus;
    f.seekp(ttt, ios::beg);
    f.write((char*)&p, sizeof(p));
    f.close();
    cout << "\n\nFatto!";
    cin.get();
    cin.ignore();
    gestione();
}

void controlla() {
    system(CMD);
    ifstream f;
    item p;
    f.open(depos, ios::out | ios::in | ios::binary);
    if (f.fail()) {
        cout << "Errore";
        cin.get();
        cin.ignore();
        exit(0);
    } else {
        while(f.read((char*)&p,sizeof(p))) {
            if (p.codice == 0 and p.quantita == 0) {
                continue;
            } else {
                cout << "Nome: " << p.nome << "\nCodice: " << p.codice << "\nQuantita': " << p.quantita << "\nTag: " << p.tag << "\n" << endl;
            }
        }
    }
    cin.get();
    cin.ignore();
    f.close();
    gestione();
}

void ricerca() {
    system(CMD);
    ifstream f;
    item p;
    int n, x;
    cout << "Ricerca prodotto per:\n1 - Tag         2 - Codice          3 - Nome\n\n>> ";
    cin >> n;
    system(CMD);
    f.open(depos, ios::in | ios::binary);
    switch (n) 
    {
        case 1:
        cout << "Inserisci il tag del prodotto: ";
        cin >> x;
        if (f) {
        while (f.read((char*)&p, sizeof(p))) {
            if (p.rettag() == x) {
                cout << "\n\nNome: " << p.nome << "\nCodice: " << p.codice << "\nQuantita': " << p.quantita << "\nTag: " << p.tag << "\n" << endl;
                break;
            } else {
                continue;
            }
        }
        cin.get();
        cin.ignore();
        f.close();
        gestione();  
        } else {
            cout << "FATAL" << endl;
            f.close();
            exit(0);
        }

        case 2:
        cout << "Inserisci il codice del prodotto: ";
        cin >> x;
        if (f) {
        while (f.read((char*)&p, sizeof(p))) {
            if (p.retcod() == x) {
                cout << "\n\nNome: " << p.nome << "\nCodice: " << p.codice << "\nQuantita': " << p.quantita << "\nTag: " << p.tag << "\n" << endl;
                break;
            } else {
                continue;
            }
        }
        cin.get();
        cin.ignore();
        f.close();
        gestione();  
        } else {
            cout << "FATAL" << endl;
            f.close();
            exit(0);
        }

        case 3:
        string name;
        cout << "Inserisci il nome del prodotto: ";
        cin >> name;
        if (f) {
        while (f.read((char*)&p, sizeof(p))) {
            if (p.nome == name) {
                cout << "\n\nNome: " << p.nome << "\nCodice: " << p.codice << "\nQuantita': " << p.quantita << "\nTag: " << p.tag << "\n" << endl;
                break;
            } else {
                continue;
            }
        }
        cin.get();
        cin.ignore();
        f.close();
        gestione();  
        } else {
            cout << "FATAL" << endl;
            f.close();
            exit(0);
        }
    }
    
}

void gestione() {
    system(CMD);
    cout << "1 --> Aggiungi prodotto            2 --> Rimuovi prodotto" << endl;
    cout << "3 --> Modifica prodotto            4 --> Controlla deposito" << endl;
    cout << "5 --> Ricerca prodotto             6 --> Torna al menu'\n\n>> ";
    int scelta;
    cin >> scelta;
    switch (scelta) {
        case 1:
        aggiungi(); break;
        case 2:
        rimuovi(); break;
        case 3:
        modifica(); break;
        case 4:
        controlla(); break;
        case 5:
        ricerca(); break;
        case 6:
        main(); break;
        default:
        gestione();
    }
}

int main() {
    system(CMD);
    cout << "1 --> Crea magazzino           2 --> Apri magazzino" << endl;
    cout << "3 --> Elimina magazzino        4 --> Esci\n\n>> ";
    int menu;
    cin >> menu;
    switch (menu) {
        case 1:
        crea(); break;
        case 2:
        apri(); break;
        case 3:
        elimina(); break;
        case 4:
        system(CMD); exit(0);
        default:
        main(); break;
    }
}