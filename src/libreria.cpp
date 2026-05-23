// Autore: Esposito Lorenzo
// Data:   2026/05/23
// Classe: 3CI
// Fila:   D

#include <iostream>
#include <ostream>
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

/**
 * Inizializza una gara a tappe di nome n ed edizione e
 */
void crea_gara(Gara_Tappe_t &x, string n, int e) {
    x.nome = n;
    x.anno = e;
}

/**
 * Stampa tutte le informazioni della gara a tappe x: nome, edizione, numero di tappe,
 * lunghezza di ogni tappa,  e infine la media
 */
void stampa_gara(Gara_Tappe_t *x) {
    cout << x->nome << ", ";
    cout << x-> anno << ", ";
    cout << x->num_tappe << ", ";
    for (int i = 0; i < x->num_tappe; i++) {
        cout << "tappa " << i+1 << ": " << x->tappe[i] << ", ";
    }
    lunghezza_media(*x);
    cout << x->lunghezza_media_tappe << endl;
}

/**
 * Togli x km dall'ultima tappa, se il valore diventa negativo la tappa viene eliminata
 * OPZIONALE: per chi ha diritto alla riduzione
 */
void trasferimento(Gara_Tappe_t *s, float km) {
    if (s->num_tappe != 0) {
        if (s->tappe[s->num_tappe-1] <= km) {
            s->tappe[s->num_tappe-1] = 0;
            s->num_tappe--;
        }
        else {
            s->tappe[s->num_tappe-1] -= km;
        }
    }
}

/**
 * Restituisce la gara più lunga
 * OPZIONALE: per chi ha diritto alla riduzione
 */
Gara_Tappe_t* gara_piu_lunga(Gara_Tappe_t gare[], int dim) {
    for (int i = 0; i < dim; i++) {
        lunghezza_media(gare[i]);
    }

    Gara_Tappe_t* piu_lunga = &gare[0];

    for (int i = 1; i < dim; i++) {
        if (gare[i].lunghezza_media_tappe*gare[i].num_tappe > piu_lunga->lunghezza_media_tappe*piu_lunga->num_tappe) {
            piu_lunga = &gare[i];
        }
    }

    return piu_lunga;
}