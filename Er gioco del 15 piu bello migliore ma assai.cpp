#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
void facile() //inizio della difficoltà facile
{
	//possibilità di vincita del giocatore praticamente pari a 100
	int monete = 11;
	int moneteRaccolteP, moneteRaccolteM;
	srand(time(NULL));

	while(monete > 0)
	{

		cout << "Quante monete vuoi raccogliere? (da 1 a 3)";
		cin >> moneteRaccolteP;
	
		while(moneteRaccolteP <= 0 || moneteRaccolteP >= 4)
		{
			cout << "Ti ho detto di scegliere tra 1 e 3!";
			facile();
		}
	
		monete -= moneteRaccolteP;
		moneteRaccolteM = rand()%3 + 1;
		monete -= moneteRaccolteM;
		cout << "Il computer ha preso " << moneteRaccolteM << " monete. Rimangono " << monete << " monete" << endl;
	
		if(monete < 0)
		{
			cout << "Il computer ha preso l'ultima moneta, e dunque hai vinto!" << endl;
		}
		else if(monete == 0)
		{
			cout << "Hai preso l'ultima moneta. Hai perso!" << endl;
		}
	}
}	


void medio() //inizio della difficoltà media
{
	int monete = 11;
	int moneteRaccolteP, moneteRaccolteM;
	srand(time(NULL));
	
	int probVitt;
	
	probVitt = rand()%100 + 1;
	
	if(probVitt >= 70)
	{
		while(monete > 0)
		{

			cout << "Quante monete vuoi raccogliere? (da 1 a 3)";
			cin >> moneteRaccolteP;
		
			while(moneteRaccolteP <= 0 || moneteRaccolteP >= 4)
			{
				cout << "Ti ho detto di scegliere tra 1 e 3!";
				medio();
			}
		
			monete -= moneteRaccolteP;
			
			switch(moneteRaccolteP)
			{
				case 1:
					
			}
			
			
			
			
			
		
			cout << "Il computer ha preso " << moneteRaccolteM << " monete. Rimangono " << monete << " monete" << endl;
		
			if(monete < 0)
			{
				cout << "Il computer ha preso l'ultima moneta, e dunque hai vinto!" << endl;
			}
			else if(monete == 0)
			{
				cout << "Hai preso l'ultima moneta. Hai perso!" << endl;
			}
		}	
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
