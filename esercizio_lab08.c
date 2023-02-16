/*
Code created by STANO VITTORIO MARIA - UniVR Dept. of Computer Science
 
Scrivere un programma C che faciliti il compito di sistemare dei pezzi di ricambio auto nel magazzino a seconda del loro peso al gestore di un magazzino di ricambio auto. 

I ricambi auto sono di 3 tipi: gomme, paraurti e specchietti. 
Dovrete implementare una bilancia con memoria e con queste funzionalità:

L'utente ad ogni interazione può scegliere:
	1. quale tipo di pezzo pesare;
	2. vedere lo storico delle pesate, per cui massimo N pesate definite staticamente devono rimanere salvate;
	3. uscire dal programma;

La bilancia deve rispondere ad ogni pesata dell'utente con:
	1. un numero progressivo che indica quante pesate sono avvenute finora;
	2. il peso del pezzo pesato;

La bilancia deve salvare i dati della pesata appena avvenuta.


Alcuni requisiti tecnici:
	- Il programma deve contenere almeno il main() e una funzione pesa() per la bilancia;
	- Utilizzare una variabile statica all'interno di questa funzione pesa() per salvare il numero di pesate avvenute;
	- Usare una lista e almeno una variabile globale per salvare lo storico delle pesate;
	- Gestire la liberazione della memoria quando il limite massimo N di pesate mantenute in memoria viene raggiunto, ovvero gestire al momento di una nuova pesata la liberazione in memoria di un nodo, nello specifico il nodo più vecchio, e aggiungere il nodo nuovo;


Il peso dei vari pezzi varia in un range:
	- gomme: tra 9 e 11 kili;
	- paraurti = tra 18 e 22 kili;
	- specchietti = tra 0.1 e 1.5 kili

La pesata dei vari pezzi deve essere simulata con valori random float nel rispettivo range. 
Esempio: 

    
        Menu
        1. Pesa
        2. Vedi storico pesate
        0. Esci
        > 1
        Pesa cosa? (1 = gomma, 2 = paraurti, 3 = specchietto)
        > 2
        Pesata #1 => Questo paraurti pesa 20.25 kili

        Menu
        1. Pesa
        2. Vedi storico pesate
        0. Esci
        >1
        Pesa cosa? (1 = gomma, 2 = paraurti, 3 = specchietto)
        > 3
        Pesata #2 => Questo specchietto pesa 1.23 kili

        Menu
        1. Pesa
        2. Vedi storico pesate
        0. Esci
        > 2
        Pesate finora:
        1 => Paraurti, 20 kili
        2 => Specchietto, 1.2 kili

 */

#include <stdio.h>    // Libreria standard
#include <stdlib.h>   // Libreria per malloc e free
#include <time.h>     // Libreria per generatore random

#define MAX_LENGHT 20 // Massimo N di pesate in memoria

#define MAX_GOMME			11.00   // Range MAX peso gomme
#define MIN_GOMME			 9.00   // Range MIN peso gomme
#define MAX_PARAURTI		22.00   // Range MAX peso paraurti
#define MIN_PARAURTI		18.00   // Range MIN peso paraurti
#define MAX_SPECCHIETTI		 1.50   // Range MAX peso specchietti
#define MIN_SPECCHIETTI		 0.10   // Range MIN peso specchietti

// Struttura tipo per pesata
struct list {
	int id;                    // Variabile numero progressivo
	int type;                  // Variabile tipo prodotto
	float weight;              // Variabile peso prodotto
	struct list *next_weight;  // Prossima pesata (tipo list)
};

struct list *head;  // Creo pointer a lista list --> punterà all'inizio
struct list *tail;  // Creo pointer a lista list --> punterà alla fine


// Funzione pesa --> Si occupa della pesatura del prodotto scelto dall'utente
void pesa(int menu_1) {

	int menu_2;      // Scelta dell'utente (menu_2)
	int type_code;   // Variabile tipo prodotto (codice 1 2 3)
	float kg;        // Variabile peso prodotto
	struct list *elemento_pesato = malloc(sizeof(struct list));  // Alloco spazio per pesata corrente
    static int counter = 0;  // Counter numero progressivo pesate

    // Verifico che lo spazio possa essere allocato, altrimenti esco dal programma
    if (elemento_pesato == NULL) {
        printf("\nAllocazione fallita!\n\n");
        exit(1); // EXIT_FAILURE --> Esco dal programma con errore
    }

    // Scelta dell'utente menu_2 (tipo prodotto)
	do {
        printf("Pesa cosa? (1 = gomma, 2 = paraurti, 3 = specchietto)\n");
        printf("> ");
        scanf("%i", &menu_2);
    } while (menu_2 < 1 || menu_2 > 3); // Verifica valori ammessi

    counter++; // Incremento il counter (progressivo pesate)

    switch(menu_2) { // A seconda del prodotto scelto genero peso e stampo riepilogo
    	case 1:
    		type_code = 1; // Tipo Gomma
    		kg = ((float)rand() / RAND_MAX * (MAX_GOMME - MIN_GOMME) + MIN_GOMME);
            printf("Pesata #%2i => Questa gomma pesa %.2f kili\n", counter, kg);
    		break;

    	case 2:
    		type_code = 2; // Tipo Paraurti
    		kg = ((float)rand() / RAND_MAX * (MAX_PARAURTI - MIN_PARAURTI) + MIN_PARAURTI);
            printf("Pesata #%2i => Questo paraurti pesa %.2f kili\n", counter, kg);
    		break;

    	case 3:
    		type_code = 3; // Tipo Specchietti
    		kg = ((float)rand() / RAND_MAX * (MAX_SPECCHIETTI - MIN_SPECCHIETTI) + MIN_SPECCHIETTI);
            printf("Pesata #%2i => Questo specchietto pesa %.2f kili\n", counter, kg);
    		break;

    	default:
    		exit(1); // EXIT_FAILURE --> Esco dal programma con errore
    }

    elemento_pesato->id = counter;          // Assegno a pesata corrente: progressivo pesata
    elemento_pesato->type = type_code;      // Assegno a pesata corrente: tipo di prodotto
    elemento_pesato->weight = kg;           // Assegno a pesata corrente: peso prodotto
    elemento_pesato->next_weight = NULL;    // Inizializzo prossimo nodo pesata

    // Se mi trovo nella prima pesata --> head punta all'inizio
    if(counter == 1) {
    	head = elemento_pesato;
    }

    // Se supero N max allocabili --> libero nodo meno recente
    if(counter > MAX_LENGHT) {
    	struct list *free_node = head;   // Punto a nodo da liberare
       	head = head->next_weight;        // Assegno pointer head a nodo successivo
        free(free_node);                 // Libero il nodo puntato
    }

    if(tail != NULL) {
    	tail->next_weight = elemento_pesato;    // Punta all'ultima pesata effettuata
    }

    tail = elemento_pesato;                     // tail punta alla pesata corrente
}

// Funzione stampa_pesate --> Si occupa della stampa dello storico pesate (scelta utente '2')
void stampa_pesate() {

	struct list *print_list = head;   // Creo pointer che piunta a primo nodo
    int print_id;                     // Variabile numero pesata
    int print_type;                   // Variabile tipo prodotto
    float print_weight;               // Variabile peso prodotto

    while (print_list != NULL) { // Stampo lista fino all'ultima pesata
        
        print_id = print_list->id;           // Assegnazione numero pesata
        print_type = print_list->type;       // Assegnazione tipo prodotto
        print_weight = print_list->weight;   // Assegnazione peso prodotto

        switch (print_type) { // Stampa info a seconda del prodotto
            case 1: // Tipo Gomma
                printf("%2i => Gomma, %.2f kili\n", print_id, print_weight);
                break;
            
            case 2: // Tipo Paraurti
                printf("%2i => Paraurti, %.2f kili\n", print_id, print_weight);
                break;
            
            case 3: // Tipo Specchietto
                printf("%2i => Specchietto, %.2f kili\n", print_id, print_weight);
                break;

            default:
                exit(1); // EXIT_FAILURE --> Esco dal programma con errore
        }
        
        print_list = print_list->next_weight; // Punto alla pesata successiva
    }
}

// Funzione main --> Mostra il menu principale. A seconda della scelta dell'utente prosegue nelle fx
int main(void) {

	int menu_1; // Scelta dell'utente (menu_1)

	head = NULL; // Inizializzo list
	tail = NULL; // Inizializzo list

	srand(time(NULL)); // Inizializzo generatore random

	// Ciclo infinito per scelta menu_1
    while(1) {
		do {

            // Stampa menu principale
			printf("\nMenu\n");
			printf("1. Pesa\n");
			printf("2. Vedi storico pesate\n");
			printf("0. Esci\n");

			printf("> ");
			scanf("%i", &menu_1);

            // Casi di inserimento previsti
			switch (menu_1) {
				case 1:             // Effettuo pesata
					pesa(menu_1);   // Funzione di pesata
					break;

				case 2:                // Stampo pesate finora
					printf("\nPesate finora:\n");
					stampa_pesate();   // Funzione di stampa
					break;

				case 0: // Esco dal programma
					printf("\nUscita dal programma. Libero memoria...\n");

                    // Libero memoria allocata
					while (head != NULL) {
        				struct list *free_list = head;   // Punto a nodo da liberare
       					head = head->next_weight;        // Assegno pointer head a nodo successivo
        				free(free_list);                 // Libero il nodo puntato
    				}
    				printf("Memoria liberata\n\n");
    				exit(0); // EXIT_SUCCESS --> Esco dal programma con successo
			}

		} while(menu_1 < 0 || menu_1 > 2); // Verifica valori ammessi
	}

	return 0;
}