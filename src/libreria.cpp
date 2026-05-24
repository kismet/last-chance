#include <iostream>
#include "../inc/libreria_tipi.h"
#include "../inc/libreria.h"

// Autore: Calcagni Luca
// Data:   2026/05/23
// Classe: 3CI
// Fila:   C

/**
 * Calcola la media in km delle varie tratte
 */
void tratta_media(Viaggio_t &x) {
    int contatore = 0;
    float somma = 0;
    for (int i = 0; i < N_FERMATE_STOP; i++) {
        if (x.tratte[i] > 0) {
            contatore += 1;
            somma += x.tratte[i];
        }
    }
    //LENZI non funziona quando contatore è ZERO
    x.media = somma / contatore;
}

/**
 * Aggiunge il km kilometri al viaggio x, se ci sono posti liberi e altrimenti restituisce false
 */
bool aggiungi_tratta(Viaggio_t &x, float km) {
    if (x.numero_tratte > N_FERMATE_STOP) {
        return false;
    }
    x.numero_tratte++;
    x.tratte[x.numero_tratte-1] = km;
    return true;
}

/**
 * Inizializza un pilota, dandogli una partenza p e una destinazione d
 */
void crea_viaggio(Viaggio_t &x, string p, string d) {
    x.partenza = p;
    x.destinazione = d;
    //LENZI meglio inizializzare anche x.numero_tratte = 0;

}

/**
 * Stampa tutte le informazioni del viaggio x: partenza, destinazione, numero di tratte, km per ogni tratta
 * e infine la distanza media di ogni tratta
 */
void stampa_viaggio(Viaggio_t &x) {
    //LENZI hai cambiato il prototipo della funzione
    cout << "partenza: " << x.partenza << endl;
    cout << "destinazione: " << x.destinazione << endl;
    cout << "chilometri tratte: ";
    for (int i = 0; i < N_FERMATE_STOP; i++) {
        if (x.tratte[i] > 0) {
            cout << x.tratte[i] << " ";
        }
    }
    cout << endl;
    cout << "numero di tratte fino ad ora: " << x.numero_tratte << endl;
    tratta_media(x);
    cout << "media: " << x.media << endl;
}

/**
 * Togli km kilometri dall'ultimo tratta
 * OPZIONALE: per chi ha diritto alla riduzione
 */
void scorciatoia(Viaggio_t *s, float punti);

/**
 * Restituisce il Viaggio più lungo in termini di kilometri
 * OPZIONALE: per chi ha diritto alla riduzione
 */
Viaggio_t* viaggio_lungo(Viaggio_t viaggi[], int dim);

/**
 * Restituisce la destinazione che ha il maggior numero di km percorsi che la raggiungono
 * BONUS: per chi ha diritto alla riduzione
 */
string destinazione_principale(Viaggio_t viaggi[], int dim);

