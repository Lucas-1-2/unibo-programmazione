/*
Elaborato 5
Esercizio 1
Versione 1

Scrivere un programma che simuli l’“effetto decriptazione dati” presentato nel 1992 nel film Sneakers. 
L’effetto è presente a partire dal minuto 0.35 nella seguente clip del film:

https://www.youtube.com/watch?v=F5bAa6gFvLs&t=35s

Il vostro programma dovrà occuparsi di chiedere all’utente una stringa e di visualizzare in tempi successivi
versioni via via più simili alla stringa iniziale.



Fucci, Lazzari, Prati, Salvetti




SPIEGAZIONE:

 Questo programma propone la soluzione creando Num_string_cas vettori di caratteri (in una matrice: stringa_cas)
 che alternerà sullo schermo ad intervalli di tempo regolari (gestiti da t_stinga).
 
 Il programma provvede inoltre a sostituire in maniera casuale ad intervalli di tempo regolari (gestiti da t_carattere)
 un carattere corretto dalla stringa inserita dall'utente, nelle stringhe generate casualmente.
 
 Il programma si conclude quando il controllo della prima stringa casuale (che è uguale alle altre casuali) 
 è uguale carattere per carattere al vettore inserito dall'utente, in tal caso imposta a 1 una variabile 'fine' 
 che in seguito permetterà la conclusione del programma.
 
*/


#include <stdio.h>
#include <time.h>
#include <string.h>



int main() {
	
	const int max_caratteri = 500;			// Caratteri massimi della stringa inserimento
	const int t_carattere = 100;			// Tempo in millisecondi prima di effettuare un cambio di carattere dalla stringa inserita alle stringhe pseudo-casuali
	const int t_stringa = 10;				// Tempo in millisecondi prima di effettuare un cambio della stringa visualizzata
	const int Num_string_cas = 10;			// Numero di stringhe casuali generate dal programma
	
	
	// Dichiarazione variabili vettori di caratteri per l'inserimento dell'utente e per la generazione delle stringhe casuali
	char valori[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '!', '"', '£', '$', '%', '&', '/', '(', ')', '=', '?', '^', '|', '@', 'ç', '°', '#', '§', '+', '-', '_', '[', ']', '{', '}', '<', '>' };
	char inserimento[max_caratteri];
	
	// Variabili perla gestione dei cicli
	int s = 0, i, t, fine = 0, pos = 0;
	
	// Richiesta di inserimento stringa
	printf("Inserire un testo (massimo %d caratteri): \n", max_caratteri);
	fgets(inserimento, max_caratteri, stdin);
	
	// Ottengo la lunghezza del vettore di caratteri inserito
	int num_val = strlen(valori);
	int lunghezza = strlen(inserimento);
	// printf("\n\n%d\n\n", lunghezza);
	
	// Dichiaro matrici i vettori di caratteri da generare casualmente, e le relative variabili per la gestione dell'estrazione del carattere da sostituire
	char stringa_cas [Num_string_cas] [lunghezza];
	int estrazione, estrazioni[lunghezza];
	
	// Inizializzazione vettore estrazioni
	for(i=0; i<lunghezza; i++){
		estrazioni[i] = lunghezza+2;
		//printf("%c", inserimento[i]);
	}
	//printf("\n");
	
	// Inizializzo la generazione pseudo-casuale
	srand(time(NULL));
	
	// Genero Num_string_cas vettori di caratteri di lunghezza uguale a quella inserita dall'utente, con solo numeri e simboli a caso dal vettore 'valori'.
	for(i=0; i<Num_string_cas; i++){
		for(t=0; t<lunghezza; t++){
			stringa_cas [i] [t] = valori[(rand() % num_val)];
			// printf("%c",stringa_cas [i] [t]);
		}
		// printf("\n");
		// system("pause");
	}
	
	
	// Ottengo l'ora corrente per poter in seguito controllare se è passato abbastanza tempo per eseguire determinate operazioni
	unsigned long int tempo1 = clock();
	unsigned long int tempo2 = clock();
	
	
	// Inizio un loop
	while(1){
		
		// Se il tempo è passato, associa un carattere giusto dal vettore inserito dall'utente, ai vettori generati casualmente
		if((clock() - tempo1) >= t_carattere){
			estr:
			estrazione = rand() % lunghezza;
			for(t=0; t<lunghezza; t++){
				if (estrazione == estrazioni[t]){
					goto estr;			// Va all'etichetta 'estr'
				}	
			}
			pos++;
			estrazioni[pos] = estrazione;
			
			
			// Associo un carattere giusto a tutti i vettori casuali
			for(i=0; i<Num_string_cas; i++){				
				stringa_cas [i] [estrazione] = inserimento[estrazione];
			}
			tempo1 = clock();
		}
			
		// Se il tempo è passato, cancella lo schermo e scrive una stringa successiva di quelle generate casualmente
		if((clock() - tempo2) >= t_stringa){
			// Cancella lo schermo e scrive una delle stringhe pseudo casuali generate all'inizio, in maniera sequenziale.
			system("cls");
			
			// Scrivo una stringa di quelle casuali, in sequenza
			for(i=0; i<lunghezza; i++){
				printf("%c", stringa_cas [s] [i]);
			}
			s++;
			if(s == Num_string_cas) s = 0;		// Ritorno al primo vettore una volta raggiunto l'ultimo
			tempo2 = clock();
			// Controllo se la prima stringa casuale (che è uguale alle altre casuali) è uguale carattere per carattere al vettore inserito dall'utente, in tal caso imposta a 1 una variabile 'fine' che in seguito permetterà la conclusione del programma
			for(i=0; i<lunghezza; i++){
				if (stringa_cas[0][i] == inserimento[i]){
					fine = 1;
				} else {
					fine = 0;
					break;
				}
			}
		}
		
		if (fine) break;			// Esco dal loop portando alla conseguente conclusione del programma
	}
		
	printf("\n\n\n\nSimulazione di decriptazione completata\n");

	// Attendo un input dall'utente per terminare il programma
	system("pause");
	return 0;
}
