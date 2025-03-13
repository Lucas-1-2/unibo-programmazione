#include <stdio.h>
#include <stdlib.h>

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
    // Aggiornare Caratteri_Stampati con il numero di caratteri stampati in ciascuna printf
    Caratteri_Stampati += printf("intero: %15d \noccupazione in memoria della variabile in byte: %d \n\n", intero, sizeof(int));
    Caratteri_Stampati += printf("intero corto: %5d \noccupazione in memoria della variabile in byte: %d \n\n", intero_corto, sizeof(short int));
    Caratteri_Stampati += printf("intero lungo: %d \noccupazione in memoria della variabile in byte: %d \n\n", intero_lungo, sizeof(long int));
    Caratteri_Stampati += printf("intero senza segno: %d \noccupazione in memoria della variabile in byte: %d \n\n", intero_no_segno, sizeof(unsigned int));
    Caratteri_Stampati += printf("intero lungo senza segno: %d \noccupazione in memoria della variabile in byte: %d \n\n", lungo_intero_no_segno, sizeof(unsigned long int));
    Caratteri_Stampati += printf("carattere: %c \noccupazione in memoria della variabile in byte: %d \n\n", carattere, sizeof(char));
    Caratteri_Stampati += printf("carattere senza segno: %c \noccupazione in memoria della variabile in byte: %d \n\n", carattere_no_segno, sizeof(unsigned char));
    Caratteri_Stampati += printf("decimale: %9.5f \noccupazione in memoria della variabile in byte: %d \n\n", decimale, sizeof(float));
    Caratteri_Stampati += printf("decimale con precisione doppia: %.8f \noccupazione in memoria della variabile in byte: %d \n\n", decimale_precisione_doppia, sizeof(double));
    Caratteri_Stampati += printf("decimale con precisione estesa: %f \noccupazione in memoria della variabile in byte: %d \n\n", decimale_precisione_estesa, sizeof(long double));

    // Stampare il numero totale di caratteri stampati
    Caratteri_Stampati += printf("caratteri stampati totale: ");
    printf("%d \n", Caratteri_Stampati);

    // Attendere l'input dell'utente prima di chiudere il programma
    system("pause");
    return 0;
}

