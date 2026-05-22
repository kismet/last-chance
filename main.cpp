// Autore: Buono Lorenzo
// Data:   2026/05/23
// Classe: 3CI
// Fila:   A
#include <iostream>
#include "inc/libreria_tipi.h"
#include "inc/libreria.h"

using namespace std;


int main() {

    // --- TEST 1: crea_pilota ---
    cout << "[TEST 1] Inizializzazione dei piloti con crea_pilota()" << endl;
    Pilota_t p1, p2, p3;
    crea_pilota(p1, "Leclerc", "Ferrari");
    crea_pilota(p2, "Hamilton", "Ferrari");
    crea_pilota(p3, "Verstappen", "Red Bull");

    cout << "Pilota 1 creato:" << endl;
    stampa_pilota(p1);
    cout << "Pilota 2 creato:" << endl;
    stampa_pilota(p2);
    cout << "Pilota 3 creato:" << endl;
    stampa_pilota(p3);
    cout << endl;

    // --- TEST 2: aggiungi_granpremio e calcola_media ---
    cout << "[TEST 2] Aggiunta di punteggi con aggiungi_granpremio()" << endl;
    cout << "(La media viene ricalcolata automaticamente tramite calcola_media)" << endl << endl;

    // Leclerc
    aggiungi_granpremio(p1, 25); // GP 1
    aggiungi_granpremio(p1, 18); // GP 2
    aggiungi_granpremio(p1, 15); // GP 3

    // Hamilton
    aggiungi_granpremio(p2, 12); // GP 1
    aggiungi_granpremio(p2, 10); // GP 2
    aggiungi_granpremio(p2, 18); // GP 3
    aggiungi_granpremio(p2, 25); // GP 4

    // Verstappen
    aggiungi_granpremio(p3, 25); // GP 1
    aggiungi_granpremio(p3, 25); // GP 2
    aggiungi_granpremio(p3, 25); // GP 3
    aggiungi_granpremio(p3, 18); // GP 4

    cout << "Stato dopo l'inserimento dei Gran Premi:" << endl;
    cout << "Leclerc:" << endl;
    stampa_pilota(p1);
    cout << "Hamilton:" << endl;
    stampa_pilota(p2);
    cout << "Verstappen:" << endl;
    stampa_pilota(p3);
    cout << endl;

    return 0;
}