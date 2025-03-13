/*
Elaborato 2
Esercizio 1
Versione 2

Scrivere un programma C che mostri l’utilizzo di tutti gli operatori studiati. 
Il programma deve inoltre mostrare il comportamento scorretto che si ottiene utilizzando tipi non appropriati alla dimensione delle variabili,
quello che si ottiene usando più operatori con side effect all’interno della stessa istruzione,
quello che si ottiene quando le regole di conversione implicita sono applicate e quando si supera il range dei valori disponibili per un tipo di dato.

Il programma deve poi mostrare l’utilizzo di tutte le funzioni matematiche della libreria math.h.


Fucci, Lazzari, Prati, Salvetti

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
    int a = 7;
    int b = 11;
    int c = 3;
    int d = 22;
    int E = 4;
    int F = 12;
    int G = 8;
    int H = 15;
    int x = 512;
    int risultato;
    double angle = 1.57;
    double valore_seno;
    int primo = 1;
    int secondo = 0;


	// Utilizzo operatori aritmetici
	risultato = a + b;
    printf("Somma di %d + %d = %d\n", a, b, risultato);

    risultato = a - b;
    printf("Differenza di %d - %d = %d\n", a, b, risultato);

    risultato = a * b;
    printf("Prodotto di %d * %d = %d\n", a, b, risultato);

    risultato = a / b;
    printf("Divisione di %d / %d = %d\n", a, b, risultato);

    risultato = a % b;
    printf("Resto della divisione di %d %% %d = %d\n\n", a, b, risultato);


    // Operatore virgola decremento
    printf("c-- = %d, --d = %d\n", c--, --d);
    printf("c-- = %d, --d = %d\n", c--, --d);
    printf("c-- = %d, --d = %d\n", c--, --d);
    printf("c-- = %d, --d = %d\n\n", c--, --d);

	// Operatore virgola incremento
    printf("c++ = %d, ++d = %d\n", c++, ++d);
    printf("c++ = %d, ++d = %d\n", c++, ++d);
    printf("c++ = %d, ++d = %d\n", c++, ++d);
    printf("c++ = %d, ++d = %d\n\n", c++, ++d);


	// Operatori compatti
    E += 5;
    printf("E += 5: E = %d\n", E);

    F *= 5;
    printf("F *= 5: F = %d\n", F);

    G /= 4;
    printf("G /= 4: G = %d\n", G);

    H %= 2;
    printf("H %%= 2: H = %d\n\n", H);


	// Superamento range
	int overflow = 2147483647;
	overflow++;
	printf("Superamento range: %d\n\n", overflow);

    // Funzioni matematiche
    valore_seno = sin(angle);
    printf("Seno di %f = %f\n", angle, valore_seno);
    
    double radicale = sqrt(a); 
	printf("Radice quadrata di %d = %lf\n", a, radicale);

	double potenza = pow(b, 2); 
	printf("%d elevato alla seconda = %lf\n", b, potenza);
	
	double log_base_10 = log10(c); 
	printf("Logaritmo base 10 di %d = %lf\n", c, log_base_10);
	
	double log_naturale = log(d); 
	printf("Logaritmo naturale di %d = %lf\n", d, log_naturale);
	
	double esponenziale = exp(E); 
	printf("Esponenziale di %d = %lf\n", E, esponenziale);
	
	double arcseno = asin(0.5); 
	printf("Arcoseno di 0.5 = %lf\n\n", arcseno);
    
    
    // Conversione implicita
    double risultatoDouble = a / 2.0;
    printf("Conversione implicita: %d / 2.0 = %lf\n\n", a, risultatoDouble);
    
    // Operatori relazionali
	printf("Operatori relazionali:\n");
	printf("a < b: %d\n", a < b);
	printf("a > b: %d\n", a > b);
	printf("a == b: %d\n", a == b);
	printf("a != b: %d\n\n", a != b);
	
	// Operatori bitwise
	int bitwise1 = 60;
	int bitwise2 = 240;
	printf("Operatori bitwise:\n");
	printf("bitwise1 & bitwise2 = %d\n", bitwise1 & bitwise2);  	// AND bitwise
	printf("bitwise1 | bitwise2 = %d\n", bitwise1 | bitwise2);  	// OR bitwise
	printf("bitwise1 ^ bitwise2 = %d\n", bitwise1 ^ bitwise2);  	// XOR bitwise
	printf("~bitwise1 = %d\n\n", ~bitwise1);                   		// NOT bitwise
	
	// Operatori logici
	printf("Operatori logici:\n");
	printf("primo && secondo = %d\n", primo && secondo);  	// Operatore logico AND
	printf("primo || secondo = %d\n", primo || secondo);  	// Operatore logico OR
	printf("!primo = %d\n\n", !primo);                		// Operatore logico NOT

	// Esempio side effect
	printf("Esempio side effect:\n");
	printf("Risultato: %d\n\n", a-- + b);


	// Attende l'input dell'utente prima di chiudere il programma
    system("pause");
    return 0;
}

