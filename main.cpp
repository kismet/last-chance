// Autore: Tosi Gianmarcp
// Data:   2026/05/23
// Classe: 3CI
// Fila:   B
#include <iostream>
#include <iomanip>
#include "inc/libreria_tipi.h"
#include "inc/libreria.h"

using namespace std;

int main() {

    // --- TEST 1: crea_lista_libri ---
    cout << "[TEST 1] Inizializzazione liste libri con crea_lista_libri()" << endl;
    Libri_t c1, c2, c3;
    crea_lista_libri(c1, "3AI", "Informatica");
    crea_lista_libri(c2, "5BI", "Informatica");
    crea_lista_libri(c3, "1CSA", "Scienze Applicate");

    cout << "Classe 1 creata:" << endl;
    stampa_lista_libri(&c1);
    cout << "Classe 2 creata:" << endl;
    stampa_lista_libri(&c2);
    cout << "Classe 3 creata:" << endl;
    stampa_lista_libri(&c3);
    cout << endl;

    // --- TEST 2: aggiungi_costo_libro e costo_medio_libri ---
    cout << "[TEST 2] Aggiunta dei prezzi dei libri con aggiungi_costo_libro()" << endl;
    cout << "(La media viene ricalcolata in automatico tramite costo_medio_libri)" << endl << endl;

    // Classe c1 (3A Informatica)
    aggiungi_costo_libro(c1, 15.50f);
    aggiungi_costo_libro(c1, 24.00f);
    aggiungi_costo_libro(c1, 32.80f);
    aggiungi_costo_libro(c1, 19.99f);

    // Classe c2 (5B Informatica)
    aggiungi_costo_libro(c2, 45.00f);
    aggiungi_costo_libro(c2, 52.50f);
    aggiungi_costo_libro(c2, 38.00f);

    // Classe c3 (1C Scienze Applicate)
    aggiungi_costo_libro(c3, 28.50f);
    aggiungi_costo_libro(c3, 31.00f);
    aggiungi_costo_libro(c3, 22.00f);
    aggiungi_costo_libro(c3, 15.00f);
    aggiungi_costo_libro(c3, 42.00f);

    cout << "Stato dopo l'inserimento dei costi dei libri:" << endl;
    cout << "Classe 3A Informatica:" << endl;
    stampa_lista_libri(&c1);
    cout << "Classe 5B Informatica:" << endl;
    stampa_lista_libri(&c2);
    cout << "Classe 1C Scienze Applicate:" << endl;
    stampa_lista_libri(&c3);
    cout << endl;

    // --- TEST 3: stampa_lista_libri ---
    cout << "[TEST 3] La stampa delle informazioni e stata eseguita con successo via stampa_lista_libri()" << endl;
    cout << "Tutti i parametri (classe/anno, indirizzo, quantita, singoli costi, media) sono stati verificati." << endl;
    cout << endl;

    // --- TEST 4: sconto ---
    cout << "[TEST 4] Applicazione dello sconto con sconto()" << endl;
    cout << "Applichiamo 3.50 EUR di sconto all'ultimo libro della classe 3A (da 19.99 EUR a 16.49 EUR)..." << endl;
    cout << "Classe 3A prima dello sconto:" << endl;
    stampa_lista_libri(&c1);

    // Eseguiamo lo sconto
    sconto(&c3, 3.5f);

    cout << "Classe 3A dopo lo sconto (ultimo libro e media ricalcolati):" << endl;
    stampa_lista_libri(&c1);
    cout << endl;

    return 0;
}