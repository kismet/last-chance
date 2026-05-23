#include <iostream>
#include "inc/libreria_tipi.h"
#include "inc/libreria.h"
using namespace std;

// Autore: Calcagni Luca
// Data:   2026/05/23
// Classe: 3CI
// Fila:   C

int main() {

    // --- TEST 1: crea_viaggio ---
    cout << "[TEST 1] Inizializzazione dei viaggi con crea_viaggio()" << endl;
    Viaggio_t v1, v2, v3;
    for (int i = 0; i < N_FERMATE_STOP; i++) {
        v1.tratte[i] = 0;
        v2.tratte[i] = 0;
        v3.tratte[i] = 0;
    }
    crea_viaggio(v1, "Roma", "Milano");
    crea_viaggio(v2, "Napoli", "Milano");
    crea_viaggio(v3, "Firenze", "Torino");
    
    // Viaggio 1 (Roma -> Milano)
    aggiungi_tratta(v1, 150.5); // Tratta 1
    aggiungi_tratta(v1, 220.0); // Tratta 2
    aggiungi_tratta(v1, 180.0); // Tratta 3

    // Viaggio 2 (Napoli -> Milano)
    aggiungi_tratta(v2, 300.0); // Tratta 1
    aggiungi_tratta(v2, 450.0); // Tratta 2

    // Viaggio 3 (Firenze -> Torino)
    aggiungi_tratta(v3, 120.0); // Tratta 1
    aggiungi_tratta(v3, 100.0); // Tratta 2
    aggiungi_tratta(v3, 180.0); // Tratta 3
    aggiungi_tratta(v3, 90.0);  // Tratta 4

    cout << "Stato dei viaggi dopo l'inserimento delle tratte:" << endl;
    cout << "Viaggio 1 (Roma -> Milano):" << endl;
    stampa_viaggio(v1);
    cout << "Viaggio 2 (Napoli -> Milano):" << endl;
    stampa_viaggio(v2);
    cout << "Viaggio 3 (Firenze -> Torino):" << endl;
    stampa_viaggio(v3);
    cout << endl;

    return 0;
}