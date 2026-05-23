// Autore: Esposito Lorenzo
// Data:   2026/05/23
// Classe: 3CI
// Fila:   D

#include "C:\Users\esposito.lorenzo/Documents/last-chance/inc/libreria_tipi.h"

/**
* Calcola la media di km di compiere in questa gara
 */
void lunghezza_media(Gara_Tappe_t &x) {
    if (x.num_tappe == 0) {
        x.lunghezza_media_tappe = 0;
    }
    else
    {
        float somma_km_tappe = 0;
        for (int i = 0; i < x.num_tappe; i++) {
            somma_km_tappe += x.tappe[i];
        }
        x.lunghezza_media_tappe = somma_km_tappe/x.num_tappe;
    }
}

/**
 * Aggiunge il p kilometri all'elenco di tappe x se ci sono posti liberi e altrimenti restituisce false
 */
bool aggiungi_tappa(Gara_Tappe_t &x, float p) {
    if (x.num_tappe < N_MASSIMO_TAPPE) {
        x.tappe[x.num_tappe] = p;
        x.num_tappe++;
        return true;
    }
    return false;
}