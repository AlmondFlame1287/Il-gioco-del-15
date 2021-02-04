#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
void facile()
{
	//possibilità di vincita del giocatore praticamente pari a 100
	int monete = 11;
	int moneteRaccolteP, moneteRaccolteM;
	

	cout << "Quante monete vuoi raccogliere? (da 1 a 3)";
	cin >> moneteRaccolteP;
	
	while(moneteRaccolteP <= 0 || moneteRaccolteP >= 4)
	{
		cout << "Ti ho detto di scegliere tra 1 e 3!";
		facile();
	}
	
	monete -= moneteRaccolteP;
	moneteRaccolteM = rand()%3;
	
	while(moneteRaccolteM == 0)
	{
		moneteRaccolteM = rand()%3;
	}
	
	cout << moneteRaccolteM << endl;
}





int main()
{
	char diff;
	
	cout << "Ciao! Seleziona la difficolta': " << endl;
	cout << "F = facile, M = medio, D = difficile" << endl;
	cin >> diff;
	
	switch(diff)
	{
		case 'f':
			facile();
			break;
		case 'm':
//			medio();
			break;
		case 'd':
//			difficile();
			break;
		default:
			cout << "Inserisci una difficoltà valida!";
			main();
			break;	
	}
	
	
	
}
