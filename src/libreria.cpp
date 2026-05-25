//
// Created by stefy on 22/05/2026.
//
// Autore: Tosi Gianmarcp
// Data:   2026/05/23
// Classe: 3CI
// Fila:   B
using namespace std;
#include <iostream>
#include "../inc/libreria.h"
#include "../inc/libreria_tipi.h"

/**
 * Calcola la media dei costi dei libri
 */
void costo_medio_libri(Libri_t &x) {
    float somma=0;
    for (int i=0; i<x.num_libri; i++) {
        somma+=x.costo[i];
    }
    //LENZI non funziona quando x.num_libri == 0
    x.media=somma/x.num_libri;
}


/**
 * Aggiunge il p prezzo all'elenco dei libri x se ci sono posti liberi e altrimenti restituisce false
 */
bool aggiungi_costo_libro(Libri_t &x, float p) {
    int cont=0;
    int salvaI;
    if (N_MATERIE==x.num_libri) return false;
    //LENZI non funziona il valore iniziale x.num_libri è 0 e considera il primo vuoto
    x.costo[x.num_libri-1]=p;
    x.num_libri++;
    costo_medio_libri(x);
        return true;
}

/**
 * Inizializza un lista libri indicando classe e indirizzo
 */
void crea_lista_libri(Libri_t &x, string c, string i) {

    x.anno=c;

    x.indirizzo=i;
    x.media=0;
    x.num_libri=0;

}

/**
 * Stampa tutte le informazioni della lista dei libri  x: classe, indirizzo, numero di libri impiegati, il costo di ogni
 * libro e infine la media
 */
void stampa_lista_libri(Libri_t *x) {
    cout<<"classe: "<< x->anno << endl;
    cout<<"indirizzo: "<< x->indirizzo << endl;
    cout<<"numero libri: "<< x->num_libri << endl;
    for (int i=0; i<x->num_libri; i++) {
        //LENZI perchè x->costo[i-1] ? quando i=0 il valore è -1 che non è un indice valido, colpa di aggiungi_libri
        cout<<"costo libri: "<< x->costo[i-1] << endl;
    }
    cout<<"media: "<< x->media << endl;

}

/**
 * Togli x euro dal prezzo dall'ultimo libro in elenco
 * OPZIONALE: per chi ha diritto alla riduzione
 */
void sconto(Libri_t *s, float punti) {

    if (s->num_libri==0) {
        //LENZI non si usano le cout nelle funzioni
        cout<<"non ci sono libri in elenco"<< endl;
    }else if (s->costo[s->num_libri-1]>=punti){
        s->costo[s->num_libri-1]-=punti;
    }
    else {
        s->costo[s->num_libri-1]=0;
    }
    costo_medio_libri(*s);
}

/**
 * Restituisce il costo del libro più economico
 * OPZIONALE: per chi ha diritto alla riduzione
 */
float libro_economico(Libri_t elenchi[], int dim) {
    //LENZI non si può cambiare la firma della funzione (il prototipo)
    double economico=0;
    for (int i=0; i<dim; i++) {
        for (int j=0; j<elenchi[i].num_libri; j++) {
            if (economico<elenchi[i].costo[j]) {
                economico=elenchi[i].costo[j];
            }
        }

    }
    return economico;
}

/**
 * Indirizzo più impegnativo per le famiglie, restituisce il nome dell'indirizzo che il totale dei costi dei
 * libri maggiore
 * BONUS: per TUTTI
 */
string scuderia_campione(Libri_t elenchi[], int dim);

