/*
Versione 2 che si presta ad implementare tramite la funzione "printf();"
la stampa dei valori massimi e minimi di ciascuna variabile utilizzando la libreria limits.h
per le tipologie intere e float.h per le tipologie con virgooa mobile

Fucci, Lazzari, Prati, Salvetti
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Includiamo la libreria limits.h per ottenere i limiti dei tipi interi
#include <float.h> // Per ottenere i limiti dei tipi in virgola mobile

int main()
{
    // Dichiarazione e inizializzazione di diverse variabili di diversi tipi
    int intero = 30000;
    short int intero_corto = -100;
    long int intero_lungo = 4037400;
    unsigned int intero_no_segno = 61109;
    unsigned long int lungo_intero_no_segno = 40009800;
    char carattere = 'a';
    unsigned char carattere_no_segno = 'b';
    float decimale = 3.141;
    double decimale_precisione_doppia = 0.000052;
    long double decimale_precisione_estesa = 3.205253;

    // Variabile per tenere traccia del numero totale di caratteri stampati
    int Caratteri_Stampati = 0;


    // Stampare i valori delle variabili e le dimensioni in byte delle variabili, sono stati utilizzate anche formattazioni quali: modificatori, campo minimo, precisione, specifica conversione
    // Aggiornare la variabile Caratteri_Stampati con il numero di caratteri stampati in ciascuna printf
    // Stampare i valori massimi e minimi che possono essere contenuti in ciascuna variabile tramite le librerie limits.h e float.
    
    // Int
    Caratteri_Stampati += printf("intero: %15d \noccupazione in memoria della variabile in byte: %d \n", intero, sizeof(int));
    Caratteri_Stampati += printf("Valore massimo di 'int': %d\n", INT_MAX); // Stampa il valore massimo di 'int'
    Caratteri_Stampati += printf("Valore minimo di 'int': %d\n\n", INT_MIN); // Stampa il valore minimo di 'int'

	// Short int
    Caratteri_Stampati += printf("intero corto: %d \noccupazione in memoria della variabile in byte: %d \n", intero_corto, sizeof(short int));
    Caratteri_Stampati += printf("Valore massimo di 'short int': %d\n", SHRT_MAX); // Stampa il valore massimo di 'short int'
    Caratteri_Stampati += printf("Valore minimo di 'short int': %d\n\n", SHRT_MIN); // Stampa il valore minimo di 'short int'

	// Long int
    Caratteri_Stampati += printf("intero lungo: %d \noccupazione in memoria della variabile in byte: %d \n", intero_lungo, sizeof(long int));
    Caratteri_Stampati += printf("Valore massimo di 'long int': %ld\n", LONG_MAX); // Stampa il valore massimo di 'long int'
    Caratteri_Stampati += printf("Valore minimo di 'long int': %ld\n\n", LONG_MIN); // Stampa il valore minimo di 'long int'

	// Unsigned int
    Caratteri_Stampati += printf("intero senza segno: %u \noccupazione in memoria della variabile in byte: %d \n", intero_no_segno, sizeof(unsigned int));
    Caratteri_Stampati += printf("Valore massimo di 'unsigned int': %u\n\n", UINT_MAX); // Stampa il valore massimo di 'unsigned int'

	// Unsigned long int
    Caratteri_Stampati += printf("intero lungo senza segno: %lu \noccupazione in memoria della variabile in byte: %d \n", lungo_intero_no_segno, sizeof(unsigned long int));
    Caratteri_Stampati += printf("Valore massimo di 'unsigned long int': %lu\n\n", ULONG_MAX); // Stampa il valore massimo di 'unsigned long int'

	// Char
    Caratteri_Stampati += printf("carattere: %c \noccupazione in memoria della variabile in byte: %d \n", carattere, sizeof(char));
    Caratteri_Stampati += printf("Valore massimo di 'char': %d\n", CHAR_MAX); // Stampa il valore massimo di 'char'
    Caratteri_Stampati += printf("Valore minimo di 'char': %d\n\n", CHAR_MIN); // Stampa il valore minimo di 'char'

	// Unsigned char
	Caratteri_Stampati += printf("carattere senza segno: %c \noccupazione in memoria della variabile in byte: %d \n", carattere_no_segno, sizeof(unsigned char));
    Caratteri_Stampati += printf("Valore massimo di 'unsigned char': %u\n\n", UCHAR_MAX); // Stampa il valore massimo di 'unsigned char'

	// Float
    Caratteri_Stampati += printf("decimale: %9.5f \noccupazione in memoria della variabile in byte: %d \n", decimale, sizeof(float));
    Caratteri_Stampati += printf("Valore massimo di 'float': %f\n", FLT_MAX); // Stampa il valore massimo di 'float'
    Caratteri_Stampati += printf("Valore minimo di 'float': %f\n\n", FLT_MIN); // Stampa il valore minimo di 'float'

	// Double
    Caratteri_Stampati += printf("decimale con precisione doppia: %.8f \noccupazione in memoria della variabile in byte: %d \n", decimale_precisione_doppia, sizeof(double));
    Caratteri_Stampati += printf("Valore massimo di 'double': %lf\n", DBL_MAX); // Stampa il valore massimo di 'double'
    Caratteri_Stampati += printf("Valore minimo di 'double': %lf\n\n", DBL_MIN); // Stampa il valore minimo di 'double'

	// Long double
    Caratteri_Stampati += printf("decimale con precisione estesa: %Lf \noccupazione in memoria della variabile in byte: %d \n", decimale_precisione_estesa, sizeof(long double));
    Caratteri_Stampati += printf("Valore massimo di 'long double': %Lf\n", LDBL_MAX); // Stampa il valore massimo di 'long double'
    Caratteri_Stampati += printf("Valore minimo di 'long double': %Lf\n\n", LDBL_MIN); // Stampa il valore minimo di 'long double'



    // Stampa il numero totale di caratteri stampati
    Caratteri_Stampati += printf("caratteri stampati totale: ");
    printf("%d \n", Caratteri_Stampati);

    // Attende l'input dell'utente prima di chiudere il programma
    system("pause");
    return 0;
}

