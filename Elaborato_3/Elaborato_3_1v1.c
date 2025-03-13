/*
Elaborato 3
Esercizio 1
Versione 1

Indovina il continente
In questo gioco, il computer visualizza una coppia di coordinate generata in maniera random sullo schermo per un breve periodo di tempo.
Il giocatore deve indovinare a quale continente appartiene la coppia di coordinate generate; fino a quando l�utente indovina,
il gioco prosegue con la generazione di una nuova coppia di coordinate. L'obiettivo � quello di continuare il processo il pi� a lungo possibile.

Al termine del gioco il programma calcoler� un punteggio ottenuto, quantomeno sulla base del numero di iterazioni eseguite 
(� possibile valutare altri criteri, ad esempio, la velocit� con cui l�utente risponde,
oppure un calcolo basato sulla difficolt� delle coordinate prodotte) e inviter� il giocatore a giocare di nuovo.

N.B.: i margini che definiscono i confini dei vari continenti sono decisi da voi


Fucci, Lazzari, Prati, Salvetti

*/

#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include <unistd.h>


int main(){
   
    double latitudine;
    double longitudine;
    int continente,scelta,risposta;
	int i=1;
    int punteggio = 0;
    int livello=0;
    int reset_livello=10;
    int new_livello;
    int reset_punteggio=0;
    int calcolo = 10;
    int min = 1;
    int max = 6;
    
    int america;                                      // corrisponde ad 1
    int lat_max_america =    80;
    int lat_min_america =   -60;
    int long_max_america =  -30;
    int long_min_america = -180;

    int africa;                                       // corrisponde ad 2
    int lat_max_africa =   40;
    int lat_min_africa =  -40;
    int long_max_africa =  60;
    int long_min_africa = -30;

    int oceania;                                      // corrisponde ad 3
    int lat_max_oceania =     0;
    int lat_min_oceania =   -40;
    int long_max_oceania =  150;
    int long_min_oceania =   90;

    int antartide;                                   // corrisponde ad 4
    int lat_max_antartide =   -60;
    int lat_min_antartide =   -90;
    int long_max_antartide =  180;
    int long_min_antartide = -180;

    int europa;                                       // corrisponde ad 5
    int lat_max_europa =   80;
    int lat_min_europa =   40;
    int long_max_europa =  60;
    int long_min_europa = -30;

    int asia;                                          // corrisponde ad 6
    int lat_max_asia =   80;
    int lat_min_asia =    0;
    int long_max_asia = 180;
    int long_min_asia =  60;
	
    srand(time(NULL));
    livello++;
	inizio:
	    continente = rand() % (max - min+ 1) + min; 		//generazione di un numero casuale da 1 a 6 per identificare il continente 
	
	    if(continente == 1){ 
	        latitudine = ((double)rand() / RAND_MAX) * (lat_max_america - lat_min_america) + lat_min_america;
	        longitudine = ((double)rand() / RAND_MAX) * (long_max_america - long_min_america) + long_min_america;
	        //printf("Latitudine: %f, Longitudine: %f\n",latitudine, longitudine);
	     }
	    if(continente == 2){ 
	        latitudine = ((double)rand() / RAND_MAX) * (lat_max_africa - lat_min_africa) + lat_min_africa;
	        longitudine = ((double)rand() / RAND_MAX) * (long_max_africa - long_min_africa) + long_min_africa;
	       // printf("Latitudine: %f, Longitudine: %f\n",latitudine, longitudine);
	     }
	    if(continente == 3){ 
	        latitudine = ((double)rand() / RAND_MAX) * (lat_max_oceania - lat_min_oceania) + lat_min_oceania;
	        longitudine = ((double)rand() / RAND_MAX) * (long_max_oceania - long_min_oceania) + long_min_oceania;
	       //printf("Latitudine: %f, Longitudine: %f\n",latitudine, longitudine);
	     }
	    if(continente == 4){ 
	        latitudine = ((double)rand() / RAND_MAX) * (lat_max_antartide - lat_min_antartide) + lat_min_antartide;
	        longitudine = ((double)rand() / RAND_MAX) * (long_max_antartide - long_min_antartide) + long_min_antartide;
	        //printf("Latitudine: %f, Longitudine: %f\n",latitudine, longitudine);
	     }
	    if(continente == 5){ 
	        latitudine = ((double)rand() / RAND_MAX) * (lat_max_europa - lat_min_europa) + lat_min_europa;
	        longitudine = ((double)rand() / RAND_MAX) * (long_max_europa - long_min_europa) + long_min_europa;
	       //  printf("Latitudine: %f, Longitudine: %f\n",latitudine, longitudine);
	     }
	    if(continente == 6){ 
	        latitudine = ((double)rand() / RAND_MAX) * (lat_max_asia - lat_min_asia) + lat_min_asia;
	        longitudine = ((double)rand() / RAND_MAX) * (long_max_asia - long_min_asia) + long_min_asia;
	       // printf("Latitudine: %f, Longitudine: %f\n",latitudine, longitudine);
	     }
	     
	    printf("Le coordinate sono:\nLatitudine: %f, Longitudine: %f\n",latitudine, longitudine);
	    sleep(10);
		/*
	    printf("\033[A"); 			// Torna su di una riga
	    printf("\033[2K");  		// Cancella la riga
	    */
	    system("@cls||clear"); 		// Pulizia del terminale

	    printf("LIVELLO %d \t PUNTEGGIO: %d ",livello, punteggio);
	    printf ("\nScegliere il continente digitando un numero da 1 a 6 come in legenda: \n 1) America\n 2) Africa\n 3) Oceania\n 4) Antartide\n 5) Europa\n 6) Asia\n\nLa tua risposta: ");
	    scanf("%d",&scelta);
	    
	
	    if (scelta == continente) {
	        printf("HAI INDOVINATO !!!\n");
	        punteggio = calcolo * i++;
	        printf("il tuo punteggio e' di: %d\n\n\n",punteggio);
	        livello++;
	        system("pause");
	        system("@cls||clear"); 		// Pulizia del terminale
	        printf("LIVELLO %d \t PUNTEGGIO: %d\n",livello, punteggio);
	        goto inizio;
	
	    } else {
	        printf("\nHAI SBAGLIATO\n");
			printf ("(Risposta giusta: %d)\n", continente); 
	        printf("Vuoi rigiocare?\n\n");
	        back:
	        printf("Digita 1 se vuoi rigiocare,\nDigita 2 se non vuoi rigiocare\nRisposta: ");
	        scanf("%d",&risposta);
	        if(risposta == 1){
	            livello = 0;
				i=1;
	            punteggio = 0;
	            system("@cls||clear"); 		// Pulizia del terminale
	            printf("Reset gioco:\n");
	            goto inizio;
	                 
	        } else if(risposta == 2){
	            system("pause"); 			// Attesa della pressione di un tasto da parte dell'utente per continuare
				return 0;
	            
	        } else {
				printf ("Errore, il numero che hai inserito (%d) deve essere compreso tra 1 e 2\n\nSi prega di riprovare\n\n", risposta);
				system("pause"); 			// Attesa della pressione di un tasto da parte dell'utente per continuare
				system("@cls||clear"); 		// Pulizia del terminale
				goto back;					// Vai all'etichetta "back"
			}
	    }
}
