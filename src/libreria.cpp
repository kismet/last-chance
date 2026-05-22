// Autore: Buono Lorenzo
// Data:   2026/05/23
// Classe: 3CI
// Fila:   A
#include <string>
#include "../inc/libreria.h"

#include <iostream>
#include <ostream>

/**
* Calcola la media di punteggi
 */
void calcola_media(Pilota_t &x) {

    x.media=0;
    for (int i=0; i < x.numero_gp; i++) {
        x.media = x.media + x.punti[i];
    }
    x.media = x.media / x.numero_gp;
}

/*
 * Aggiunge il p punti al pilota x, se ci sono posti liberi e altrimenti restituisce false
 */
bool aggiungi_granpremio(Pilota_t &x, int p) {

    if(x.numero_gp < N_GRAN_PREMI) {
        int punteggio_totale=0;
        for (int i=0; i < x.numero_gp; i++) {
            punteggio_totale += x.punti[i];
        }
        punteggio_totale +=p;
        return true;
    }
    return false;

}

/**
 * Inizializza un pilota, dandogli un nome n e una scuderia s
 */
void crea_pilota(Pilota_t &x, string n, string s) {

    x.cognome = n;
    x.scuderia = s;
}

/**
 * Stampa tutte le informazioni del pilota x: nome, cognome, numero di gran premi e punteggio per ogni gran premio
 * e infine la media
 */
void stampa_pilota(Pilota_t *x) {


    cout<<x->cognome<<endl;
    cout<<x->scuderia<<endl;
    cout<<x->numero_gp<<endl;

    for (int i=0; i < N_GRAN_PREMI; i++) {
        cout<<x->punti[i]<<endl;
    }
    cout<<endl;
    cout<<x->media<<endl;
}

/**
 * Togli p punti dall'ultimo piazzamento del pilota x
 * OPZIONALE: per chi ha diritto alla riduzione
 */
void retrocedi(Pilota_t *s, float punti) {

    int punteggio_totale=0;
    for (int i=0; i < s->numero_gp; i++){
        punteggio_totale +=s->punti[i];
    }
    punteggio_totale = punteggio_totale - punti;

}

/**
 * Restituisce il Pilota campione del mondo (quello con più punti)
 * OPZIONALE: per chi ha diritto alla riduzione
 */
Pilota_t* campione_del_mondo(Pilota_t pilots[], int dim) {

}

/**
 * Restituisce il nome della scuderia che ha fatto più punti
 * BONUS: per chi ha diritto alla riduzione
 */
string scuderia_campione(Pilota_t pilots[], int dim);

