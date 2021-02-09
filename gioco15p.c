#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int controlloInputPlayer(int input, int m) //m = monete
{
	do
	{
		printf("Quante monete vuoi prendere? (da 1 a 3) \n");
		scanf("%d", &input);
		
		if(input <= 0 || input >= 4)
		{
			printf("Ti ho detto di inserire un numero da 1 a 3! \n");
		}
		
		if(input > m)
		{
			printf("Non puoi prendere piu' monete di quelle che ci sono sul tavolo \n");
		}
	}
	while(input <= 0 || input >= 4 && input > m);
	
	return input;
}

int controlloInputMacchina(int inputM, int m) //m = monete
{
	srand(time(NULL));
	while(inputM > m)
	{
		printf("Non puoi prendere piu' monete di quante ce ne siano sul tavolo \n");
		inputM = rand()%3 + 1;
	}
	
	return inputM;
}

void inizioMacchinaCasuale(int monete, int mrp, int mrm)
{
	// mrp = moneteRaccoltePlayer, mrm = moneteRaccolteMacchina
	srand(time(NULL));
	do
	{
		mrm = rand()%3 + 1;
		
		controlloInputMacchina(mrm, monete);
		printf("Il computer ha preso %d monete. Rimangono %d monete", mrm, monete);
		monete -= mrm;
	
		
		controlloInputPlayer(mrp, monete);
		monete -= mrp;
	
	}
	while(monete > 0);
}

void inizioMacchinaDeterminato(int monete, int mrp, int mrm)
{
	srand(time(NULL));
	
	do
	{
		mrm = rand()%3 + 1;
		
		controlloInputMacchina(mrm, monete);
		printf("Il computer ha preso %d monete. Rimangono %d monete", mrm, monete);
		monete -= mrm;
		
		controlloInputPlayer(mrp, monete);
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
	while(monete > 0);	

}

void inizioGiocatoreCasuale(int monete, int mrp, int mrm)
{

	srand(time(NULL));
	
	do
	{
		
		controlloInputPlayer(mrp, monete);
		monete -= mrp;
		
		mrm = rand()%3 + 1;
		
		controlloInputMacchina(mrm, monete);
		printf("Il computer ha preso %d monete. Rimangono %d monete", mrm, monete);
		monete -= mrm;
		
	}
	while(monete > 0);
}

void inizioGiocatoreDeterminato(int monete, int mrp, int mrm)
{
	
	do
	{
		controlloInputPlayer(mrp, monete);
		
		
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
	while(monete > 0);
}

void facile(int monete) //inizio della difficoltà facile
{
	int probInizio, probSconf;
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

void medio(int monete) //inizio della difficoltà media
{
	int probInizio, probSconf;
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

void difficile(int monete) //inizio della difficoltà difficile
{
	int probInizio, probSconf;
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
	int monete = 11;
	printf("Ciao! Seleziona una difficolta': \n");
	printf("F = facile, M = medio, D = difficile. \n");
	scanf("%c", &diff);
	
	switch(diff) //scelta difficoltà
	{
		case 'f':
			facile(monete);
			break;
		case 'm':
			medio(monete);
			break;
		case 'd':
			difficile(monete);
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
