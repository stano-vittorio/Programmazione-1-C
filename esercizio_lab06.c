/*
Code created by STANO VITTORIO MARIA - UniVR Dept. of Computer Science

Scrivere un programma C in cui si definisce una funzione che prende come parametri una stringa ed un carattere e restituisce un’altra stringa, da cui sono state rimosse tutte le occorrenze del carattere.

Infine si scriva la funzione main in cui si testa la propria implementazione della funzione con qualche stringa. 

    Esempio:
    Stringa = "allocazione"; Carattere da rimuovere = 'c'; => "alloazione"
 
 */

#include <stdio.h>

#define DIM 100 + 1 // Dimensione max string 100 + terminazione


// Start funzione remove_char
void remove_char(char string1[], char character) { // Input stringa + carattere

    // Dichiarazione variabili
    char string2[DIM]; // Stringa di destinazione
    int i; // Indice di ciclo
    int pos = 0; // Indice di incremento posizione

    for(i = 0; i < DIM; i++) { // Ciclo for per dimensione max stringa
        if(string1[i] != character) { // if per identificare il carattere da eliminare
            string2[pos] = string1[i]; // Assegnazione char string1 a string2 (if true)
            pos++; // Incremento posizione string2 (if true)
        }
    }

    // Stampa riepilogo e valori finali
    printf("Stringa = %s; Carattere da rimuovere = '%c'; => %s\n", string1, character, string2);
}


// Start funzione main
int main(void) {

    printf("\n"); // Stampa riga vuota per grafica

    // Assegnazione valori di test
    remove_char("allocazione", 'c'); // Chiamata fx (stringa, carattere)
    remove_char("vittoria", 't'); // Chiamata fx (stringa, carattere)
    remove_char("programmazione", 'a'); // Chiamata fx (stringa, carattere)
    remove_char("GigaByte", 'B'); // Chiamata fx (stringa, carattere)
    remove_char("Computer", 'C'); // Chiamata fx (stringa, carattere)
    remove_char("TeraFlops", 'F'); // Chiamata fx (stringa, carattere)

    printf("\n"); // Stampa riga vuota per grafica
    
    return 0;
}