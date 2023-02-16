/*
Code created by STANO VITTORIO MARIA - UniVR Dept. of Computer Science

Scrivere un programma C per calcolare la media, il massimo ed il minimo di una sequenza di voti inseriti dall'utente.

I valori ammessi devono essere maggiori o uguali a 18 e minori o uguali a 30. L'inserimento dei voti prosegue fino a quando l'utente non inserisce un numero non valido (cioè minore di 18 o maggiore di 30).

Subito dopo l'immissione del valore di fine inserimento vengono visualizzati media, massimo, minimo ed il numero di voti inseriti. Qualora il primo valore inserito fosse di fine inserimento dovrà essere visualizzato un messaggio di errore, al quale, seguirà la terminazione del programma.

 */

#include <stdio.h>

int main(void) {

    // Dichiarazione variabili
    float val;          // Inserimento valore
    float max = 0;      // Inizializzo val. max
    float min;          // Valore minimo
    double media;       // Media aritmetica
    int counter = 0;    // Inizializzo contatore
    float somma = 0;    // Inizializzo somma

    printf("\n** Avvio del programma **\n");    // Messaggio di avvio

    printf("Inserire valore >= 18 e <= 30: ");  // Richiesta primo valore
    scanf("%f", &val);                          // Salvataggio primo valore

    if(val >= 18 && val <= 30) {    // Verifica condizione primo valore

        min = val;                  // Assegnamento valore minimo
            
        do{                         // Inizio ciclo
            if(val > max) {         // Verifica valore massimo
                max = val;
            }

            if(val < min) {         // Verifica valore minimo
                min = val;
            }

            counter++;              // Incremento counter
            somma += val;           // Somma valore per valore

            media = (double)somma / counter;    // Eseguo media aritmetica

            printf("Inserire valore >= 18 e <= 30: ");  // Richiesta valori successivi
            scanf("%f", &val);                          // Salvataggio valori

        } while(val >= 18 && val <= 30);                // Condizione di ciclo

        printf("\n** Fase di elaborazione **\n");       // Stampa finale

        printf("- Media valori: %g\n", media);            // Stampa media
        printf("- Massimo valore: %g\n", max);            // Stampa valore massimo
        printf("- Minimo valore: %g\n", min);             // Stampa valore minimo
        printf("- Numero valori: %i\n\n", counter);       // Stampa numero valori


    } else {
        printf("\nErrore di inserimento! Riavviare il programma\n\n");  // Se false messaggio di errore
    }

    return 0;
}