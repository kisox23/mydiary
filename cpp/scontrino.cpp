//PROGRAMMAZIONE SCONTRINO
#include <iostream>       //libreria per l'input e l'output (per usare cout e cin)
#include <string>         //libreria per l'utilizzo del tipo stringa
#include <unistd.h>       //libreria per usare la funzione sleep()
#include <stdio.h>        //libreria per usare la funzione printf()
#include <cstdlib>        //libreria per usare la funzione exit()
#include <iomanip>
using namespace std;      //omettere std:: per i comandi nel namespace std
unsigned int sleep(); //dichiarazione per usare la funzione di riposo

int lista() //funzione principale
{
    LOOP:int cont=0; //contatore per il loop
    float p, f=0, importo, resto; //variabili per la somma dei prezzi decimali
    string lista; //variabile della lista dell'insieme
    
    cout << "               INSERISCI I VARI PRODOTTI: (Premi 000 in prodotto per terminare)\n\n"; //avviso
    
    do {
        cont = cont + 1; //inizio del loop
        string prezzo;
        string prodotto;
		string unita;
        
		cout << "NOME DEL PRODOTTO > ";
        cin >> prodotto;                              
        cout << "PREZZO > ";   
        cin >> prezzo;
		cout << "UNITA' > ";
		cin >> unita;
        if (prodotto == "000") 
            {
                break;
                goto FINE; //condizione per terminare  il loop
            }   
        cout << "*************************************************************************************************\n";
		
		p = stof(prezzo); //string_to_float
        int l = stoi(unita);
        f = f + (p * l); //sommatore dei prezzi
        double molt = p * l;
        string m = to_string(molt);
        lista = lista + (prodotto + " - " + prezzo + "€ x " + unita + " PEZZI  ->  " + m + "\n"); //fine del loop
    } while (cont < 100000); //condizione per un limite massimo irraggiungibile
    
    system("clear");
    FINE:cout << "\nLISTA SCONTRINO: \n" << lista << endl;
    cout << endl;
    double tot = f;
    cout << "TOTALE: " << tot << "€" << endl;
    
    sleep(1);
    string w;
    cout << "\nVUOI CALCOLARE IL RESTO? (s/n)  ";
    cin >> w;
    cout << endl;
    if (w == "s" or w == "S")
    {
        cout << "INSERISCI L'IMPORTO RICEVUTO: ";
        cin >> importo;
        cout << endl;
        
        resto = (importo - tot)*100;
        int b50, b20, b10, b5, n2, n1, n05, n02, n01, n005, n002, n001; /*dichiarazione 
variabili corrispondenti alle banconote e alle monete per il resto*/
        
        b50 =  resto /5000;
        resto = (resto - (b50*5000));
        cout << "BANCONOTE 50 EURO >> " << b50 << endl;
        
        b20 =  resto /2000;
        resto = resto - (b20*2000);
        cout << "BANCONOTE 20 EURO >> " << b20 << endl;
        
        b10 =  resto /1000;
        resto = resto - (b10*1000);
        cout << "BANCONOTE 10 EURO >> " << b10 << endl;
        
        b5 =  resto /500;
        resto = resto - (b5*500);
        cout << "BANCONOTE 5 EURO >> " << b5 << endl;
        
        n2 =  resto /200;
        resto = resto - (n2*200);
        cout << "MONETE 2 EURO >> " << n2 << endl;
        
        n1 =  resto /100;
        resto = resto - (n1*100);
        cout << "MONETE 1 EURO >> " << n1 << endl;
        
        n05 =  resto /50;
        resto = resto - (n05*50);
        cout << "MONETE 50 CENTESIMI >> " << n05 << endl;
        
        n02 =  resto /20;
        resto = resto - (n02*20);
        cout << "MONETE 20 CENTESIMI >> " << n02 << endl;
        
        n01 =  resto /10;
        resto = resto - (n01*10);
        cout << "MONETE 10 CENTESIMI >> " << n01 << endl;
        
        n005 =  resto /5;
        resto = resto - (n005*5);
        cout << "MONETE 5 CENTESIMI >> " << n005 << endl;
        
        n002 =  resto /2;
        resto = resto - (n002*2);
        cout << "MONETE 2 CENTESIMI >> " << n002 << endl;
        
        n001 =  resto /1;
        resto = resto - (n001*1);
        cout << "MONETE 1 CENTESIMO >> " << n001 << endl;
        
        tot = 0;
        
        FLAG:cout << "\nVUOI RIAVVIARE? (s/n)  "; //si sceglie se si vuole rieseguire il codice
        string er;
        cin >> er;
        if (er == "s" || er == "S") 
            {
                cout << "\n\n\n\n";
                goto LOOP; //se sì, ritorna al LOOP
                system("clear");
            }
        if (er == "n" || er == "N") 
            { 
                cout << "\n\n\n\n\n";
                cout << "===================================================================================================\n";
                cout << "!                                                                                                 !";
                cout << "!                         GRAZIE PER AVER USATO IL SOFTWARE, ARRIVEDERCI!                         !";
                cout << "!                                                                                                 !";
                cout << "===================================================================================================\n";
                cout << "\n\n\n\n\n";
                sleep(2);
                system("clear");
                exit(0);
            } else goto FLAG;
    }
    if (w == "n" or w == "N")
    {
		goto FLAG;
    }
    return 0;
}

int main()  //la funzione main serve solo a introdurre e chiamare la funzione lista
{
    system("clear");   // pulisci lo schermo
    cout << "===================================================================================================\n";
    cout << "!                                           BENVENUTO                                             !";
    cout << "!                REGISTRATORE DI CASSA PER TERMINALE UNIX-LIKE; TESTATO SU LUBUNTU                !";
    cout << "!                                    Autore: Kyog;Re    v1.0                                      !";
    cout << "===================================================================================================\n";
    sleep(1); //aspetta 1 secondo
    lista();
}
/*COMANDI USATI:  
cout = output       cin = input       return = ritorna valore funzione
if = condizione       else = altrimenti      do = fai qualcosa       
while = ciclo (mentre)       or/|| = oppure (nelle condizioni)    
goto = rileggi codice da un determinato punto assegnato prima del simbolo ':'
 *VARIABILI USATE:
int = numero intero       float = numero a virgola mobile       string = stringa */

/*TEORIA:
file header = file che richiamano librerie standard
namespace = spazio di nomi definiti dal programmatore usato per evitare confusione
    fra nomi simili
*/