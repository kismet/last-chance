#include "../inc/libreria.h"
#include "../inc/libreria_tipi.h"
#include <iostream>
/**
* Calcola la media di punteggi
 */
void calcola_media(Pilota_t &x) {
    int sum;
    for (int i : x.punti) {
        sum = sum + i;
    }
    x.media = sum / x.numero_gp;
}

/**
 * Aggiunge il p punti al pilota x, se ci sono posti liberi e altrimenti restituisce false
 */
bool aggiungi_granpremio(Pilota_t &x, int p) {
    for (int i = 0; i < x.numero_gp; i++) {
        if (x.punti[i] < 0) {
            x.punti[i] = p;
            return true;
        }
    }
    return false;
}

/**
 * Inizializza un pilota, dandogli un nome n e una scuderia s
 */
void crea_pilota(Pilota_t &x, string n, string s) {
    int const numGP = 22;
    x.nome = n;
    x.scuderia = s;
    for (int i = 0; i < numGP; i++) {
        x.punti[i] = -1;
    }
}

/**
 * Stampa tutte le informazioni del pilota x: nome, cognome, numero di gran premi e punteggio per ogni gran premio
 * e infine la media
 */
void stampa_pilota(Pilota_t *x) {
    std::cout << x->nome << "\n";
    std::cout << x->cognome << "\n";
    std::cout << x->numero_gp << "\n";
    for (int i : x->punti) {
        std::cout << i << "\n";
    }
    std::cout << x->media << "\n";
}

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

