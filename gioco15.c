#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int controlloInput(int input)
{
	do
	{
		printf("Quante monete vuoi prendere? (da 1 a 3) \n");
		scanf("%d", &input);
		
		if(input <= 0 || input >= 4)
		{
			printf("Ti ho detto di inserire un numero da 1 a 3! \n");
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
		
		printf("Il computer ha preso %d monete. Rimangono %d monete \n", mrm, monete);
	
		controlloInput(mrp);
		
		monete -= mrp;
	
	}
	
}

void inizioMacchinaDeterminato(int monete, int mrp, int mrm)
{
	srand(time(NULL));
	
	while(monete > 0)
	{
		mrm = rand()%3 + 1;
		monete -= mrm;
		
		printf("Il computer ha preso %d monete. Rimangono %d monete \n", mrm, monete);
		
		
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
	int monete = 11;
	int moneteRaccolteP, moneteRaccolteM;
	srand(time(NULL));
	
	moneteRaccolteP = moneteRaccolteM = 0;
	probInizio = rand()%10 + 1; 
	probSconf = rand()%100 + 1; 
	
	if(probInizio % 2 == 0)
	{
		if(probSconf >= 90)
		{
			inizioGiocatoreDeterminato(monete, moneteRaccolteP, moneteRaccolteM);
		}
		else
		{
			inizioGiocatoreCasuale(monete, moneteRaccolteP, moneteRaccolteM);
		}
	}
	else
	{
		if(probSconf >= 90)
		{
			inizioMacchinaDeterminato(monete, moneteRaccolteP, moneteRaccolteM);
		}
		else
		{
			inizioMacchinaCasuale(monete, moneteRaccolteP, moneteRaccolteM);
		}
	}
}

void medio() //inizio della difficoltà media
{
	int probInizio, probSconf;
	int monete = 11;
	int moneteRaccolteP, moneteRaccolteM;
	srand(time(NULL));
	
	probInizio = rand()%10 + 1; 
	probSconf = rand()%100 + 1; 
	
	if(probInizio % 2 == 0)
	{
		if(probSconf >= 60)
		{
			inizioGiocatoreDeterminato(monete, moneteRaccolteP, moneteRaccolteM);
		}
		else
		{
			inizioGiocatoreCasuale(monete, moneteRaccolteP, moneteRaccolteM);
		}
	}
	else
	{
		if(probSconf >= 60)
		{
			inizioMacchinaDeterminato(monete, moneteRaccolteP, moneteRaccolteM);
		}
		else
		{
			inizioMacchinaCasuale(monete, moneteRaccolteP, moneteRaccolteM);
		}
	}
}

void difficile() //inizio della difficoltà difficile
{
	int probInizio, probSconf;
	int monete = 11;
	int moneteRaccolteP, moneteRaccolteM;
	srand(time(NULL));
	
	probInizio = rand()%10 + 1; 
	probSconf = rand()%100 + 1; 
	
	if(probInizio % 2 == 0)
	{
		if(probSconf >= 10)
		{
			inizioGiocatoreDeterminato(monete, moneteRaccolteP, moneteRaccolteM);
		}
		else
		{
			inizioGiocatoreCasuale(monete, moneteRaccolteP, moneteRaccolteM);
		}
	}
	else
	{
		if(probSconf >= 10)
		{
			inizioMacchinaDeterminato(monete, moneteRaccolteP, moneteRaccolteM);
		}
		else
		{
			inizioMacchinaCasuale(monete, moneteRaccolteP, moneteRaccolteM);
		}
	}
}

int main()   //inizio della struttura principale del programma
{
	char diff; 
	
	printf("Ciao! Seleziona una difficolta': \n");
	printf("F = facile, M = medio, D = difficile. \n");
	scanf("%c", &diff);
	
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
			do
			{
				printf("Ciao! Seleziona una difficolta': \n");
				printf("F = facile, M = medio, D = difficile. \n");
				scanf("%c", &diff);
				if(diff != 'f' || diff != 'm' || diff != 'd')
				{
					printf("Inserisci una difficolta' esistente!\n");
				}
			}
			while(diff != 'f' || diff != 'm' || diff != 'd');
			break;	
	}
}
