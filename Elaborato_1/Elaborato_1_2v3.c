/*
Versione 3 che implementa variabili costanti per memorizzare i valori di conversione da miglia a chilometri e da galloni a litri

Fucci, Lazzari, Prati, Salvetti
*/



#include <stdio.h> 		// Includo la libreria per il terminale


int main()
{
	// Dichiaro le variabili di tipo float per permettere la gestione dei valori con la virgola
    const float miglia;			
    const float galloni;		
    float miglia_x_galloni;		
    float litri;				
    float chilometri;			
    float litri_x_chilometri;	
    
    // Utilizzo le costanti per i valori di conversione da miglia a chilometri e da galloni a litri
    const float Conversione_km = 1.60934;
	const float Conversione_lt = 3.78541;

    printf("Inserire il numero di galloni: ");						//stampo nel terminale
    scanf("%f", &galloni);											//aspetto che l'utente inserisca un valore e attribuisco quest'ultimo alla variabile "galloni"
    printf("Il numero di galloni inserito e': %f\n\n", galloni);	//stampo nel terminale
    printf("Inserire il numero di miglia percorse: ");				//stampo nel terminale
    scanf("%f", &miglia);											//aspetto che l'utente inserisca un valore e attribuisco quest'ultimo alla variabile "miglia"
    printf("Il numero di miglia percorse e': %f\n\n", miglia);		//stampo nel terminale

    miglia_x_galloni = miglia / galloni;										//calcolo le miglia per gallone
    printf("Il numero di miglia per gallone e': %.2f\n", miglia_x_galloni);		//stampo nel terminale il risultato della riga precedente

    chilometri = miglia * Conversione_km;		//converto le miglia in chilometri e assegno il valore alla variabile chilometri
    litri = galloni * Conversione_lt;			//converto i galloni in litri e assegno il valore alla variabile litri

  	litri_x_chilometri = (litri / chilometri) * 100;									//calcolo quanti litri l'utente utilizza per 100km
    printf("Hai consumato: %.3f litri per 100 chilometri \n\n", litri_x_chilometri);	//stampo nel terminale il risultato della riga precedente
    
    // Attende l'input dell'utente prima di chiudere il programma
    system("pause");
    return 0;

}
