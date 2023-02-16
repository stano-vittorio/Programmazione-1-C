/*
Code created by STANO VITTORIO MARIA - UniVR Dept. of Computer Science

Scrivere un programma C che crea un array di stringhe che contiene i valori da 1 a N (con N definito staticamente), sostituendo con la stringa "CIP" i numeri che sono multipli di 3, con "CIOP" i numeri che sono multipli di 7 e con "CIPCIOP" i numeri che sono multipli sia di 3 che di 7 e stamparne il risultato. 
Il programma deve essere costituito dai seguenti sottoprogrammi:

Sottoprogramma 1: prende in input il riferimento ad un array di stringhe e lo riempie con i numeri da 1 ad N, convertiti in stringa ed assegnati all'array.

Sottoprogramma 2: prende in input il riferimento ad un array di stringhe, controllando che contenga solo stringhe formate da numerali e sostituendo con la stringa "CIP" i numeri che sono multipli di 3, con "CIOP" i numeri che sono multipli di 7 e con "CIPCIOP" i numeri che sono multipli sia di 3 che di 7.

Sottoprogramma 3: prende in input il riferimento ad un array di stringhe e ne stampa in output le stringhe contenute, separate da una virgola come nell'esempio.

Sottoprogramma main: alloca un array di stringhe di dimensione adatta a rappresentare il problema, senza chiedere alcun valore all'utente, e richiama i sottoprogrammi precedentemente elencati per risolvere la specifica data.

    
    Esempio: N = 50

    Array dopo il sottoprogramma 1: { "1", "2", "3", "4", "5", "6", "7", "8", ... , "48", "49", "50" }
    Array dopo il sottoprogramma 2: { "1", "2", "CIP", "4", "5", "CIP", "CIOP", "8", "CIP", "10", "11", "CIP", "13", "CIOP", "CIP", "16", "17", "CIP", "19", "20", "CIPCIOP", "22", ... , "CIP", "CIOP", "50" }

    Stampa finale: 1, 2, CIP, 4, 5, CIP, CIOP, 8, CIP, 10, 11, CIP, 13, CIOP, CIP, 16, 17, CIP, 19, 20, CIPCIOP, 22, 23, CIP, 25, 26, CIP, CIOP, 29, CIP, 31, 32, CIP, 34, CIOP, CIP, 37, 38, CIP, 40, 41, CIPCIOP, 43, 44, CIP, 46, 47, CIP, CIOP, 50
    

Avvertenze: non è concesso utilizzare la libreria <string.h>, dunque sarà necessario create delle funzioni di supporto per gestire le stringhe.
 
 */

#include <stdio.h>

#define DIM 100 // Definizione numero righe (valore massimo generato)
#define MAX_CHAR 10 + 1 // Definizione numero colonne (cifre massime valore generato)


// Funzione di inserimento caratteri char in stringa di destinazione
void inserimento_valori(char input[MAX_CHAR], char output[MAX_CHAR]) {
    
    int i = 0; // Variabile scorrimento posizione

    // Scorrimento fino a carattere di terminazione
    while(input[i] != '\0') {

        output[i] = input[i]; // Assegno valori in stringa di destinazione
        i++; // Incremento posizione
    }

    output[i] = '\0'; // Carattere di terminazione stringa
}

// Funzione di verifica dei valori numerici in ogni posizione
int verifica_numero(char string_array[MAX_CHAR]) {

    int i = 0; // Variabile scorrimento posizione
    int x = 0; // Variabile sentinella per verifica numero

    // Scorrimento fino a carattere di terminazione
    while(string_array[i] != '\0') {

        // Condizioni di verifica carattere numerico
        if(string_array[i] >= '0' || string_array[i] <= '9') {
            x = 1;
        }

        i++; // Incremento posizione
    }

    return x; // Ritorno variabile sentinella --> Se 1 = ok valori numerici
}

// Funzione di conversione stringhe da caratteri char a numeri interi
int conversione_char_int(char string_array[MAX_CHAR]) {

    int i = 0; // Variabile scorrimento posizione
    int num_int = 0; // Variabile per numero convertito

    // Scorrimento fino a carattere di terminazione
    while(string_array[i] != '\0') {

        // Moltiplico per 10 e sommo per la successiva pos. (es. 1 1 (11) : 1*10 = 10 + 1 = 11)
        num_int *= 10; 
        num_int += string_array[i] - '0'; // Fase di conversione
        i++; // Incremento posizione
    }

    return num_int; // Ritorno numero convertito da CHAR a INT
}

// Prende in input il riferimento ad un insieme di array stringhe (matrice) e li riempie con numeri da 1 ad DIM, convertiti in stringa ed assegnati all'array. L'assegnazione viene effettuata attraverso la funzione inserimento_valori (riga 36)
void sottoprogramma1(char string_matrix[DIM][MAX_CHAR]) {

    int n, copy_n; // Variabili per numero generato
    int counter; // Variabile counter
    char string2[MAX_CHAR] = {}; // Array stringa per valore generato da n

    for(int i = 0; i < DIM; i++) { // Scorrimento riga per riga

        n = copy_n = 1 + i; // Numero int generato

        // Contatore cifre numero int
        counter = 0;
        while(copy_n != 0) {
            counter++;
            copy_n /= 10;
        }

        // Conversione numero int in char da DX a SX
        for(int j = counter - 1; j >= 0; j--) {
            string2[j] = (n % 10) + '0'; // Assegnazione char
            n /= 10;
        }

        string2[counter] = '\0'; // Carattere di terminazione stringa

        // Passaggio a funzione di riempimento stringa
        inserimento_valori(string2, string_matrix[i]);
    }
}

// Prende in input il riferimento ad un insieme di array stringhe (matrice), controllando che contenga solo stringhe formate da numerali e sostituendo con la stringa "CIP" i numeri che sono multipli di 3, con "CIOP" i numeri che sono multipli di 7 e con "CIPCIOP" i numeri che sono multipli sia di 3 che di 7. L'assegnazione delle nuove stringhe viene effettuata attraverso la funzione inserimento_valori
void sottoprogramma2(char string_matrix[DIM][MAX_CHAR]) {

    int n; // Variabile per int convertito

    for(int i = 0; i < DIM; i++) { // Scorrimento riga per riga
        
        // Fase di verifica dei valori numerici
        if(verifica_numero(string_matrix[i]) == 1) { // Se 1 = ok valori numerici

            n = conversione_char_int(string_matrix[i]); // n contiene int convertito

            // Definizioni delle condizioni + passaggio a funzione di riempimento stringa
            if(n % 3 == 0 && n % 7 != 0) {
                inserimento_valori("CIP", string_matrix[i]);
            }
            else if(n % 7 == 0 && n % 3 != 0) {
                inserimento_valori("CIOP", string_matrix[i]);
            }
             else if(n % 3 == 0 && n % 7 == 0) {
                inserimento_valori("CIPCIOP", string_matrix[i]);
            }
        }
    }
}

// Prende in input il riferimento ad un insieme di array stringhe (matrice) e ne stampa in output le stringhe contenute, separate da una virgola tranne l'ultimo valore
void sottoprogramma3(char string_matrix[DIM][MAX_CHAR]) {

    int i; // Indice di ciclo

    printf("\n"); // Riga vuota per grafica
    printf("Stampa finale:\n");
    
    // Fase di stampa della matrice riga per riga (= array)
    for(i = 0; i < DIM - 1; i++) {
        printf("%s, ", string_matrix[i]);
    }

    printf("%s\n", string_matrix[i]); // Stampa ultimo elemento senza virgola
    printf("\n"); // Riga vuota per grafica
}

// Alloca un array di stringhe di dimensione adatta (matrice), senza chiedere alcun valore all'utente, e richiama i sottoprogrammi (sottoprogramma1, sottoporgramma2 e sottoprogramma3) per risolvere la specifica. I vari sottoprogrammi faranno riferimento ad altre funzioni implementate nel codice
int main(void) {
    
    // Definizione matrice --> righe = DIM; colonne = massimo numero char
    char string[DIM][MAX_CHAR] = {};

    // Chiamata a sottoprogrammi e passaggio di matrice
    sottoprogramma1(string);
    sottoprogramma2(string);
    sottoprogramma3(string);

    return 0;
}