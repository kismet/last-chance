//
// Created by stefy on 22/05/2026.
//

// Autore: Ciardelli Alessandro
// Data:   2026/05/23
// Classe: 3CI
// Fila:   B

#ifndef LAST_CHANCE_LIBRERIA_H
#include "libreria_tipi.h"

/**
 * Calcola la media dei costi dei libri
 */
void costo_medio_libri(Libri_t &x);

/**
 * Aggiunge il p prezzo all'elenco dei libri x se ci sono posti liberi e altrimenti restituisce false
 */
bool aggiungi_costo_libro(Libri_t &x, float p);

/**
 * Inizializza un lista libri indicando classe e indirizzo
 */
void crea_lista_libri(Libri_t &x, string c, string i);

/**
 * Stampa tutte le informazioni della lista dei libri  x: classe, indirizzo, numero di libri impiegati, il costo di ogni
 * libro e infine la media
 */
void stampa_lista_libri(Libri_t *x);

/**
 * Togli x euro dal prezzo dall'ultimo libro in elenco
 * OPZIONALE: per chi ha diritto alla riduzione
 */
void sconto(Libri_t *s, float punti);

/**
 * Restituisce il costo del libro più economico
 * OPZIONALE: per chi ha diritto alla riduzione
 */
Libri_t* libro_economico(Libri_t elenchi[], int dim);

/**
 * Indirizzo più impegnativo per le famiglie, restituisce il nome dell'indirizzo che il totale dei costi dei
 * libri maggiore
 * BONUS: per TUTTI
 */
string scuderia_campione(Libri_t elenchi[], int dim);


#define LAST_CHANCE_LIBRERIA_H

#endif //LAST_CHANCE_LIBRERIA_H