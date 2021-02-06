#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int controlloInput(int input)
{
	do
	{
		printf("Quante monete vuoi prendere? (da 1 a 3) ");
		scanf("%d", &input);
		
		if(input <= 0 || input >= 4)
		{
			printf("Ti ho detto di inserire un numero da 1 a 3!");
		}
	}
	while(input <= 0 || input >= 4);
	
	return input;
}


void inizioMacchinaCasuale(int monete, int mrp, int mrm)
{
	// mrp = moneteRaccoltePlayer, mrm = moneteRaccolteMacchina
	srand(time(NULL));
	while(monete > 0)
	{
		mrm = rand()%3 + 1;
		monete -= mrm;
		
		printf("Il computer ha preso %d monete. Rimangono %d monete", moneteRaccolteM, monete);
	
		controlloInput(mrp);
		
		monete -= moneteRaccolteP;
	
	}
	
}

void inizioMacchinaDeterminato(int monete, int mrp, int mrm)
{
	srand(time(NULL));
	
	while(monete > 0)
	{
		moneteRaccolteM = rand()%3 + 1;
		monete -= moneteRaccolteM;
		
		printf("Il computer ha preso %d monete. Rimangono %d monete", moneteRaccolteM, monete);
		
		controlloInput(mrp);
		
		switch(mrp)
		{
			case 1:
				mrm = 3;
				monete -= mrm;
				printf("Il computer ha raccolto %d monete. Rimangon %d monete \n", mrm, monete);
				break;
			
			case 2:
				mrm = 2;
				monete -= mrm;
				printf("Il computer ha raccolto %d monete. Rimangon %d monete \n", mrm, monete);
				break;
				
			case 3:
				mrm = 1;
				monete -= mrm;
				printf("Il computer ha raccolto %d monete. Rimangon %d monete \n", mrm, monete);
				break;		
		
		}
		
		
	}	

}

void inizioGiocatoreCasuale(int monete, int mrp, int mrm)
{

	srand(time(NULL));
	
	while (monete > 0)
	{
		
		controlloInput(mrp);
		
		monete -= mrp;
		mrm = rand()%3 + 1;
		monete -= mrm;
		
		printf("Il computer ha raccolto %d monete. Rimangon %d monete \n", mrm, monete);
		
	
	}
}

void inizioGiocatoreDeterminato(int monete, int mrp, int mrm)
{
	
	while(monete > 0)
	{
		controlloInput(mrp);
		
		
		monete -= mrp;
		
		switch(mrp)
		{
			case 1:
				mrm = 3;
				monete -= mrm;
				printf("Il computer ha raccolto %d monete. Rimangon %d monete \n", mrm, monete);
				break;
			
			case 2:
				mrm = 2;
				monete -= mrm;
				printf("Il computer ha raccolto %d monete. Rimangon %d monete \n", mrm, monete);
				break;
				
			case 3:
				mrm = 1;
				monete -= mrm;
				printf("Il computer ha raccolto %d monete. Rimangon %d monete \n", mrm, monete);
				break;		
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
