#include "mylib.h"

//DICHIARAZIONI
char *dir = "/tmp";
string password, path;
int int_input;
string filz = "checker_file.txt";

bool exists(const string &nome) 
{
	return access(nome.c_str(), 0) == 0;
}

//MENU' PRINCIPALE
int screen_menu()
{
	system("clear");
	printf("====================================================================================");
	printf("\\																					 																											/");
	printf("\\                       	    						TEST #1: COSA NUMERO UNO              						 											/");
	printf("\\														TEST #2: SCRIVERE SU UN FILE DI TESTO																	/");
	printf("\\														TEST #3: RIPRODURRE UN SUONO							 												/");
	printf("\\														TEST #4: BOH FRA										 																/");
	printf("\\																					 																											/");
	printf("====================================================================================");
	cout << "\n\n>> ";
	cin >> int_input;
	
	switch (int_input)
	{
		/*case 1:
		play();
		
		case 2:
		notepad();
		
		case 3:
		sound();
		
		case 4:
		clex(1);*/
		
		default:
		crediti();
	}
    return 0;
}

//FUNZIONE MENU' PER VERIFICARE LA PASSWORD E ACCEDERE AL MENU' PRINCIPALE
int menu()
{
	system("clear");
	cout << "If everything goes ok, check the 'checker_file.txt' in the /home directory\nand insert the password." << endl;
	unal();
	FLAG1:cout << "Password >>> ";
	cin >> password;
	
	if (password != "2377723") {
		sleep(1);
		cout << "Wrong password, try again." << endl;
		goto FLAG1;
	}
	
	if (password == "2377723") {
		screen_menu();
	}
    return 0;
}

//CREATORE Di checker_file.txt
int file_creator()
{
	fstream file;
	file.open("checker_file.txt", ios::in);
	file << "key: 2377723";
	file.close();
	cout << "Generating password..." << endl;
	sleep(1);
	cout << "Done." << endl;
	menu();
    
    return 0;
}

//CHECKER
int file_checker()
{
	chdir("/home");
	exists(filz);
}

//FUNZIONE MAIN (PULISCE SCHERMO)
int main()
{
	chdir("/home");
	system("clear");
	sleep(1);
	file_checker();
}
