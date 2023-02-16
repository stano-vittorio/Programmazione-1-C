/*
Code created by STANO VITTORIO MARIA - UniVR Dept. of Computer Science

Scrivere un programma in C per calcolare la somma di due numeri binari.

I due valori dovranno essere inseriti dall'utente. Il programma dovrà, innanzitutto, controllare se i due numeri inseriti siano effettivamente espressi in notazione binaria. Qualora i valori inseriti fossero errati dovrà essere visualizzato un messaggio di errore, al quale, seguirà la terminazione del programma.

Es: v1 = 100101; v2 = 111;
      v1 = 110110; v2 = 1310; -> ERRORE!

Si dovrà, quindi, effettuare la somma dei due valori inseriti e stampare il risultato. La somma deve essere svolta bit a bit, dunque, non è ammessa la conversione del numero binario oppure l'utilizzo di array.

Es:
            111 <- carry bit (riporto)
          ---------
          100101 +
             111 =
          ---------
          101100

 */

#include <stdio.h>

int main(void) {

    // Dichiarazione variabili
    unsigned long long int bin1, bin2, bin_cpy1, bin_cpy2;    // Memorizzazione binary
    unsigned long long int bit_sum, bit1, bit2;               // Memorizzazione bit
    unsigned long long int carry_bit = 0;                     // Variabile riporto
    unsigned long long int res = 0;                           // Risultato binario
    unsigned long long int pot10 = 1;                         // Posizione potenza di 10
    int counter1 = 0, counter2 = 0, max_bit;                  // Variabili contatore
    _Bool error = 0;                                          // Bool di controllo

    printf("\n** Avvio del programma **\n");    // Messaggio di avvio

    // Massima allocazione 19 bit
    printf("Inserire il 1° numero binario: ");  // Richiesta primo valore
    scanf("%lli", &bin1);                       // Salvataggio primo valore

    // Controllo se il primo valore è un numero binario
    bin_cpy1 = bin1;
    while(bin_cpy1) {
        if(bin_cpy1 % 10 != 1 && bin_cpy1 % 10 != 0) {
            error = 1;
        }
        bin_cpy1 /= 10;
        counter1++;         // Incremento counter per verificare il numero di bit
    }

    // Massima allocazione 19 bit
    printf("Inserire il 2° numero binario: ");  // Richiesta secondo valore
    scanf("%lli", &bin2);                       // Salvataggio secondo valore

    // Controllo se il secondo valore è un numero binario
    bin_cpy2 = bin2;
    while(bin_cpy2) {
        if(bin_cpy2 % 10 != 1 && bin_cpy2 % 10 != 0) {
            error = 1;
        }
        bin_cpy2 /= 10;
        counter2++;         // Incremento counter per verificare il numero di bit
    }

    // Salvo in max_bit il numero massimo di bit inseriti
    if(counter1 > counter2) {
        max_bit = counter1;
    } else {
        max_bit = counter2;
    }

    if(error == 0) {        // Se i valori sono corretti procedo alla somma

        bin_cpy1 = bin1;    // Copia valori binari
        bin_cpy2 = bin2;    // Copia valori binari

        // Per ogni bit eseguo la somma e calcolo l'eventuale riporto
        for(int i = 0; i < max_bit + 1; i++) {
            bit1 = bin_cpy1 % 10;                   // Salvo bit1
            bit2 = bin_cpy2 % 10;                   // Salvo bit2

            bit_sum = bit1 + bit2 + carry_bit;      // Eseguo somma bit a bit

            // Verifico tutti i risultati possibili
            switch (bit_sum) {
                case 1:                 // CASO 1 | bit di somma = 1
                    res += pot10;       // Risultato = 1
                    carry_bit = 0;      // Riporto successivo = 0
                    break;
                case 2:                 // CASO 2 | bit di somma = 2
                    carry_bit = 1;      // Riporto successivo = 1
                    break;
                case 3:                 // CASO 3 | bit di somma = 3 (1 [cb] + 1 + 1)
                    res += pot10;       // Risultato = 1
                    carry_bit = 1;      // Riporto successivo = 1
                    break;
                default:
                    break;
            }

            bin_cpy1 /= 10;     // Scorro al bit successivo
            bin_cpy2 /= 10;     // Scorro al bit successivo
            pot10 *= 10;        // Incremento valore di potenza
        }

        printf("\n** Fase di elaborazione **\n");   // Stampa finale

        printf("Il risultato dell'operazione binaria %llu + %llu è: %llu\n\n", bin1, bin2, res); // Stampa finale

    } else {
        printf("\nErrore di inserimento! Riavviare il programma\n\n");  // Se false messaggio di errore
    }

    return 0;
}