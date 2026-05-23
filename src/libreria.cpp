#include "../inc/libreria.h"
#include "../inc/libreria_tipi.h"
#include <iostream>
#include <vector>
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
void retrocedi(Pilota_t *s, float punti) {
    for (int i = s->numero_gp; i > 0; i--) {
        s->punti[i] = -1;
    }
}

/**
 * Restituisce il Pilota campione del mondo (quello con più punti)
 * OPZIONALE: per chi ha diritto alla riduzione
 */
Pilota_t* campione_del_mondo(Pilota_t pilots[], int dim) {
    int sum = 0;
    int tmp = 0;
    int numeroCampione = 0;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < pilots[i].numero_gp; j++) {
            tmp = tmp + pilots[i].punti[j];
        }
        if (tmp > sum) {
            tmp = sum;
            numeroCampione = i;
        }
    }
    return &pilots[numeroCampione];
}

/**
 * Restituisce il nome della scuderia che ha fatto più punti
 * BONUS: per chi ha diritto alla riduzione
 */
string scuderia_campione(Pilota_t pilots[], int dim) {
    vector<string> arrScuderie;
    for (int i = 0; i < dim; i++) {
        arrScuderie.push_back(pilots[i].scuderia);
    }
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (arrScuderie[i + 1] == arrScuderie[j]) {
                arrScuderie[i].erase();
            }
        }
    }
    int puntiScuderia[arrScuderie.size()];
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (pilots[i].scuderia == arrScuderie[j]) {
                for (int k = 0; k < dim; k++) {
                    puntiScuderia[i] = puntiScuderia[i] + pilots[i].punti[k];
                }
            }
        }
    }
}

