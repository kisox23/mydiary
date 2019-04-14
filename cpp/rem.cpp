#include "mylib.h"

int main()
{
	int array[50];
	int var=0, num, iter, val, fine;
	do
	{
		cout << "Quanti numeri vuoi inserire? (max 50) > ";
		cin >> num;
	} while (num < 2 and num > 50);
		
	for (iter=0; iter < num; iter++) {
		cout << "Inserisci il " << iter+1 << "° numero: ";
		cin >> val;
	}
	
	cout << "\n\nQuale valore vuoi trovare nell'array? ";
	cin >> fine;
	
	iter=0;
	while (iter < num and var == 0)
	{
		if (array[iter] == fine ) {
			var = 1;
		}
		else {
			iter = iter + 1;
		}
	}
	
	if (var == 1) {
		cout << "Numero trovato. " << endl;
	}
	else {
		cout << "Numero non trovato. " << endl;
	}
}