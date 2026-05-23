
#include "../inc/libreria.h"
#include "../inc/libreria_tipi.h"
#include <iostream>
#include <string>

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

// Togli x km dall'ultima tappa
void trasferimento(Gara_Tappe_t *s, float km) {

    if ( s->num_tappe > 0 ) {
        s->tappe[s->num_tappe - 1] -= km;
        lunghezza_media(*s);
    }
}

// Restituisce la gara più lunga
Gara_Tappe_t* gara_piu_lunga(Gara_Tappe_t gare[], int dim) {

    if ( dim == 0 ) {
        return nullptr;
    }

    // Puntatore alla gara più lunga
    // Di base lo faccio puntare alla prima gara
    Gara_Tappe_t* garaLunga = &gare[0];

    // Parto da secondo elemento dell'array
    for ( int i = 1; i < dim; i++ ) {

        if ( gare[i].lunghezza_media_tappe > garaLunga->lunghezza_media_tappe ) {
            garaLunga = &gare[i];
        }
    }

    return garaLunga;

}

// Restituisce il nome della gara che risulta più lunga in km dalla sua prima edizione ad ora
string gare_storica_piu_lunga(Gara_Tappe_t gare[], int dim) {

    // Se non ci sono gare inserite ritorno nulla
    if ( dim == 0 ) {
        return ".";
    }

    // Presumo che sia la prima gara e se ne trovo una più lunga aggiorno i valori
    string nomeGaraLunga = gare[0].nome;
    float mediaGaraLunga = gare[0].lunghezza_media_tappe;

    // Parto da secondo elemento dell'array
    for ( int i = 1; i < dim; i++ ) {
        if ( gare[i].lunghezza_media_tappe > mediaGaraLunga ) {
            nomeGaraLunga = gare[i].nome;
        }
    }

    return nomeGaraLunga;
}