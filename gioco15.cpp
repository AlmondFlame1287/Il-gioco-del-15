#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
void facile() //inizio della difficoltà facile
{
	//possibilità di vincita del giocatore praticamente pari a 100
	int monete = 11;
	int probInizio;
	int moneteRaccolteP, moneteRaccolteM;
	srand(time(NULL));


	probInizio = rand()%10 + 1; //se pari allora inizia il giocatore altrimenti inizia la macchina

	while(monete > 0) //finchè il numero di monete non raggiunge lo 0
		if(probInizio % 2 == 0)
		{

			do 
			{
				cout << "Quante monete vuoi raccogliere? (da 1 a 3)";
				cin >> moneteRaccolteP;
				if (moneteRaccolteP <= 0 || moneteRaccolteP >= 4) 
				{
					cout << "Ti ho detto di scegliere tra 1 e 3!\n";
				}
			} 
			while(moneteRaccolteP <= 0 || moneteRaccolteP >= 4); // controllo dell'input
			
			// calcolo delle monete e prsa in un numero randomico da 1 a 3 per le monete prese dalla macchina
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
		else
		{
			
			moneteRaccolteM = rand()%3 + 1;
			monete -= moneteRaccolteM;
			
			cout << "Il computere ha preso " << moneteRaccolteM << " monete. Rimagono " << monete << " monete" << endl;
			cout << "Quante monete vuoi raccogliere? (1 a 3) ";
			cin >> moneteRaccolteP;
			
			monete -= moneteRaccolteP;
			
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
	//probabilità di vittoria casuale
	int monete = 11;
	int moneteRaccolteP, moneteRaccolteM;
	int probInizio;
	int probSconf;
	srand(time(NULL));
	
	probInizio = rand()%10 + 1; //numero randomico da 1 a 10
	probSconf = rand()%100 + 1; //numero randomico da 1 a 100
	
	if(probInizio % 2 == 0) //se il resto di probInizio == 0
	{
		if(probSconf >= 60) //se probSconfitta è maggiore o uguale a 0
		{
		
			do 
			{
				cout << "Quante monete vuoi raccogliere? (da 1 a 3)";
				cin >> moneteRaccolteP;
				
				if (moneteRaccolteP <= 0 || moneteRaccolteP >= 4) 
				{
					cout << "Ti ho detto di scegliere tra 1 e 3!\n";
				}
			} 
			while(moneteRaccolteP <= 0 || moneteRaccolteP >= 4);
			
			monete -= moneteRaccolteP;
		
			switch(moneteRaccolteP) //scelta delle monete da sottrarre per vincere
			{
				case 1:
					moneteRaccolteM = 3;
					monete -= moneteRaccolteM; 
					break;
				
				case 2:
					moneteRaccolteM = 2;
					monete -= moneteRaccolteM;
					break;
			
				case 3:
					moneteRaccolteM = 1;
					monete -= moneteRaccolteM;
					break;
			}
		
	
			cout << "Il computer ha preso " << moneteRaccolteM << " monete. Rimangono " << monete << " monete" << endl;  //restituisci il valore delle monete prese dal pc e le monete rimanenti
	
			if(monete < 0) //nel caso in cui le monete sono minore di 0 (dato che un umano non andrebbe a -monete), diamo per scontato che la macchina prende l'ultima moneta e quindi perde.
			{
				cout << "Il computer ha preso l'ultima moneta, e dunque hai vinto!" << endl;
			}
			else if(monete == 0) //altrimenti diamo per scontato che l'utente abbia preso l'ultima moneta e che dunque abbia perso
			{
				cout << "Hai preso l'ultima moneta. Hai perso!" << endl;
			}
		}
		
		else //se invece probSconf è minore di 60
		{
			while(monete > 0)
			{
				do 
				{
					cout << "Quante monete vuoi raccogliere? (da 1 a 3)";
					cin >> moneteRaccolteP;
					if (moneteRaccolteP <= 0 || moneteRaccolteP >= 4) 
					{
						cout << "Ti ho detto di scegliere tra 1 e 3!\n";
					}
				}
				
				while(moneteRaccolteP <= 0 || moneteRaccolteP >= 4);
			
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
	}
	
		
		
	else //se invece probInizio non è pari
	{
		moneteRaccolteM = rand()%3 + 1;
		monete -= moneteRaccolteM;
		
		cout << "Il computere ha preso " << moneteRaccolteM << " monete. Rimagono " << monete << " monete" << endl;
		cout << "Quante monete vuoi raccogliere? (1 a 3) ";
		cin >> moneteRaccolteP;
		
		monete -= moneteRaccolteP;
		
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


void difficile() //inizio della difficoltà difficile
{
	//possibilità di vincita del giocatore praticamente pari a 0
	int monete = 11;
	int moneteRaccolteP, moneteRaccolteM;
	int probInizio, probSconf;
	srand(time(NULL));
	
	probInizio = rand()%10 + 1; 
	probSconf = rand()%100 + 1; 
	
	while(monete > 0)
	{
		if(probSconf >= 10)
		{
			if(probInizio % 2 == 0)
			{
				do 
				{
					cout << "Quante monete vuoi raccogliere? (da 1 a 3)";
					cin >> moneteRaccolteP;
				
					if (moneteRaccolteP <= 0 || moneteRaccolteP >= 4) 
					{
						cout << "Ti ho detto di scegliere tra 1 e 3!\n";
					}
				} 
				while(moneteRaccolteP <= 0 || moneteRaccolteP >= 4);
			
			monete -= moneteRaccolteP;
			moneteRaccolteM = rand()%3 + 1;
			monete -= moneteRaccolteM;
			
			cout << "Il computere ha preso " << moneteRaccolteM << " monete. Rimagono " << monete << " monete" << endl;
			
			}
			
			else
			{
				cout << "Inizia l'AI che prende 2 monete" << endl;
				monete -= 2;
				do 
				{
					cout << "Quante monete vuoi raccogliere? (da 1 a 3)";
					cin >> moneteRaccolteP;
					if (moneteRaccolteP <= 0 || moneteRaccolteP >= 4) 
					{
						cout << "Ti ho detto di scegliere tra 1 e 3!\n";
					}
				} 
				while(moneteRaccolteP <= 0 || moneteRaccolteP >= 4); // controllo dell'input
				 
				switch(moneteRaccolteP)
				{
					case 1:
						moneteRaccolteM = 3;
						monete -= moneteRaccolteM;
						cout << "Il computer ha preso " << moneteRaccolteM << " monete. Rimangono " << monete << " monete" << endl;
						break;
					
					case 2:
						moneteRaccolteM = 2;
						monete -= moneteRaccolteM;
						cout << "Il computer ha preso " << moneteRaccolteM << " monete. Rimangono " << monete << " monete" << endl;
						break;
					
					case 3:
						moneteRaccolteM = 1;
						monete -= moneteRaccolteM;
						cout << "Il computer ha preso " << moneteRaccolteM << " monete. Rimangono " << monete << " monete" << endl;
						break;	
				}
							
			}
			
			
			
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
		//	difficile();
			break;
		default:
			cout << "Inserisci una difficoltà valida!";
			main();
			break;	
	}
	
	
	
}
