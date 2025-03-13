/*
Elaborato 3
Esercizio 2
Versione 1

Scrivere un programma che legga da tastiera un testo terminato dal carattere '#'
e poi stampi le statistiche relative al numero di spazi, al numero di caratteri di nuova linea, 
al numero di caratteri letti, al numero di quelli maiuscoli, etc., 

utilizzando almeno una volta tutte le funzioni dell’header ctype.h.

Fucci, Lazzari, Prati, Salvetti

*/


#include <stdio.h>
#include <ctype.h>


int main() {
    char carattere;
    int spazi = 0, nuova_linea = 0, caratteri_letti = 0, maiuscoli = 0, caratteri_alfanumerici = 0, lettere = 0, caratteri_controllo = 0, caratteri_numerici = 0, caratteri_grafici = 0, minuscoli = 0, caratteri_stampabili = 0, punteggiatura = 0, esadecimali = 0;

    printf("Inserisci un testo (termina con #):\n");
    scanf("%c", &carattere);

    while ((carattere = getchar()) != '#'){
    	
	    caratteri_letti++;
	
	    if(isspace(carattere)){
	        spazi++;
	    }
	    
	    if(carattere == '\n'){
	       nuova_linea++;
	    }
	    
	    if(isupper(carattere)){
	        maiuscoli++;
	    }
	    
	    if(isalnum(carattere)){
	        caratteri_alfanumerici++;
	    }
	    
	    if(isalpha(carattere)){
	        lettere++;
	    }
	    
	    if(iscntrl(carattere)){
	        caratteri_controllo++;
	    }
	    
	    if(isdigit(carattere)){
	        caratteri_numerici++;
	    }
	    
	    if(isgraph(carattere)){
	        caratteri_grafici++;
	    }
	    
	    if(islower(carattere)){
	        minuscoli++;
	    }
	    
	    if(isprint(carattere)){
	        caratteri_stampabili++;
	    }
	    
	    if(ispunct(carattere)){
	        punteggiatura++;
	    }
	    
	    if(isxdigit(carattere)){
	        esadecimali++;
	    }
    
	}

    printf("numero di spazi: %d\n", spazi);

    printf("numero di nuove linee: %d\n", nuova_linea);

    printf("numero di caratteri maiuscoli: %d\n", maiuscoli);

    printf("numero di caratteri alfanumerici: %d\n", caratteri_alfanumerici);

    printf("numero di caratteri di controllo: %d\n", caratteri_controllo);

    printf("numero di caratteri numerici: %d\n", caratteri_numerici);

    printf("numero di caratteri grafici: %d\n", caratteri_grafici);

    printf("numero di caratteri minuscoli: %d\n", minuscoli);

    printf("numero di caratteri stampabili: %d\n", caratteri_stampabili);

    printf("numero di caratteri di punteggiatura: %d\n", punteggiatura);

    printf("numero di caratteri esadecimali: %d\n", esadecimali );


	system("pause");
    return 0;
}
