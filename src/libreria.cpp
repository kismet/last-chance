#include "../inc/libreria.h"

#include <iostream>
#include "../inc/libreria_tipi.h"


/**
* Calcola la media di km di compiere in questa gara
 */
void lunghezza_media(Gara_Tappe_t &x) {

    //messo un float in caso un valore fosse con la virgola
    float somma = 0, media;
    int tengoConto = 0;
    //LENZI errore devi contare fino a x.num_tappe
    for (int i = 0; i<N_MASSIMO_TAPPE; i++) {
        somma += x.tappe[i];
        tengoConto++;
    }
    //fatto casting per prevenzione
    media = somma/(float)tengoConto;
    x.lunghezza_media_tappe = media;
    //LENZI non funziona se tengoConto = 0;
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
            x.num_tappe++;
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
    //LENZI andrebbe inizializzato x.num_tappe = 0
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
    //LENZI poteva essere utile calcolare la media prima
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
    //LENZI ? Il testo non lo chiede... Errore comprensione del testo
    //se negativo tolgo km al precedente
    for (int i = indiceUltimaGara; i>=0; i--) {
        if (km != 0) { //LENZI perchè? vanno tolti solo all'ultimo non a tutti
            if (s->tappe[i] < km) {
                km -= s->tappe[i]; //LENZI perchè?
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
Gara_Tappe_t* gara_piu_lunga(Gara_Tappe_t gare[], int dim) {
    int indiceGaraPiuLunga;
    long lunghezzaDaSuperare = 0;
    for (int i = 0; i<dim; i++) {
        long lunghezzaGara = calcoloLunghezzaTotaleGara(gare[i]);
        if (lunghezzaGara > lunghezzaDaSuperare) {
            indiceGaraPiuLunga = i;
            lunghezzaDaSuperare = lunghezzaGara;
        }
    }
    Gara_Tappe_t *pIndiceGaraPiuLunga = &gare[indiceGaraPiuLunga];
    return pIndiceGaraPiuLunga;
}

//funzione di supporto
long calcoloLunghezzaTotaleGara(Gara_Tappe_t g) {
    long lunghezza = 0;
    for (int i = 0; i<N_MASSIMO_TAPPE; i++) {
        if (g.tappe[i] != -1) {
            lunghezza += g.tappe[i];
        }
    }
    return lunghezza;
}

/**
 * Restituisce il nome della gara che risulta più lunga in km dalla sua prima edizione ad ora
 * BONUS: per TUTTI
 */
string gare_storica_piu_lunga(Gara_Tappe_t gare[], int dim) {
    //LENZI interpretazione sbagliata della domanda, dovevi considerare la somma di tutte le edizioni
    //Es.: La vuelta lunga 100km ma con 20 edizioni è più lunga della coppa del mondo di 500km perchè
    //sono 2000km vs 500km
    Gara_Tappe_t *pGaraPiuLunga = gara_piu_lunga(gare, dim);
    return pGaraPiuLunga->nome;
}