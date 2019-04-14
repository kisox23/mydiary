#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a,b,c,d,e;
    cout << "INSERISCI 5 NUMERI: " << endl;
    cout << "\nPRIMO > ";
    cin >> a;
    cout << "\nSECONDO > ";
    cin >> b;
    cout << "\nTERZO >";
    cin >> c;
    cout << "\nQUARTO > ";
    cin >> d;
    cout << "\nQUINTO > ";
    cin >> e;
    auto res = minmax({a,b,c,d,e});
    cout << "\nMIN > " <<res.first<< "\nMAX > " <<res.second<< endl;
    return 0;
}