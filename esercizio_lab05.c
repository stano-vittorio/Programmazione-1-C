/*
Code created by STANO VITTORIO MARIA - UniVR Dept. of Computer Science

Scrivere un programma C usando le seguenti strutture dati che rappresentano un concessionario con il relativo gestore e le auto vendute: 
    
        #define MAX_STR 30
        #define MAX_TRG 7
        #define MAX_AUTO_CONCE 50
        
        typedef struct automobile {
            char modello[MAX_STR + 1];
            char targa[MAX_TRG + 1];
            int  mese_immatricolazione;
            int  anno_immatricolazione;
        } auto_t;

        typedef struct persona {
            char piva[MAX_STR + 1];
            char nome[MAX_STR + 1];
            char cognome[MAX_STR + 1];
        } persona_t;

        typedef struct concessionario{
            int       codice_concessionario;
            persona_t gestore;
            auto_t    automobili[MAX_AUTO_CONCE];    
            int       num_auto; // Numero auto inizializzate nel array automobili. 
        } concessionario_t;
        

Si realizzi una funzione che prende in input un array di tipo concessionario_t ed il numero di concessionari inseriti (non è detto corrisponda alla dimensione massima del array), e che per ogni concessionario stampi a video codice, gestore ed per ogni auto immatricolata nel 2015, modello, targa e mese (in numero) dell'auto. 
Il report mostrato dovrà avere il seguente formato: 
    
        Conc. 0, codice 12345: gestore Paolo Rossi
        Immatricolazioni 2015:
        * mese 9: Punto, MI80980
        * mese 6: Marea, TO12567

        Conc. 1, codice 23456: gestore Luca Bianchi
        Immatricolazioni 2015:
        * mese 2: Panda, VE85980
    

Si scriva poi la funzione main per testare le funzionalità del programma sviluppato inizializzando con opportuni valori l'array di concessionario_t.
 
 */

#include <stdio.h>

#define MAX_STR 30
#define MAX_TRG 7
#define MAX_AUTO_CONCE 50

#define DIM 10 // Dimensione array concessionario_t x[] = numero max concessionari

// Struct dati automobile
typedef struct automobile {
	char modello[MAX_STR + 1]; // Modello automobile
    char targa[MAX_TRG + 1]; // Targa automobile
    int mese_immatricolazione; // Mese immatr. automobile
    int anno_immatricolazione; // Anno immatr. automobile
} auto_t;

// Struct dati gestore
typedef struct persona {
    char piva[MAX_STR + 1]; // P.IVA gestore
    char nome[MAX_STR + 1]; // Nome gestore
    char cognome[MAX_STR + 1]; // Cognome gestore
} persona_t;

// Struct dati concessionario
typedef struct concessionario {
    int codice_concessionario; // Codice concessionario
    persona_t gestore; // Gestore conc. --> struct persona_t
    auto_t automobili[MAX_AUTO_CONCE]; // Dati auto conc. --> struct auto_t
    int num_auto; // Numero auto concessionario
} concessionario_t;


// Start funzione printReport
void printReport(concessionario_t x[], int Dealer) {

    // Dichiarazione variabili locali
    int i, j; // Indici di ciclo

    printf("\n"); // Stampa riga vuota per interfaccia grafica

    for(i = 0; i < Dealer; i++) { // Ciclo for per numero di conc.
        printf("Conc. %i, ", i); // Intestazione conc.
        printf("codice %i: ", x[i].codice_concessionario); // Intestazione codice
        printf("gestore %s", x[i].gestore.nome); // Intestazione nome gestore
        printf(" %s\n", x[i].gestore.cognome); // Intestazione cognome gestore

        printf("Immatricolazioni 2015:\n"); // Titolo immatricolazione

        for(j = 0; j < x[i].num_auto; j++) { // Ciclo for verifica

            if(x[i].automobili[j].anno_immatricolazione == 2015) { // Verifica immatr. anno 2015
                printf("* mese %2i: ", x[i].automobili[j].mese_immatricolazione); // Intestazione mese
                printf("%s, ", x[i].automobili[j].modello); // Intestazione modello auto
                printf("%s ", x[i].automobili[j].targa); // Intestazione targa auto
                printf("\n"); // Stampa riga vuota per interfaccia grafica
            }
        }
        printf("\n"); // Stampa riga vuota per interfaccia grafica
    }
}


// Start funzione main
int main(void) {
    
    // Dichiarazione variabili locali
    int numDealer = 3; // Assegnazione numero concessionari

    concessionario_t x[DIM]; // Assegnazione array x[] a typedef concessionario_t

    // Concessionario 0 - Assegnazione dati
    concessionario_t conc_0 = { // {codice conc., persona_t, auto_t, numero auto}
        12345, // Codice conc.
        {"02391864134", "Paolo", "Rossi"}, // Dati gestore --> struct persona_t
        {{"Punto", "MI80980", 9, 2015}, // Dati auto 1 --> struct auto_t
         {"Marea", "TO12567", 6, 2015}, // Dati auto 2 --> struct auto_t
         {"Auris", "PD926LV", 10, 2012}}, // Dati auto 3 --> struct auto_t
        3 // Numero auto
    };

    // Concessionario 1 - Assegnazione dati
    concessionario_t conc_1 = { // {codice conc., persona_t, auto_t, numero auto}
        23456, // Codice conc.
        {"02296862543", "Luca", "Bianchi"}, // Dati gestore --> struct persona_t
        {{"Panda", "VE85980", 2, 2015}, // Dati auto 1 --> struct auto_t
         {"Niro", "LE192VT", 8, 2001}, // Dati auto 2 --> struct auto_t
         {"Sportage", "FS349MW", 3, 2015}}, // Dati auto 3 --> struct auto_t
        3 // Numero auto
    };

    // Concessionario 2 - Assegnazione dati
    concessionario_t conc_2 = { // {codice conc., persona_t, auto_t, numero auto}
        34567, // Codice conc.
        {"02196562143", "Aldo", "Montano"}, // Dati gestore --> struct persona_t
        {{"Levante", "VI875ES", 12, 2015}, // Dati auto 1 --> struct auto_t
         {"Sorento", "RO209NE", 7, 2018}}, // Dati auto 2 --> struct auto_t
        2 // Numero auto
    };

    // Assegnazione dati concessionari in array concessionario_t x[DIM]
    x[0] = conc_0; // Concessionario 0
    x[1] = conc_1; // Concessionario 1
    x[2] = conc_2; // Concessionario 2

    printReport(x, numDealer); // Start funzione con input array e num. conc.

    return 0;
}