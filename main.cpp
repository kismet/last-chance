// Autore: Landucci Gianmarco
// Data:   2026/05/23
// Classe: 3CI
// Fila:   C

#include <iostream>
#include "inc/libreria.h"

using namespace std;

int main() {

    // --- TEST 1: crea_viaggio ---
    cout << "[TEST 1] Inizializzazione dei viaggi con crea_viaggio()" << endl;
    Viaggio_t v1, v2, v3;
    crea_viaggio(v1, "Roma", "Milano");
    crea_viaggio(v2, "Napoli", "Milano");
    crea_viaggio(v3, "Firenze", "Torino");

    cout << "Viaggio 1 creato:" << endl;
    stampa_viaggio(&v1); // Corretto: passa l'indirizzo &v1
    cout << "Viaggio 2 creato:" << endl;
    stampa_viaggio(&v2); // Corretto: passa l'indirizzo &v2
    cout << "Viaggio 3 creato:" << endl;
    stampa_viaggio(&v3); // Corretto: passa l'indirizzo &v3
    cout << endl;

    // --- TEST 2: aggiungi_tratta e calcola_media ---
    cout << "[TEST 2] Aggiunta di tratte con aggiungi_tratta()" << endl;
    cout << "(La media viene ricalcolata automaticamente tramite calcola_media)" << endl << endl;

    // Viaggio 1 (Roma -> Milano)
    aggiungi_tratta(v1, 150.5f); // Tratta 1
    aggiungi_tratta(v1, 220.0f); // Tratta 2
    aggiungi_tratta(v1, 180.0f); // Tratta 3

    // Viaggio 2 (Napoli -> Milano)
    aggiungi_tratta(v2, 300.0f); // Tratta 1
    aggiungi_tratta(v2, 450.0f); // Tratta 2

    // Viaggio 3 (Firenze -> Torino)
    aggiungi_tratta(v3, 120.0f); // Tratta 1
    aggiungi_tratta(v3, 100.0f); // Tratta 2
    aggiungi_tratta(v3, 180.0f); // Tratta 3
    aggiungi_tratta(v3, 90.0f);  // Tratta 4

    cout << "Stato dei viaggi dopo l'inserimento delle tratte:" << endl;

    cout << endl;

    cout << "Viaggio 1 (Roma -> Milano):" << endl;
    stampa_viaggio(&v1);

    cout << endl;

    cout << "Viaggio 2 (Napoli -> Milano):" << endl;
    stampa_viaggio(&v2);

    cout << endl;

    cout << "Viaggio 3 (Firenze -> Torino):" << endl;
    stampa_viaggio(&v3);
    cout << endl;

    return 0;
}