#include <iostream>
#include "../inc/libreria.h"

void tratta_media(Viaggio_t &x) {

    if (x.numero_tratte == 0) { // Check se il numero delle tratte e' uguale a 0
        x.media = 0;
        return;
    }

    float somma = 0; // Creo la variabile somma e la inizializzo a 0

    for (int i = 0; i < x.numero_tratte ; i++) {
        somma += x.tratte[i]; // Sommo tutte le tratte
    }

    x.media = somma / x.numero_tratte; // Faccio la media utilizzando somma che continee tutte le tratte

}

bool aggiungi_tratta(Viaggio_t &x, float km) {

    if (x.numero_tratte >= N_FERMATE_STOP) { // Check se il numero delle tratte rientra nel range del massimo delle tratte
        return false;
    }

    x.tratte[x.numero_tratte] = km;
    x.numero_tratte++;

    tratta_media(x);

    return true;
}

void crea_viaggio(Viaggio_t &x, string p, string d) {

    //
    x.partenza = p;
    x.destinazione = d;
    x.numero_tratte = 0;
    x.media = 0;

    // Svuoto tutte le tratte fino a N_FERMATE_STOP
    for (int i = 0; i < N_FERMATE_STOP; i++) {
        x.tratte[i] = 0;
    }

}

void stampa_viaggio(Viaggio_t *x) {

    cout << "- Partenza -> " << x->partenza << endl; // Stampo il campo partenza
    cout << "- Destinazione -> " << x->destinazione << endl; // Stampo il campo destinazione
    cout << "- Numero Tratte -> " << x->numero_tratte << endl; // Stampo il campo numero tratte

    // Stampo i valori delle varie tratte (numero tratte) del viaggio
    for (int i = 0; i < x->numero_tratte ; i++) { //
        cout << "  - Tratta " << i + 1 << ": " << x->tratte[i] << " km" << endl;
    }

    cout << "- Media Tratte -> " << x->media << " km" << endl; // Stampo il campo della media dei km delle tratte

}

void scorciatoia(Viaggio_t *s, float km) {

}

Viaggio_t* viaggio_lungo(Viaggio_t viaggi[], int dim) {

}

string destinazione_principale(Viaggio_t viaggi[], int dim) {

}

