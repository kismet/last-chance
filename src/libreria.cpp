#include <iostream>
#include "../inc/libreria.h"

void tratta_media(Viaggio_t &x) {

    if (x.numero_tratte == 0) {
        x.media = 0;
        return;
    }

    float somma = 0;

    for (int i ; i < x.numero_tratte ; i++) {
        somma += x.tratte[i];
    }

    x.media = somma / x.numero_tratte;

}

bool aggiungi_tratta(Viaggio_t &x, float km) {

    if (x.numero_tratte >= MAX_TRATTE) {
        return false;
    }

    x.tratte[x.numero_tratte] = km;
    x.numero_tratte ++;

    tratta_media(x);

    return true;
}

void crea_viaggio(Viaggio_t &x, string p, string d) {
    
    x.partenza = p;
    x.destinazione = d;
    x.numero_tratte = 0;
    x.media = 0;

    for (int i = 0; i < MAX_TRATTE; i++) {
        x.tratte[i] = 0;
    }

}

/**
 * Stampa tutte le informazioni del pilota x: nome, cognome, numero di gran premi e punteggio per ogni gran premio
 * e infine la media
 */
void stampa_pilota(Pilota_t *x);

/**
 * Togli p punti dall'ultimo piazzamento del pilota x
 * OPZIONALE: per chi ha diritto alla riduzione
 */
void retrocedi(Pilota_t *s, float punti);

/**
 * Restituisce il Pilota campione del mondo (quello con più punti)
 * OPZIONALE: per chi ha diritto alla riduzione
 */
Pilota_t* campione_del_mondo(Pilota_t pilots[], int dim);

/**
 * Restituisce il nome della scuderia che ha fatto più punti
 * BONUS: per chi ha diritto alla riduzione
 */
string scuderia_campione(Pilota_t pilots[], int dim);

