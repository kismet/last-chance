
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

    // Aggiorno anche la lunghezza media
    lunghezza_media(x);

    return true;
}

// Inizializza una gara a tappe di nome n ed edizione e
void crea_gara(Gara_Tappe_t &x, string n, int e) {

    x.nome = n;
    x.anno = e;
    x.num_tappe = 0;
    x.lunghezza_media_tappe = 0;

    for ( int i = 0; i < N_MASSIMO_TAPPE; i++ ) {
        x.tappe[i] = 0;
    }

}

// Stampa tutte le informazioni della gara a tappe x: nome, edizione, numero di tappe,
// lunghezza di ogni tappa, e infine la media
void stampa_gara(Gara_Tappe_t *x) {

    cout << "Nome: " << x->nome << endl;
    cout << "Edizione: " << x->anno << endl;
    cout << "Numero tappe: " << x->num_tappe << endl;
    for ( int i = 0; i < x->num_tappe; i++ ) {
        cout << "Tappa " << i + 1 << ": " << x->tappe[i] << endl;
    }
    cout << "Media: " << x->lunghezza_media_tappe << endl;

}