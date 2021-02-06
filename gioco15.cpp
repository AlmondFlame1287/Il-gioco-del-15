#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void inizioMacchinaCasuale()
{
	int monete = 11;
	int moneteRaccolteP, moneteRaccolteM;
	
	srand(time(NULL));
	
	while(monete > 0)
	{
		moneteRaccolteM = rand()%3 + 1;
		monete -= moneteRaccolteM;
		
		cout << "Il computer ha preso " << moneteRaccolteM << " monete. Rimangono " <<  monete << " monete." << endl;
	
		do
		{
			cout << "Quante monete vuoi prendere? (1 a 3) " << endl;
			cin >> moneteRaccolteP;
		
			if(moneteRaccolteP <= 0 || moneteRaccolteP >= 4)
			{
				cout << "Ti ho detto di inserire un numero da 1 a 3!";
			}
		}
		while(moneteRaccolteP <= 0 || moneteRaccolteP >= 4);
		
		monete -= moneteRaccolteP;
		
		if(monete <= 0)
		{
			cout << "Le monete sono finite.";
		}
		
	}
	
}

void inizioMacchinaDeterminato()
{
	int monete = 11;
	int moneteRaccolteM, moneteRaccolteP;
	srand(time(NULL));
	
	while(monete > 0)
	{
		moneteRaccolteM = rand()%3 + 1;
		monete -= moneteRaccolteM;
		
		cout << "Il computer ha preso " << moneteRaccolteM << " monete. Rimangono " <<  monete << " monete." << endl;
		
		do
		{
			cout << "Quante monete vuoi prendere? (1 a 3) " << endl;
			cin >> moneteRaccolteP;
		
			if(moneteRaccolteP <= 0 || moneteRaccolteP >= 4)
			{
				cout << "Ti ho detto di inserire un numero da 1 a 3!";
			}
		}
		while(moneteRaccolteP <= 0 || moneteRaccolteP >= 4);
		
		
		switch(moneteRaccolteP)
		{
			case 1:
				moneteRaccolteM = 3;
				monete -= moneteRaccolteM;
				cout << "Il computer ha raccolto " << moneteRaccolteM << " monete. Rimangono " << monete << " monete" << endl;
				break;
			
			case 2:
				moneteRaccolteM = 2;
				monete -= moneteRaccolteM;
				cout << "Il computer ha raccolto " << moneteRaccolteM << " monete. Rimangono " << monete << " monete" << endl;
				break;
				
			case 3:
				moneteRaccolteM = 1;
				monete -= moneteRaccolteM;
				cout << "Il computer ha raccolto " << moneteRaccolteM << " monete. Rimangono " << monete << " monete" << endl;
				break;		
		
		}
		
		if(monete <= 0)
		{
			cout << "Le monete sono finite.";
		}
		
	}	

}

void inizioGiocatoreCasuale()
{
	int monete = 11;
	int moneteRaccolteP, moneteRaccolteM;
	srand(time(NULL));
	
	while (monete > 0)
	{
		
		do
		{
			cout << "Quante monete vuoi prendere? (1 a 3) " << endl;
			cin >> moneteRaccolteP;
		
			if(moneteRaccolteP <= 0 || moneteRaccolteP >= 4)
			{
				cout << "Ti ho detto di inserire un numero da 1 a 3!";
			}
		}
		while(moneteRaccolteP <= 0 || moneteRaccolteP >= 4);
		
		
		monete -= moneteRaccolteP;
		moneteRaccolteM = rand()%3 + 1;
		monete -= moneteRaccolteM;
		
		cout << "Il computer ha raccolto " << moneteRaccolteM << " monete. Rimangono " << monete << " monete" << endl;
		
		if(monete <= 0)
		{
			cout << "Le monete sono finite.";
		}
	}
}

void inizioGiocatoreDeterminato()
{
	int monete = 11;
	int moneteRaccolteP, moneteRaccolteM;
	
	while(monete > 0)
	{
		do
		{
			cout << "Quante monete vuoi prendere? (1 a 3) " << endl;
			cin >> moneteRaccolteP;
			
			if(moneteRaccolteP <= 0 || moneteRaccolteP >= 4)
			{
				cout << "Ti ho detto di inserire un nuero da 1 a 3!";
			}
		}
		while(moneteRaccolteP <= 0 || moneteRaccolteP >= 4);
		
		
		monete -= moneteRaccolteP;
		
		switch(moneteRaccolteP)
		{
			case 1:
				moneteRaccolteM = 3;
				monete -= moneteRaccolteM;
				cout << "Il computer ha raccolto " << moneteRaccolteM << " monete. Rimangono " << monete << " monete" << endl;
				break;
			
			case 2:
				moneteRaccolteM = 2;
				monete -= moneteRaccolteM;
				cout << "Il computer ha raccolto " << moneteRaccolteM << " monete. Rimangono " << monete << " monete" << endl;
				break;
				
			case 3:
				moneteRaccolteM = 1;
				monete -= moneteRaccolteM;
				cout << "Il computer ha raccolto " << moneteRaccolteM << " monete. Rimangono " << monete << " monete" << endl;
				break;		
		}
		
		if(monete <= 0)
		{
			cout << "Le monete sono finite.";
		}
	}
}

void facile() //inizio della difficoltà facile
{
	int probInizio, probSconf;
	srand(time(NULL));
	
	probInizio = rand()%10 + 1; 
	probSconf = rand()%100 + 1; 
	
	if(probInizio % 2 == 0)
	{
		if(probSconf >= 90)
		{
			inizioGiocatoreDeterminato();
		}
		else
		{
			inizioGiocatoreCasuale();
		}
	}
	else
	{
		if(probSconf >= 90)
		{
			inizioMacchinaDeterminato();
		}
		else
		{
			inizioMacchinaCasuale();
		}
	}
}

void medio() //inizio della difficoltà media
{
	int probInizio, probSconf;
	srand(time(NULL));
	
	probInizio = rand()%10 + 1; 
	probSconf = rand()%100 + 1; 
	
	if(probInizio % 2 == 0)
	{
		if(probSconf >= 60)
		{
			inizioGiocatoreDeterminato();
		}
		else
		{
			inizioGiocatoreCasuale();
		}
	}
	else
	{
		if(probSconf >= 60)
		{
			inizioMacchinaDeterminato();
		}
		else
		{
			inizioMacchinaCasuale();
		}
	}
}

void difficile() //inizio della difficoltà difficile
{
	int probInizio, probSconf;
	srand(time(NULL));
	
	probInizio = rand()%10 + 1; 
	probSconf = rand()%100 + 1; 
	
	if(probInizio % 2 == 0)
	{
		if(probSconf >= 10)
		{
			inizioGiocatoreDeterminato();
		}
		else
		{
			inizioGiocatoreCasuale();
		}
	}
	else
	{
		if(probSconf >= 10)
		{
			inizioMacchinaDeterminato();
		}
		else
		{
			inizioMacchinaCasuale();
		}
	}
}

int main()   //inizio della struttura principale del programma
{
	char diff; 
	
	cout << "Ciao! Seleziona la difficolta': " << endl;
	cout << "F = facile, M = medio, D = difficile" << endl;
	cin >> diff;
	
	switch(diff) //scelta difficoltà
	{
		case 'f':
			facile();
			break;
		case 'm':
			medio();
			break;
		case 'd':
			difficile();
			break;
		default:
			cout << "Inserisci una difficoltà valida!";
			main();
			break;	
	}
}
