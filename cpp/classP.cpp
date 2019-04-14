#include "mylib.h"

class Colore {
    char color[10][15] = {"Blu","Giallo","Rosso","Verde","Azzurro","Arancione","Viola","Rosa","Nero","Bianco"};
    char forma[5][15] = {"Quadrato","Triangolare","Rettangolare","Rotonda","Esagonale"};
    int x;
    int y;
    public:
        Colore() {
            srand(time(NULL));
            int colorex = (rand() % 10 + 1);
            srand(time(NULL));
            int formax = (rand() % 5);
            x = colorex;
            y = formax;
        };
        
        void show() {
            cout << "Oggetto: " << color[x] << " - " << forma[y] << "\n" << endl;
        }
};

int main() {
    cout << "\nGenerating...\n" << endl;
    Colore n1;
    sleep(1);
    Colore n2;
    sleep(1);
    
    n1.show();
    n2.show();
}