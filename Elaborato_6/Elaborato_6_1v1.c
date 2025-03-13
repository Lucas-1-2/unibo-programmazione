/*
Elaborato 6
Esercizio 1
Versione 1

CONSEGNA:
Si vuole implementare un algoritmo di apprendimento automatico per rinforzo: il Q-learning.
L’obiettivo del Q-learning è quello di adattarsi iterativamente al problema da risolvere migliorando la scelta delle azioni da eseguire.
Il problema è caratterizzato da un agente, un insieme di stati S e un insieme di azioni A,
effettuando le quali l'agente si muove da uno stato ad un altro stato. Ogni stato fornisce all'agente una ricompensa.

L'obiettivo dell'agente è quello di massimizzare la ricompensa totale.

In particolare, immaginare di dover allenare un robot a percorrere nel minor tempo possibile un labirinto disseminato di bombe e sorgenti di energia,
data una posizione iniziale e una posizione finale che deve raggiungere. Il sistema di punteggio/premio è il seguente:

Il robot perde 1 punto a ogni passo (serve a favorire la scelta dei percorsi più brevi e a raggiunge l'obiettivo il più velocemente possibile)
Se il robot calpesta una mina, perde 100 punti e la partita finisce.
Se il robot raggiunge una sorgente di energia guadagna 1 punto.
Se il robot raggiunge l'obiettivo finale ottiene 100 punti.

L’ambiente di gioco deve essere modellato usando una tabella Q (Q-table) dove le colonne rappresentano le azioni (destra, sinistra, alto, basso)
e le righe rappresentano gli stati (iniziale, vuoto, energia, mina, finale).
Ogni valore della Q-table rappresenterà la massima ricompensa futura attesa che il robot otterrà se compirà quell'azione in quello stato.
Si tratta di un processo iterativo, poiché è necessario migliorare la tabella Q a ogni iterazione.
Inizialmente la Q-table sarà inizializzata con valori 0, sarà poi iterativamente migliorata usando l’algoritmo di Q-learning.


L’algoritmo deve procedere secondo i seguenti passi:

inizializzazione della Q-table
scelta di un’azione
esecuzione dell’azione
misurazione della ricompensa
aggiornamento della Q-table
Vedere i dettagli di come aggiornare i valori della Q-table e un esempio di gioco ad esempio dal seguente sito::

https://www.freecodecamp.org/news/an-introduction-to-q-learning-reinforcement-learning-14ac0b4493cc/


Fucci, Lazzari, Prati, Salvetti

*/

//N.B.: con l'energia grande(+100) nella posizione corrente, il programma impiegherÃ  qualche secondo per 
//trovare la soluzione del percorso quindi nel terminale bisogna attendere una volta rannato il programma



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32 // valido sia per 32 che 64 bit
	#define CLEAR system("cls");
#else
    #define CLEAR system("clear");
#endif

#define NR 6 //inizializzazione numero di righe
#define NC 5 //inizializzazione numero di colonne
#define NA 4
#define Q_LENGTH NR * NC

#define MAX_TRAINING_STEP -1
#define MAX_TRAINING_EXPERIMENT 1000

#define LEARNING_RATE 0.1
#define DISCOUNT_RATE 0.99

int main(int argc, const char * argv[]) {
    int i, j, first;
    int countTrainingStep = 0, countTrainingExperiment = 0;
    float eps, maxReward;
    int mappa[NR][NC] = {           //mappa con i valori di ogni casella:
        {0, -1, -1, -1, -1},        //-1 = casella vuota
        {-1, -100, -1, -1, -1},     //-100 = mina
        {-1, -1, -1, -1, -100},     //1 = energia
        {-1, -1, -1, -1, +100,},    //+100 = energia grande
        {1, -1, -100, -1, -1},      //0 = posizione di partenza
        {-1, -1, -1, -1, -1},
    };;
    float q_table[Q_LENGTH][NA] = {
                         /* Up  Right Down Left */
    /* robot (start)  */    {0, 0,    0,   0},
    /* blank  */            {0, 0,    0,   0},
    /* blank  */            {0, 0,    0,   0},
    /* blank  */            {0, 0,    0,   0},
    /* energy */            {0, 0,    0,   0},
    /* blank  */            {0, 0,    0,   0},
    /* mine */              {0, 0,    0,   0},
    /* blank  */            {0, 0,    0,   0},
    /* blank  */            {0, 0,    0,   0},
    /* blank  */            {0, 0,    0,   0},
    /* blank  */            {0, 0,    0,   0},
    /* blank  */            {0, 0,    0,   0},
    /* blank  */            {0, 0,    0,   0},
    /* energy */            {0, 0,    0,   0},
    /* mine */              {0, 0,    0,   0},
    /* blank  */            {0, 0,    0,   0},
    /* blank  */            {0, 0,    0,   0},
    /* blank  */            {0, 0,    0,   0},
    /* blank  */            {0, 0,    0,   0},
    /* blank  */            {0, 0,    0,   0},
    /* energy */            {0, 0,    0,   0},
    /* blank  */            {0, 0,    0,   0},
    /* mine */              {0, 0,    0,   0},
    /* blank  */            {0, 0,    0,   0},
    /* blank  */            {0, 0,    0,   0},
    /* blank  */            {0, 0,    0,   0},
    /* blank  */            {0, 0,    0,   0},
    /* blank  */            {0, 0,    0,   0},
    /* blank  */            {0, 0,    0,   0},
    /* big energy */        {0, 0,    0,   0},
    };
    int moveDirection[NA][2] = {
        {-1, 0},    //up
        {0, 1},     //right
        {1, 0},    //down
        {0, -1},    //left
    };

    int start_r = 0, start_c = 0;   //robot start position
    int curr_r, curr_c, action, curr_state;
    int next_r, next_c;

    srand(time(NULL));

    CLEAR;

    eps = 100;
    curr_state = 0;
    curr_r = start_r;
    curr_c = start_c;
    while (countTrainingExperiment < MAX_TRAINING_EXPERIMENT) {
        countTrainingStep++;

        action = 0;
        //epsilon gredy
        int r = rand() % 100 + 1;
        if (r <= (100 - eps)) {     //il programma decide se utilizzare le direzioni consigliate dalla q-table o andare a random 
            first = 1;
            for (i = 0; i < NA; i++) {
                next_r = curr_r + moveDirection[i][0];
                next_c = curr_c + moveDirection[i][1];
                if (next_r >= 0 && next_r < NR && next_c >= 0 && next_c < NC) {
                    if (first || q_table[curr_state][i] > maxReward) {
                        maxReward = q_table[curr_state][i];
                        action = i;
                        first = 0;
                    }
                }
            }
        }
        else {
            int actionRandomCheck[] = {0, 0, 0, 0};
            int trovato = 0;
            while (!trovato) {
                do {
                    action = rand() % 4;
                }
                while (actionRandomCheck[action] == 1);
                actionRandomCheck[action] = 1;
                
                next_r = curr_r + moveDirection[action][0];
                next_c = curr_c + moveDirection[action][1];
                if (next_r >= 0 && next_r < NR && next_c >= 0 && next_c < NC) {
                    trovato = 1;
                }               
            }
        }
        
        curr_r += moveDirection[action][0];
        curr_c += moveDirection[action][1];
        int reward = mappa[curr_r][curr_c];
        int new_state = curr_r * NC + curr_c;
        int maxFutureReward = 0;
        first = 1;
        for (i = 0; i < NA; i++) {
            next_r = curr_r + moveDirection[i][0];
            next_c = curr_c + moveDirection[i][1];
            if (next_r >= 0 && next_r < NR && next_c >= 0 && next_c < NC) {
                if (first || q_table[new_state][i] > maxFutureReward) {
                    maxFutureReward = q_table[new_state][i];
                    first = 0;
                }
            }
        }

        q_table[curr_state][action] = q_table[curr_state][action] + LEARNING_RATE * (reward + DISCOUNT_RATE * maxFutureReward - q_table[curr_state][action]);

        if (curr_state == 4 || curr_state == 5 || (MAX_TRAINING_STEP > 0 && countTrainingStep > MAX_TRAINING_STEP)) {
            countTrainingStep = 0;
            curr_state = 0;
            curr_r = start_r;
            curr_c = start_c;
            countTrainingExperiment++;
            eps -= 100.0 / MAX_TRAINING_EXPERIMENT;
        }
        else {
            curr_state = new_state;
        }
    }

    printf("\n\n");
    for (i = 0; i < Q_LENGTH; i++) {
        for (j = 0; j < NA; j++) {
            printf("%3.2f ", q_table[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");


    int move = 1, count = 1;
    int mappaSpostamento[NR][NC];
    for (i = 0; i < NR; i++) {
        for (j = 0; j < NC; j++) {
            mappaSpostamento[i][j] = 0;
        }
    }

    curr_state = 0;
    curr_r = start_r;
    curr_c = start_c;
    mappaSpostamento[curr_r][curr_c] = count;
    while (move) {
        action = 0;
        first = 1;
        for (i = 0; i < NA; i++) {
            next_r = curr_r + moveDirection[i][0];
            next_c = curr_c + moveDirection[i][1];
            if (next_r >= 0 && next_r < NR && next_c >= 0 && next_c < NC) {
                if (first || q_table[curr_state][i] > maxReward) {
                    maxReward = q_table[curr_state][i];
                    action = i;
                    first = 0;
                }
            }
        }    

        curr_r += moveDirection[action][0];
        curr_c += moveDirection[action][1];
        count++;
        curr_state = curr_r * NC + curr_c;
        mappaSpostamento[curr_r][curr_c] = count;
        switch (mappa[curr_r][curr_c]) {
        case 100: //find big energy
            printf("trovata energia grande, robot felice!");
            move = 0;
            break;
        case -100: //find mine
            printf("trovata mina, robot fatto zac!");
            move = 0;
            break;
        }
    }

    printf("\n\n");
printf("+----+----+----+----+----+\n");
    for (i = 0; i < NR; i++) {
        for (j = 0; j < NC; j++) {
            printf("| %3d", mappaSpostamento[i][j]);
        }
        printf("|\n");
        printf("+----+----+----+----+----+\n");
    }
    printf("\n\n");

    return 0;
}
