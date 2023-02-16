/*
Code created by STANO VITTORIO MARIA - UniVR Dept. of Computer Science
 
Scrivere un programma in C che chieda all'utente di inserire cinque valori interi non negativi e ne disegna l'istogramma a barre verticali.

Es:
Se l'utente inserisce i valori: 1 4 5 2 1, il programma visualizzerà il seguente output:
    *
  * *
  * *
  * * *
* * * * *
1 4 5 2 1

Qualora i valori inseriti fossero errati dovrà essere visualizzato un messaggio di errore, al quale, seguirà la terminazione del programma.
*/

#include <stdio.h>

#define N 5             // Numero massimo valori

int main(void) {
    
    // Dichiarazione variabili
    int array[N];       // Array per valori iniziali
    int max = 0;        // Memorizza il valore massimo inserito
    _Bool check = 1;    // Controllo valore corretto

    printf("\n** Avvio del programma **\n");    // Messaggio di avvio

    // Richiesta inserimento N valori
    for (int i = 0; i < N; i++) {

        printf("Inserisci valore %i: ", i + 1);
        scanf("%i", &array[i]);

        // Trovo il massimo dei valori inseriti
        if (array[i] > max) {
            max = array[i];
        }
    }

    // Verifico che non siano stati inseriti numeri negativi
    for(int i = 0; i < N; i++) {
        if(array[i] < 0) {
            check = 0;
        }
    }

    printf("\n\n** Fase di elaborazione **\n\n");   // Stampa finale

    // Se sono stati inseriti valori non valiti --> ERRORE!
    if (check == 0) {
        printf("Sono stati inseriti valori non validi!\n\n");

    } else { // Altrimenti

        // Stampo istogramma a partire dal valore max
        for (int i = max; i > 0; i--) {

            // Scorro tutto l'array
            for (int j = 0; j < N; j++) {

                // Stampo "*" se il valore inserito dall'utente è >= della riga in cui mi trovo
                // Stampo " " in tutti gli altri casi
                if (array[j] >= i) {
                    printf(" * ");
                } else {
                    printf("   ");
                }
            }
            printf("\n");
        }

        // Stampo i valori iniziali inseriti
        // Stampa ottimizzata per 2 cifre decimali
        for (int i = 0; i < N; i++) {
            printf("%2i ", array[i]);
        }
        printf("\n\n");
    }
    return 0;
}