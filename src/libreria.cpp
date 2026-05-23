#include <iostream>
#include "../inc/libreria_tipi.h"


/**
* Calcola la media di km di compiere in questa gara
 */
void lunghezza_media(Gara_Tappe_t &x) {

    //messo un float in caso un valore fosse con la virgola
    float somma = 0, media;
    int tengoConto = 0;
    for (int i = 0; i<N_MASSIMO_TAPPE; i++) {
        somma += x.tappe[i];
        tengoConto++;
    }
    //fatto casting per prevenzione
    media = somma/(float)tengoConto;
    x.lunghezza_media_tappe = media;
}

/**
 * Aggiunge il p kilometri all'elenco di un cadavedere x se ci sono posti liberi e altrimenti restituisce false
 */
bool aggiungi_tappa(Gara_Tappe_t &x, float p) {
    bool aggiuntaPossibile = false;
    for (int i = 0; i<N_MASSIMO_TAPPE; i++) {
        if (x.tappe[i] == -1) {
            aggiuntaPossibile = true;
            x.tappe[i] = p;
            return aggiuntaPossibile;
        }
    }
    return aggiuntaPossibile;
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
    cout<<"nome della gara: "<<x->nome<<endl;
    cout<<"edizione numero: "<<x->anno<<endl;
    cout<<"numero di tappe: "<<x->num_tappe<<endl;
    for (int i = 0; i<N_MASSIMO_TAPPE; i++) {
        if (x->tappe[i] != -1) {
            cout<<"tappa numero: "<<i<<" lunghezza (km): "<<x->tappe[i]<<endl;
        }
    }
    cout<<"media dei kilometri: "<<x->lunghezza_media_tappe<<endl;
}

/**
 * Togli x km dall'ultima tappa
 * OPZIONALE: per chi ha diritto alla riduzione
 */
void trasferimento(Gara_Tappe_t *s, float km) {
    int indiceUltimaGara;
    for (int i = 0; i<N_MASSIMO_TAPPE; i++) {
        if (s->tappe[i] != -1) {
            indiceUltimaGara = i;
        }
    }
    //se negativo tolgo km al precedente
    for (int i = indiceUltimaGara; i>=0; i--) {
        if (km != 0) {
            if (s->tappe[i] < km) {
                km -= s->tappe[i];
                s->tappe[i] = 0;
            }else if (s->tappe[i] > km) {
                s->tappe[i] -= km;
                km = 0;
            }else if (s->tappe[i] == km) {
                km = 0;
                s->tappe[i] = 0;
            }
        }
    }
}

/**
 * Restituisce la gara più lunga
 * OPZIONALE: per chi ha diritto alla riduzione
 */
Gara_Tappe_t* gara_piu_lunga(Gara_Tappe_t gare[], int dim);

/**
 * Restituisce il nome della gara che risulta più lunga in km dalla sua prima edizione ad ora
 * BONUS: per TUTTI
 */
string gare_storica_piu_lunga(Gara_Tappe_t gare[], int dim);