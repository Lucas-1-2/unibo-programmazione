/*
Elaborato 7
Esercizio 1
Versione 1				

ATTENZIONE: � previsto un debug all'interno di varie parti del codice,
			per abilitarlo/disabilitarlo occorre cercare la stringa "abilitare il DEBUG"
			e commentare o meno le relative righe di codice.


CONSEGNA:
L'algoritmo k-nearest neighbors (KNN) � un algoritmo di apprendimento automatico supervisionato utilizzato per risolvere sia problemi
di classificazione che di regressione. L'algoritmo KNN presuppone che oggetti con caratteristiche simili si trovino nelle immediate vicinanze,
cio� poco distanti fra loro nello spazio dove sono rappresentate le caratteristiche degli oggetti.

L'algoritmo KNN chiede di valutare la somiglianza degli elementi pi� vicini e, a maggioranza, classifica l�elemento.
La somiglianza viene definita in base a una metrica di distanza tra due punti di dati.
Una scelta popolare � la distanza euclidea, ma � possibile valutare altre misure in base al proprio dataset,
ad esempio, Manhattan, Chebyshev, Hamming, etc.

Per trovare la classe di appartenenza di un dato in ingresso, si esegue un loop su ogni esempio di training.
Per ogni esempio viene calcolata la distanza tra esempio e ingresso usando la metrica desiderata.
Infine, si prendono i k esempi con distanza minore e si contano le classificazioni di questi esempi.
Vince la classificazione con maggior numero di esempi tra i k trovati.

Si veda ad esempio https://www.geeksforgeeks.org/k-nearest-neighbours/

per una descrizione pi� dettagliata dell�algoritmo.
Algoritmo:

1.Scegliere il valore di K, cio� il numero di vicini pi� prossimi che verr� utilizzato per fare la previsione
2.Calcolare la distanza tra quel punto e tutti i punti dell'insieme di training
3.Selezionare i K vicini pi� prossimi in base alle distanze calcolate
4.Assegnare l'etichetta della classe maggioritaria al nuovo punto
5.Ripetere i passaggi da 2 a 4 per tutti i punti dati dell'insieme di test
6.Valutare l'accuratezza dell'algoritmo (usando il 25% dei dati del dataset dato).

Usare l'algoritmo KNN per prevedere se un prestito bancario verr� rimborsato in base ai dati del cliente,
usando il 75% dei dati relativi ai prestiti presenti in un dataset composto di 10.000 dati di prestiti
con informazioni sulla struttura del prestito, sul mutuatario e sul fatto che il prestito sia stato rimborsato per intero.
I dati sono stati estratti da LendingClub.com, una societ� che mette in contatto i mutuatari con gli investitori.

Le informazioni presenti nel dataset sono:

0 credit_policy			1 se il cliente soddisfa i criteri di sottoscrizione del credito; 0 altrimenti.
1 purpose				Lo scopo del prestito.
2 int_rate				Il tasso di interesse del prestito (ai mutuatari pi� rischiosi vengono assegnati tassi di interesse pi� elevati).
3 installment			Le rate mensili dovute dal mutuatario se il prestito viene finanziato.
4 log_annual_inc		Il log naturale del reddito annuo autodichiarato del mutuatario.
5 dti					Il rapporto debito/reddito del mutuatario (importo del debito diviso per il reddito annuale).
6 fico					Il punteggio di credito FICO del mutuatario.
7 days_with_cr_line		Il numero di giorni in cui il debitore ha avuto una linea di credito.
8 revol_bal				Il saldo revolving del debitore (importo non pagato alla fine del ciclo di fatturazione della carta di credito).
9 revol_util			Il tasso di utilizzo della linea revolving del debitore (l'importo della linea di credito utilizzata rispetto al credito totale disponibile).
10 inq_last_6mths		Il numero di richieste di informazioni da parte dei creditori negli ultimi 6 mesi.
11 delinq_2yrs			Il numero di volte in cui il debitore � stato in ritardo di oltre 30 giorni con i pagamenti negli ultimi 2 anni.
12 pub_rec				Il numero di registri pubblici in deroga del mutuatario.
13 not_fully_paid		1 se il prestito non � stato completamente pagato; 0 altrimenti.

Il dataset � presente nel file credit a disposizione su virtuale.
I dati di ogni prestito devono essere gestiti tramite un'apposita struttura dati.



Fucci, Lazzari, Prati, Salvetti

*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#define MAX_RIGA 156
#define MAX_RIGHE_FILE 10000
#define RIGHE_TRAINING 7500
#define VAL_RST_DIST 1000000000.000



//struttura dati per rappresentare un prestito
struct Prestito {
	int credit_policy;				// 1 se il cliente soddisfa i criteri di sottoscrizione del credito; 0 altrimenti
	char purpose [30];				// Lo scopo del prestito
	double int_rate;				// Il tasso di interesse del prestito (ai mutuatari pi� rischiosi vengono assegnati tassi di interesse pi� elevati)
	double installment;				// Le rate mensili dovute dal mutuatario se il prestito viene finanziato
	double log_annual_inc;			// Il log naturale del reddito annuo autodichiarato del mutuatario
	double dti;						// Il rapporto debito/reddito del mutuatario (importo del debito diviso per il reddito annuale)
	double fico;					// Il punteggio di credito FICO del mutuatario
	double days_with_cr_line;		// Il numero di giorni in cui il debitore ha avuto una linea di credito
	double revol_bal;				// Il saldo revolving del debitore (importo non pagato alla fine del ciclo di fatturazione della carta di credito)
	double revol_util;				// Il tasso di utilizzo della linea revolving del debitore (l'importo della linea di credito utilizzata rispetto al credito totale disponibile)
	double inq_last_6mths;			// Il numero di richieste di informazioni da parte dei creditori negli ultimi 6 mesi
	double delinq_2yrs;				// Il numero di volte in cui il debitore � stato in ritardo di oltre 30 giorni con i pagamenti negli ultimi 2 anni
	double pub_rec;					// Il numero di registri pubblici in deroga del mutuatario
	int not_fully_paid;				// 1 se il prestito non � stato completamente pagato; 0 altrimenti
};
struct Prestito training [RIGHE_TRAINING];
struct Prestito esaminato [MAX_RIGHE_FILE-RIGHE_TRAINING];










/*
Lettura del file fino alla fine: 
Le righe considerate come RIGHE_TRAINING (define 7500) vengono assegnate alla struct Prestito training
Le successive vengono assegnate alla struct Prestito esaminato
*/
void Lettura_File (char str[], FILE *file1){
	// primi 2 argomenti per fgets() [usare anche la variabile MAX_RIGA dichiarata define]
	int t;
	for(t=0; !feof(file1); t++){
		fgets(str, MAX_RIGA, file1);
		// printf("\n%s",str);			// Togliere il commento iniziale per abilitare il DEBUG
		if(t<RIGHE_TRAINING){
			//result serve per un eventuale debug, assume il valore dei valori associati correttamente da sscanf (se vale meno del numero degli argomenti di sscanf � un problema)
			int result = sscanf(str, "%d, %[^,], %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %d",
								&training[t].credit_policy,
								training[t].purpose,
								&training[t].int_rate,
								&training[t].installment,
								&training[t].log_annual_inc,
								&training[t].dti,
								&training[t].fico,
								&training[t].days_with_cr_line,
								&training[t].revol_bal,
								&training[t].revol_util,
								&training[t].inq_last_6mths,
								&training[t].delinq_2yrs,
								&training[t].pub_rec,
								&training[t].not_fully_paid );
				
			/*	//(aggiungere // a inizio riga per abilitare il DEGUB)
			
			//eventuale debug 				
			printf("\n Result: %d\n", result);
			printf("\nLettura file t (training) = %d \t %d, %s, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %d",
						t, 
						training[t].credit_policy,
						training[t].purpose,
						training[t].int_rate,
						training[t].installment,
						training[t].log_annual_inc,
						training[t].dti,
						training[t].fico,
						training[t].days_with_cr_line,
						training[t].revol_bal,
						training[t].revol_util,
						training[t].inq_last_6mths,
						training[t].delinq_2yrs,
						training[t].pub_rec,
						training[t].not_fully_paid );
			system("pause");
			*/	//(aggiungere // a inizio riga per abilitare il DEGUB)
						
		} else {
			//result serve per un eventuale debug, assume il valore dei valori associati correttamente da sscanf (se vale meno del numero degli argomenti di sscanf � un problema)
			int result = sscanf(str, "%d, %[^,], %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %d",
								&esaminato[t-RIGHE_TRAINING].credit_policy,
								esaminato[t-RIGHE_TRAINING].purpose,
								&esaminato[t-RIGHE_TRAINING].int_rate,
								&esaminato[t-RIGHE_TRAINING].installment,
								&esaminato[t-RIGHE_TRAINING].log_annual_inc,
								&esaminato[t-RIGHE_TRAINING].dti,
								&esaminato[t-RIGHE_TRAINING].fico,
								&esaminato[t-RIGHE_TRAINING].days_with_cr_line,
								&esaminato[t-RIGHE_TRAINING].revol_util,
								&esaminato[t-RIGHE_TRAINING].revol_bal,
								&esaminato[t-RIGHE_TRAINING].inq_last_6mths,
								&esaminato[t-RIGHE_TRAINING].delinq_2yrs,
								&esaminato[t-RIGHE_TRAINING].pub_rec,
								&esaminato[t-RIGHE_TRAINING].not_fully_paid );
			
			/* (aggiungere // a inizio riga per abilitare il DEGUB)
			
			//eventuale debug 				
			printf("\n Result: %d\n", result);			
			printf("\n Lettura file t (esaminato) = %d \t %d, %s, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %d",
						t, 
						esaminato[t-RIGHE_TRAINING].credit_policy,
						esaminato[t-RIGHE_TRAINING].purpose,
						esaminato[t-RIGHE_TRAINING].int_rate,
						esaminato[t-RIGHE_TRAINING].installment,
						esaminato[t-RIGHE_TRAINING].log_annual_inc,
						esaminato[t-RIGHE_TRAINING].dti,
						esaminato[t-RIGHE_TRAINING].fico,
						esaminato[t-RIGHE_TRAINING].days_with_cr_line,
						esaminato[t-RIGHE_TRAINING].revol_util,
						esaminato[t-RIGHE_TRAINING].revol_bal,
						esaminato[t-RIGHE_TRAINING].inq_last_6mths,
						esaminato[t-RIGHE_TRAINING].delinq_2yrs,
						esaminato[t-RIGHE_TRAINING].pub_rec,
						esaminato[t-RIGHE_TRAINING].not_fully_paid);
						
			*/ 	//(aggiungere // a inizio riga per abilitare il DEGUB)
		}
		// system("pause");		// Togliere il commento iniziale per abilitare il DEBUG
	}
	fclose(file1);
	return;	
}










// Aggiornamento del vettore 'distanze' ordinando in ordine crescente le distanze euclidee precedentemente calcolate, dalla distanza minore a quella maggiore
// Aggiornamento del vettore 'esiti_distanze' (nello stesso modo del vettore 'distanze') con i corrispettivi esiti di pagamento del prestito degli elementi del vettore 'distanze'
void Aggiornamento_Distanze_K (double val_dist, double distanze_K[], float esiti_distanze_K[], int k, int riga_esaminata, int riga_training){
	int i, j, cambio;
	double appoggio1, appoggio2;
	float appoggio3, appoggio4;
	
	// Passa i K elementi dei vettori
	for(i=0; i<k; i++){
		/*
		 Se il valore trovato con la distanza euclidea � minore di uno di quelli gi� presenti nell'array 'distanze_K',
		 si entra nel ciclo if che tramite 2 variabili di appoggio si occupa di aggiornare l'array traslando i suoi valori verso la fine dell'array ("destra")
		*/
		/*
		 Tramite il medesimo ragionamento all'interno del ciclo if, tramite altre 2 variabili di appoggio, si aggiorna l'array 'esiti_distanze_K'.
		 Questo array conterr� i risultati di pagamento del corrispondente elemento dell'array 'distanze_K'.
		 L'aggiornamento di questo vettore (per traslazione) � identico a quello utilizzato per l'array 'distanze_K'.
		*/
		if(val_dist <= distanze_K [i]){
			appoggio1 = distanze_K [i];
			distanze_K [i] = val_dist;
			
			appoggio3 = esiti_distanze_K [i];
			esiti_distanze_K [i] = training[riga_training].not_fully_paid;
			
			cambio = 1;
			for(j=i+1; j<k; j++){
				if(cambio){
					appoggio2 = distanze_K [j];
					distanze_K [j] = appoggio1;
					
					appoggio4 = esiti_distanze_K [j];
					esiti_distanze_K [j] = appoggio3;
				
				} else {
					appoggio1 = distanze_K [j];
					distanze_K [j] = appoggio2;
					
					appoggio3 = esiti_distanze_K [j];
					esiti_distanze_K [j] = appoggio4;
				}
				cambio = 1-cambio;
			}
			// printf("\n 'val_dist' (%d): %f", riga_esaminata, val_dist);			// Togliere il commento iniziale per abilitare il DEBUG
			break;
		}
	}
	return;
}










// Distanza euclidea tra due prestiti
float distanzaEuclidea(struct Prestito prestito1, struct Prestito prestito2){
	// Calcola prima le differenza quadratiche per ogni tipo di dato e poi facendo la radice quadrata della somma delle differenze quadratiche
	// Formula della distanza euclidea: {[somma delle differenze] al quadrato} tutto sotto radice

    //calcolo delle differenze quadratiche
    int diff_credit_policy = prestito1.credit_policy - prestito2.credit_policy;
    double diff_int_rate = prestito1.int_rate - prestito2.int_rate;
    double diff_installment = prestito1.installment - prestito2.installment;
    double diff_log_annual_inc = prestito1.log_annual_inc - prestito2.log_annual_inc;
    double diff_dti = prestito1.dti - prestito2.dti;
    double diff_fico = prestito1.fico - prestito2.fico;
    double diff_days_with_cr_line = prestito1.days_with_cr_line - prestito2.days_with_cr_line;
    double diff_revol_bal = prestito1.revol_bal - prestito2.revol_bal;
    double diff_revol_util = prestito1.revol_util - prestito2.revol_util;
    double diff_inq_last_6mths = prestito1.inq_last_6mths - prestito2.inq_last_6mths;
    double diff_delinq_2yrs = prestito1.delinq_2yrs - prestito2.delinq_2yrs;
    double diff_pub_rec = prestito1.pub_rec - prestito2.pub_rec;

    //somma delle differenze euclidee
    double somma_diff = ((diff_credit_policy^2)+
						(diff_int_rate*diff_int_rate)+
						(diff_installment*diff_installment)+
						(diff_log_annual_inc*diff_log_annual_inc)+
						(diff_dti*diff_dti)+
						(diff_fico*diff_fico)+
						(diff_days_with_cr_line*diff_days_with_cr_line)+
						(diff_revol_bal*diff_revol_bal)+
						(diff_revol_util*diff_revol_util)+
						(diff_inq_last_6mths*diff_inq_last_6mths)+
						(diff_delinq_2yrs*diff_delinq_2yrs)+
						(diff_pub_rec*diff_pub_rec));
						
    double distanza = sqrt(somma_diff);
    return distanza;
}










// Reset dei vettori 'distanze' e 'esiti_vettore', entrambi di K elementi
void Rst_distanze (const int K, double vettore[], float esiti_vettore[]){
	int t;
	
	// Inizializzo a VAL_RST_DIST tutte le celle dell'array 'vettore' e inizializzo anche tutte le celle dell'array 'esiti_vettore'
	for(t=0; t<K; t++){
		vettore[t] = VAL_RST_DIST;
		esiti_vettore [t] = 0.5; 		// Imposto a 0,5 cos� in caso di mancata assegnazione il valore non influisce ne su 1 ne su 0 la media calcolata in "Aggiornamento_Distanze_K" tra tutti gli elementi dell'array
	}
	return;
}










// Calcolo della probabilit� che la riga esaminata possa essere completamente pagata
float Probabilita_not_fully_paid (float esiti_distanze_K[], const int K, int riga_esaminata){
	float probabilita, media = 0.0;
	int i, indovinato;
	
	//printf("\n Esito distanza (%d): ", riga_esaminata);		// Togliere il commento iniziale per abilitare il DEBUG
	
	// Sommo tutti gli elementi di 'esiti_distanze_K'
	for(i=0; i<K; i++){
		media += esiti_distanze_K[i];
		//printf(" %3.2f ", esiti_distanze_K[i]);				// Togliere il commento iniziale per abilitare il DEBUG
	}
	
	/*	//(aggiungere // a inizio riga per abilitare il DEGUB)
	printf("\nMedia esiti distanze (riga %d): %f", riga_esaminata, media);
	system("pause");
	*/	//(aggiungere // a inizio riga per abilitare il DEGUB)
	
	// Calcolo la media %
	probabilita = media/K*100.00;
	//printf("\n Probabilita che non venga pagato (riga %d): %3.2f%%", riga_esaminata, probabilita);		// Togliere il commento iniziale per abilitare il DEBUG
	
	if (probabilita < 50.00) {
		//printf("\nSecondo l'algoritmo e' probabile che il prestito verra' ripagato.");				// Togliere il commento iniziale per abilitare il DEBUG
		indovinato = 0;
		
	} else if (probabilita > 50.00) {
		//printf("\nSecondo l'algoritmo e' probabile che il prestito NON verra' ripagato.");			// Togliere il commento iniziale per abilitare il DEBUG
		indovinato = 1;
		
	} else {	// Significa che probabilit� == 50.00
		//printf("\nAvendo scelto un numero K pari, non e' stato possibile stabilire con certezza se il prestito verra' ripagato o meno.");			// Togliere il commento iniziale per abilitare il DEBUG
		indovinato = 2;		// non � ne 0 ne 1, serve in seguito a far capire al programma che ha sbagliato a indovinare a prescindere.
	}
	
	
	// Stabilisco se � effettivamente vero ci� che il mio algoritmo ha previsto (sull'esito del pagamento)
	if(indovinato == esaminato[riga_esaminata].not_fully_paid){
		indovinato = 1.0;
		//printf("\nHO INDOVINATO! DAJE ROMA ;)");		// Togliere il commento iniziale per abilitare il DEBUG
		
	} else {
		indovinato = 0.0;
		//printf("\nNON ho indovinato :(");				// Togliere il commento iniziale per abilitare il DEBUG
	}
	
	//system("pause");									// Togliere il commento iniziale per abilitare il DEBUG
	
	return indovinato;
}










int main(){
	FILE *file;												// Puntatore a FILE
	char *filename;											
	char riga_file [MAX_RIGA];								// Dimensione prima riga del file csv
	char PERCORSO_FILE_CUSTOM[261];							// Dimensione massima di un percorso file Windows 260 caratteri, 261 per stare sicuri
	char PERCORSO_FILE_DEFAULT[] = "loan_dataWIN.csv";		// Percorso di default del file da aprire
	const int K;
	int i, t;
	double DIST_VAL;
	float accuratezza = 0.0, Indovinato;
	
	
	printf("Attenzione, il file di default prevede %d righe, e' possibile che il codice \nfunzioni in maniera errata se si opera con un diverso valore di righe totali del file \n\nInserire il percorso esteso del file che si vuole utilizare, \nin alternativa premere 'invio' per proseguire usando il file di default '%s':\n", MAX_RIGHE_FILE, PERCORSO_FILE_DEFAULT);
	gets(PERCORSO_FILE_CUSTOM); 		// Ottiene la stringa in input dal terminale
	
	// Se la stringa contiene qualcosa, viene associata al variabile filename, altrimenti viene associato il percorso del file previsto come default
	if(strlen(PERCORSO_FILE_CUSTOM) > 0){
		printf("Molto bene, procedo utilizzando come percorso file: '%s'\n\n", PERCORSO_FILE_CUSTOM);
		filename = PERCORSO_FILE_CUSTOM;
	
	} else {
		printf("Molto bene, procedo utilizzando il percorso file impostato come default: '%s'\n\n", PERCORSO_FILE_DEFAULT);
		filename = PERCORSO_FILE_DEFAULT;
	}
	
	
	// Apertura del file in modalit� lettura (r)
    file = fopen(filename , "r");
	if(file == NULL) {
		printf("Errore nell'apertura file\n");
		system("pause");
		exit(1);
	}
	printf("File aperto correttamente.\n\n");
	
	// Imposto il valore di K, definito come costante intera
	printf("Impostare K \n(il numero di vicini piu' prossimi che verra' utilizzato per fare la previsione, si consiglia un numero dispari) \nInserire K: ");
	scanf("%d", &K);
	double distanze [K];
	float esiti_distanze [K];
	
	
	// Intera lettura del file
	printf("File aperto correttamente.\n\n");
	Lettura_File(riga_file, file);
	
	printf("\nLettura file completata, proseguire per ottenere i risultati.\n\n");
	system("pause");
	printf("\nElaborazione dati...\n");		
	
	// Per ogni riga da esaminare, essa viene confrontata con tutte le righe destinate al training e viene aggiornato il vettore destinato a salvare le K distanze euclidee pi� vicine 
	for(i=0; i<(MAX_RIGHE_FILE-RIGHE_TRAINING); i++){
		// Reset del vettore 'distanze' di K elementi, con il valore VAL_RST_DIST
		Rst_distanze (K, distanze, esiti_distanze);
		for(t=0; t<(RIGHE_TRAINING); t++){
			DIST_VAL = distanzaEuclidea(esaminato[i], training[t]);
			//printf("\nDIST_VAL (%d - %d): %lf", i+1, t+1, DIST_VAL);		//(togliere // a inizio riga per abilitare il DEGUB)
			Aggiornamento_Distanze_K(DIST_VAL, distanze, esiti_distanze, K, i, t);
			
		}
		// system("pause");			//(togliere // a inizio riga per abilitare il DEGUB)
		
		/* //(aggiungere // a inizio riga per abilitare il DEGUB)
		printf("\nArray distanze K (riga %d):\t", RIGHE_TRAINING+i+1);
		for(t=0; t<K; t++){
			printf(" %13.3f ", distanze[t]);
		}
		*/ 	//(aggiungere // a inizio riga per abilitare il DEGUB)
		
		
		/*	//(aggiungere // a inizio riga per abilitare il DEGUB)
		printf("\nArray esiti distanze K (riga %d):\t", RIGHE_TRAINING+i+1);
		for(t=0; t<K; t++){
			printf(" %2.2f ", esiti_distanze[t]);
		}
		*/	//(aggiungere // a inizio riga per abilitare il DEGUB)
		
		
		
		// Calcolo la probabilit� del saldo del pagamento
		Indovinato = Probabilita_not_fully_paid(esiti_distanze, K, i);
		accuratezza += Indovinato;
		
		// Reset del vettore 'distanze' di K elementi, con il valore VAL_RST_DIST
		Rst_distanze (K, distanze, esiti_distanze);
	}
	
	// Output finale dell'accuratezza di questo algoritmo KNN 
	accuratezza = (accuratezza/(MAX_RIGHE_FILE-RIGHE_TRAINING)*100);
	printf("\nIl programma e' terminato ottenendo una %% di accuratezza nelle previsioni dell'%3.2f%%\n\n", accuratezza);
	system("pause");
	return (0);
}

