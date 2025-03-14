/*
Elaborato 4
Esercizio 1
Versione 2		!!! Implementa la scelta sulla generazione dei vettori 1 e 2: completamente automatica o completamente manuale. !!!

Siano dati due vettori di interi di lunghezza differente.
Scrivere un programma C che inserisca i valori da tastiera e che lo faccia anche generandoli in maniera pseudo-casuale.
Il programma deve poi generare un terzo vettore contenente l�intersezione tra i due vettori di input.
Implementare sia la variante in cui le ripetizioni di un elemento nei vettori di input vengono riportate anche nel vettore risultato,
sia quella in cui le ripetizioni non sono inserite nel risultato.

Implementare poi la generazione di un quarto vettore contenente l'unione dei due vettori di input.

Il programma deve inoltre stampare gli indirizzi di memoria occupati dagli elementi dei vettori
e la loro dimensione totale in termini di numero di byte.



Fucci, Lazzari, Prati, Salvetti

*/


#include <stdio.h>
#include <time.h>


int main() {
	// Variabili costanti da modificare per variare il programma
	const int n1 = 3, n2 = 5, max = 3, min = 1;
	
	int vet1 [n1];
	int vet2 [n2];
	int vet3 [n1+n2];
	int vet4 [n1+n2];
	int i, t, j, risp, cursore = 0, ripetizione = 0;
	
	// Inizializzazione del vettore 3 con degli 0
	for(i=0; i<(n1+n2); i++) {
		vet3[i] = 0;
	}
	
	inizio:
	// Richiesta sulla tipologia di riempimento dei vettori vet1 e vet2
	printf("Come si desiderano creare i vettori?\n1) Automaticamente con numeri casuali compresi tra %d e %d.\n2) Voglio riempire i vettori manualmente.\n\nRisposta: ", min, max);
	scanf("%d", &risp);
	
	// Generazione Vettori 1 e 2 in base alla risposta "risp"
	switch(risp){
		case 1:
			printf("\nOk, genero i vettori in maniera automatica.");
			// Inizializzo la generazione casuale di valori
			srand(time(NULL));
			
			// Riempio il vettore vet1 con valori casuali compresi fra min e max
			printf("\nVettore 1 (casuale): ");
			for(i=0; i<n1; i++){
				vet1[i] = rand() % (max - min + 1) + min; 		//generazione di un numero casuale da min a max
				printf("%d ", vet1[i]);
				vet4[i] = vet1[i];
			}
			
			// Riempio il vettore vet2 con valori casuali compresi fra min e max
			printf("\nVettore 2 (casuale): ");
			for(i=0; i<n2; i++){
				vet2[i] = rand() % (max - min + 1) + min; 		//generazione di un numero casuale da min a max
				printf("%d ", vet2[i]);
				vet4[n1+i] = vet2[i];
			}
			
			break;
			
		case 2:
			// Riempimento manuale vettore 1
			printf("\nOk, inserisci %d numeri interi per il vettore 1:\n", n1);
			for(i=0; i<n1; i++){
				printf("Valore %d per il vettore 1: ", i+1);
				scanf("%d", &vet1[i]);
				vet4[i] = vet1[i];
			}

			// Riempimento manuale vettore 2
			printf("\nOra Inserisci %d numeri interi per il vettore 2:\n", n2);
			for(i=0; i<n2; i++){
				printf("Valore %d per il vettore 2: ", i+1);
				scanf("%d", &vet2[i]);
				vet4[n1+i] = vet2[i];
			}
			
			break;
			
		default:
			printf ("\nErrore, il numero che hai inserito (%d) deve essere compreso tra 1 e 2\nSi prega di riprovare\n\n", risp);
			system("pause"); 			// Attesa della pressione di un tasto da parte dell'utente per continuare
			system("@cls||clear"); 		// Pulizia del terminale
			goto inizio;				// Vai all'etichetta "inizio"
			break;
	}
	
	
	printf("\n");
	// Stampo gli indirizzi di memoria del vettore 1 e la sua dimensione totale in byte
	for(i=0; i<n1; i++) printf("\nIndirizzo di memoria vettore 1 (posizione %d):\t%X ", i, &vet1[i]);
	printf("\nDimensione totale vettore 1: %d byte\n", sizeof(*vet1)*(n1));
	
	// Stampo gli indirizzi di memoria del vettore 2 e la sua dimensione totale in byte
	for(i=0; i<n2; i++) printf("\nIndirizzo di memoria vettore 2 (posizione %d):\t%X ", i, &vet2[i]);
	printf("\nDimensione totale vettore 2: %d byte", sizeof(*vet2)*(n2));
	
	// Riempimento vettore vet3 contenente l'intersezione senza ripetizione fra vet1 e vet2
	for(i=0; i<n1; i++ ){
		for(t=0; t<n2; t++){
			if (vet1[i] == vet2[t]){
				for(j=0; j<(n1+n2); j++){
					if(vet1[i] == vet3[j]){		// Se il confronto fra il valore del vettore 1 e uno del vettore 3 � uguale significa che ho gi� inserito il numero nel vettore
						ripetizione = 1;		// Imposto la variabile a 1 per evitare successivamente di inserire un duplicato all'interno di vet3	
					}
				}
				if(ripetizione == 0){
					vet3[cursore] = vet2[t];
					cursore++;
				}
				ripetizione = 0;
			}
		}
	}
	
	// Stampa del terzo vettore senza ripetizione
	printf("\n\nVettore 3 senza ripetizione:\t");
	for(i=0; i<(n1+n2); i++) printf("%d ", vet3[i]);
	
	// Riempimento vettore vet3 contenente l'intersezione con ripetizione fra vet1 e vet2
	cursore = 0;
	for(i=0; i<n1; i++ ){
		for(t=0; t<n2; t++){
			if (vet1[i] == vet2[t]){
				vet3[cursore] = vet2[t];
				cursore++;
				vet1[i] = 0;
				vet2[t] = 0;
			}
		}
	}
	
	// Stampa del terzo vettore con ripetizione
	printf("\nVettore 3 con ripetizione:\t");
	for(i=0; i<(n1+n2); i++) printf("%d ", vet3[i]);
	for(i=0; i<(n1+n2); i++) printf("\nIndirizzo di memoria vettore 3 (posizione %d):\t%X ", i, &vet3[i]);
	printf("\nDimensione totale vettore 3: %d byte", sizeof(*vet3)*(n1+n2));
	 
	// Stampa del quarto vettore
	printf("\n\nVettore 4 (unione 1 e 2):\t");
	for(i=0; i<(n1+n2); i++) printf("%d ", vet4[i]);
	for(i=0; i<(n1+n2); i++) printf("\nIndirizzo di memoria vettore 4 (posizione %d):\t%X ", i, &vet4[i]);
	printf("\nDimensione totale vettore 4: %d byte\n\n", sizeof(*vet4)*(n1+n2));
	
	system("pause");
	return 0;

}
