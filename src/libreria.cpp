
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