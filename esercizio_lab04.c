/*
Code created by STANO VITTORIO MARIA - UniVR Dept. of Computer Science

Scrivere un programma C che implementi i seguenti sottoprogrammi: 

Sottoprogramma 1: riceve come parametro una matrice quadrata NxN (con N definito staticamente, ma ipotizzando che potrebbe cambiare) di caratteri, di cui individuarne il carattere che compare con maggiore frequenza e lo restituisce (in caso di molteplici caratteri, si tenga il primo trovato); 

Sottoprogramma 2: riceve come parametri un carattere e una matrice quadrata NxN di caratteri, visualizzando su terminale la stessa matrice però con uno spazio al posto di tutti i caratteri uguali al carattere passato come parametro; 

In fine si scriva un programma main che, utilizzando i sottoprogrammi 1 e 2, individua il carattere che compare più frequentemente in una matrice NxN di caratteri, riempita dall'utente, per poi stamparla a schermo mostrando però uno spazio al posto dei caratteri uguali al carattere individuato. 
    
    Esempio input:
    a.cde
    fdffr
    tQfrd
    yyfwe
    f1bpf

    Relativo output:
    a.cde
     d  r
    tQ rd
    yy we
     1bp
*/

#include <stdio.h>

#define N 5

// Riceve come parametro una matrice quadrata NxN (con N definito staticamente, ma ipotizzando che potrebbe cambiare) di caratteri, di cui individuarne il carattere che compare con maggiore frequenza e lo restituisce (in caso di molteplici caratteri, si tenga il primo trovato);
char sottoprogramma_1(char matrix[N][N]) {
    
    // DICHIARAZIONE VARIABILI
    char max_char;          // Carattere con maggiori occorrenze
    char check;             // Carattere corrente da verificare
    int counter;            // Contatore occorrenze carattere corrente
    int max_counter = 0;    // Contatore carattere con maggiori occorrenze

    // SCORRO TUTTA LA MATRICE
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {

            check = matrix[i][j];   // Prendo ogni volta il carattere [i][j]
            counter = 0;            // Inizializzo contatore carattere corrente

            // SCORRO TUTTA LA MATRICE 
            for(int k = 0; k < N; k++) {
                for(int h = 0; h < N; h++) {

                    // CONTO LE OCCORRENZE PER CIASCUN CARATTERE [i][j]
                    if(matrix[k][h] == check) {
                        counter++;
                    }
                }
            }

            // INDIVIDUO IL CARATTERE CON MAGGIOR NUMERO DI OCCORRENZE
            if(counter > max_counter) {
                max_counter = counter;  // Sostituisco ogni volta
                max_char = matrix[i][j];
            }
        }
    }
    return max_char;
}

// Riceve come parametri un carattere e una matrice quadrata NxN di caratteri, visualizzando su terminale la stessa matrice però con uno spazio al posto di tutti i caratteri uguali al carattere passato come parametro
void sottoprogramma_2(char carattere, char matrix[N][N]) {

    // SOSTITUISCO IL CARATTERE INDIVIDUATO CON ' '
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(matrix[i][j] == carattere) {
                matrix[i][j] = ' ';
            }
        }
    }

    // STAMPO LA MATRICE MODIFICATA
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

// Individua il carattere che compare più frequentemente in una matrice NxN di caratteri, riempita dall'utente, per poi stamparla a schermo mostrando però uno spazio al posto dei caratteri uguali al carattere individuato. 
int main(void) {

    // DICHIARAZIONE VARIABILI
    char matrix[N][N]; // Matrice di caratteri
    char carattere;    // Carattere con maggiori occorrenze

    // MESSAGGIO DI AVVIO
    printf("\n** Avvio del programma **\n");
    printf("Inserire caratteri matrice %i x %i:\n", N, N);

    // RICHIESTA INSERIMENTO CARATTERI
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf(" %c", &matrix[i][j]);
        }
    }

    // IDENTIFICO IL CARATTERE CON MAGGIORI OCCORRENZE
    carattere = sottoprogramma_1(matrix);

    // STAMPA FINALE
    printf("\n** Fase di elaborazione **\n");
    printf("Matrice %i x %i modificata:\n", N, N);

    // MODIFICO LA MATRICE E LA STAMPO
    sottoprogramma_2(carattere, matrix);
    printf("\n");

    return 0;
}