/*
Elaborato 6
Esercizio 2
Versione 1

CONSEGNA:
Scrivere un programma C dove sono inizializzate una variabile di tipo int, una di tipo float, una di tipo double,
una di tipo char, ed un array di 5 interi (precisamente con i valori 10, 20, 30, 40, 50). 
Inizializzare un puntatore per ciascuna di queste variabili. 

Assegnare ad ogni variabile un valore tramite l'utilizzo della funzione scanf. 
Visualizzare il valore di ogni variabile in due modi: prima tramite accesso diretto alla variabile 
e a seguito tramite l'utilizzo del suo puntatore (accesso indiretto).

Visualizzare la posizione in memoria della variabile tramite l'utilizzo diretto della variabile e tramite il suo puntatore.
Visualizzare la posizione in memoria del puntatore.

Modificare il contenuto di ogni variabile e mostrare nuovamente le varie informazioni.
Porre attenzione nel mostrare messaggi di output dettagliati che chiariscano ciò che si visualizza,
in modo che il programma risulti un valido ausilio per spiegare il funzionamento dei puntatori.


Fucci, Lazzari, Prati, Salvetti

*/

#include <stdio.h>

int main(){
	
	int i, j;
	
	// Inizializzazione variabili e relativi puntatori
	int a, *p_a;
	float b, *p_b;
	double c, *p_c;
	char d, *p_d;
	int arr[5] = {10, 20, 30, 40, 50}, *p_arr;
	
	// Assegnazione puntatori
	p_a = &a;
	p_b = &b;
	p_c = &c;
	p_d = &d;
	p_arr = &arr;
	
	// Utilizzo un ciclo for per ripetere l'asssegnazione delle variabili e ricevere i medesimi feedback
	for(j=0; j<2; j++){
		// Assegnamento di valori tramite la funzione scanf
		printf("Assegna un valore intero: ");
		scanf(" %d", &a);
		
		printf("Assegna un valore float: ");
		scanf(" %f", &b);
		
		printf("Assegna un valore double: ");
		scanf(" %lf", &c);
		
		printf("Assegna un carattere: ");
		scanf(" %c", &d);
		
		
		// Visualizzo la variabile che vado a trattare
		// Visualizzo il valore di ogni variabile tramite accesso diretto alla variabile e a seguito tramite l'utilizzo del suo puntatore (accesso indiretto).
		// Visualizzo la posizione in memoria della variabile tramite l'utilizzo diretto della variabile e tramite il suo puntatore.
		// Visualizzo la posizione in memoria del puntatore.
		printf("\n\nVariabile 'a':");
		printf("\nValore diretto: %d \nValore indiretto: %d", a, *p_a);
		printf("\nPosizione in memoria: %X \nPosizione in memoria usando il relativo puntatore: %X", &a, p_a);
		printf("\nPosizione in memoria del relativo puntatore: %X", &p_a);
		
		printf("\n\nVariabile 'b':");
		printf("\nValore diretto: %f \nValore indiretto: %f", b, *p_b);
		printf("\nPosizione in memoria: %X \nPosizione in memoria usando il relativo puntatore: %X", &b, p_b);
		printf("\nPosizione in memoria del relativo puntatore: %X", &p_b);
		
		printf("\n\nVariabile 'c':");
		printf("\nValore diretto: %f \nValore indiretto: %f", c, *p_c);
		printf("\nPosizione in memoria: %X \nPosizione in memoria usando il relativo puntatore: %X", &c, p_c);
		printf("\nPosizione in memoria del relativo puntatore: %X", &p_c);
		
		printf("\n\nVariabile 'd':");
		printf("\nValore diretto: %c \nValore indiretto: %c", d, *p_d);
		printf("\nPosizione in memoria: %X \nPosizione in memoria usando il relativo puntatore: %X", &d, p_d);
		printf("\nPosizione in memoria del relativo puntatore: %X", &p_d);
		
		printf("\n\nVariabile 'arr':");
		printf("\nValori diretti: ");
		for(i=0; i<5; i++) printf("%d ", arr[i]);
		printf("\nValori indiretti: ");
		for(i=0; i<5; i++) printf("%d ", *(p_arr+i));
		for(i=0; i<5; i++) printf("\nPosizione in memoria (%d): %X", i, &arr[i]);
		for(i=0; i<5; i++) printf("\nPosizione in memoria (%d) usando il relativo puntatore: %X", i, (p_arr+i));
		printf("\nPosizione in memoria del relativo puntatore: %X", &p_arr);
		
		
		printf("\n\n\n\n\n");
		system("pause");
	}
		
	return 0;
}
