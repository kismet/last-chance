
#include "../inc/libreria.h"
#include "../inc/libreria_tipi.h"
#include <iostream>

using namespace std;

// Calcola la media di km di compiere in questa gara
void lunghezza_media(Gara_Tappe_t &x) {

    // Se le tappe sono 0 lunghezza media tappe = 0
    if ( x.num_tappe == 0 ) {
        x.lunghezza_media_tappe = 0;
    }
    else {
        float sommaKm = 0;

        for ( int i = 0; i < x.num_tappe; i++ ) {
            sommaKm = sommaKm + x.tappe[i];
        }

        x.lunghezza_media_tappe = sommaKm / x.num_tappe;
    }
}

// Aggiunge il p kilometri all'elenco di un cadavedere x se ci sono posti liberi e altrimenti restituisce false
bool aggiungi_tappa(Gara_Tappe_t &x, float p) {

    if ( x.num_tappe >= N_MASSIMO_TAPPE ) {
        return false;
    }

    x.tappe[x.num_tappe] = p;
    x.num_tappe++;

    return true;
}