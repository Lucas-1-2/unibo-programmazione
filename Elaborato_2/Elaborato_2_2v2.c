/*
Elaborato 2
Esercizio 2
Versione 2

L’utente pensa ad un numero e il computer lo deve indovinare compiendo le seguenti operazioni.

L’utente fissa un intervallo entro cui generare il valore da indovinare (min, max). Se i valori inseriti non rispettano il vincolo 0<min<=max, l’operazione di lettura va ripetuta
L’utente pensa ad un numero compreso tra min e max.
Il programma cerca di indovinare la scelta dell’utente e propone un numero. A seconda della situazione l’utente deve dire al programma se
- il numero da indovinare è più piccolo;
- il numero da indovinare è più grande;
- ha indovinato.
Scrivere una versione di programma (Versione 1) in cui non c'è limite al numero di tentativi che il programma può fare per indovinare il numero e scriverne un'altra (Versione 2) in cui invece viene posto tale limite.

Il programma deve stampare il numero di tentativi fatti.


Fucci, Lazzari, Prati, Salvetti

*/

#include<stdio.h>
#include <stdlib.h>


int main(){
	
	int Num, Max, Min, Tent, Old_Tent, Risp, N_Tent = 0, New_Min, New_Max, Max_Tent;
	
	// Etichetta
	Start:
		// Inserimento del range numerico e del numero massimo di tentativi
		printf("Inserire il valore minimo dell'intervallo numerico: ");
		scanf("%d", &Min);
		printf("Inserire il valore massimo dell'intervallo numerico: ");
		scanf("%d", &Max);
		printf("Inserire il numero massimo di tentativi: ");
		scanf("%d", &Max_Tent);
	
		// Verifica del range numerico
		if ((0 < Min) && (Min <= Max)) {
			printf("\nIntervallo di valori %d - %d impostato correttamente\n\n", Min, Max);
		
		// In caso di errore, avverte l'utente evidenziandoglielo e richiede un nuovo inserimento
		} else {
			printf("Errore nell'intervallo %d - %d, \nIl valore minimo (%d) deve essere compreso tra 0 (escuso) e il valore massimo \n\nSi prega di riprovare\n\n", Min, Max, Min);
			system("pause"); 			// Attesa della pressione di un tasto da parte dell'utente per continuare
			system("@cls||clear"); 		// Pulizia del terminale
			goto Start;					// Vai all'etichetta "Start"
		}
	
		// Etichetta
		Input_Num:
			printf("Pensa ad un numero compreso nell'intervallo %d - %d che il programma tentera' di indovinare: ", Min, Max);
			scanf("%d", &Num);
	
			// Verifica che il numero da indovinare sia compreso nell'intervallo impostato precedentemente
			if (!(Min <= Num) || !(Num <= Max)){
				printf ("Errore, il numero che hai scelto (%d) deve essere compreso tra %d e %d\n\nSi prega di riprovare\n\n", Num, Min, Max);
				system("pause"); 			// Attesa della pressione di un tasto da parte dell'utente per continuare
				system("@cls||clear"); 		// Pulizia del terminale
				goto Input_Num;				// Vai all'etichetta "Input_Num"
			}
	
			// Imposta come tentativo il valore cetrale del range numerico
			Tent = (Max - Min) / 2 + Min;
			New_Max = Max;
			New_Min = Min;
			
			// Tentativo di indovinare il numero
			Tentativo:
				N_Tent++;
				
				// Verifico di non aver raggiunto il numero massimo di tentativi
				if (N_Tent <= Max_Tent){
					Old_Tent = Tent;
					// Eticheta
					Risposta:
						printf("\nTentativo %d: Il tuo numero e' %d \n\nInserisci 1 se il numero che hai scelto e' piu' piccolo \nInserisci 2 se il numero che hai scelto e' piu' grande \nInserisci 3 se ho indovinato \n\n", N_Tent, Tent);
						scanf("%d", &Risp);
				
						// Opzione dove il tentativo è maggiore del numero da indovinare
						if (Risp == 1){
							New_Max = Old_Tent;
							Tent = (Old_Tent - New_Min) / 2 + New_Min;
					
						// Opzione dove il tentativo è minore del numero da indovinare
						} else if (Risp == 2) {
							New_Min = Old_Tent;
							Tent = (New_Max - Old_Tent) / 2 + Old_Tent;
						
						// Opzione dove il tentativo è uguale al numero da indovinare
						} else if (Risp == 3) {
							printf("\nEvvai ho indovinato, il tuo numero e' %d, e ci ho impegato solo %d tentativo/i. \nDaje Roma\n", Tent, N_Tent);
							// Attende l'input dell'utente prima di chiudere il programma
    						system("pause");
    						return 0;
						
						// Opzione dove l'inserimento non corrisponde alle opzioni fornite
						} else {
							printf ("Errore, il numero che hai inserito (%d) deve essere compreso tra 1 e 3\n\nSi prega di riprovare\n\n", Risp);
							system("pause"); 			// Attesa della pressione di un tasto da parte dell'utente per continuare
							system("@cls||clear"); 		// Pulizia del terminale
							goto Risposta;				// Vai all'etichetta "Risposta"
						}
					
						goto Tentativo;					// Vai all'etichetta "Tentativo"
				 
				} else {
					printf("\nPurtroppo non sono riuscito ad indovinare il numero entro i tentativi massimi (%d)\n\n", Max_Tent);
					// Attende l'input dell'utente prima di chiudere il programma
    				system("pause");
    				return 0;
				}
}


