//
// Created by stefy on 22/05/2026.
//

// Autore: Esposito Lorenzo
// Data:   2026/05/23
// Classe: 3CI
// Fila:   D

#ifndef LAST_CHANCE_LIBRERIA_H
#include "libreria_tipi.h"

/**
 * Calcola la media di km di compiere in questa gara
 */
void lunghezza_media(Gara_Tappe_t &x);

/**
 * Aggiunge il p kilometri all'elenco di un cadavedere x se ci sono posti liberi e altrimenti restituisce false
 */
bool aggiungi_tappa(Gara_Tappe_t &x, float p);

/**
 * Inizializza una gara a tappe di nome n ed edizione e
 */
void crea_gara(Gara_Tappe_t &x, string n, int e);

/**
 * Stampa tutte le informazioni della gara a tappe x: nome, edizione, numero di tappe,
 * lunghezza di ogni tappa,  e infine la media
 */
void stampa_gara(Gara_Tappe_t *x);

/**
 * Togli x km dall'ultima tappa
 * OPZIONALE: per chi ha diritto alla riduzione
 */
void trasferimento(Gara_Tappe_t *s, float km);

/**
 * Restituisce la gara più lunga (relativo a km di tutte le edizioni)
 * OPZIONALE: per chi ha diritto alla riduzione
 */
Gara_Tappe_t* gara_piu_lunga(Gara_Tappe_t gare[], int dim);

/**
 * Restituisce il nome della gara che risulta più lunga in km dalla sua prima edizione ad ora
 * BONUS: per TUTTI
 */
string gare_storica_piu_lunga(Gara_Tappe_t gare[], int dim);


#define LAST_CHANCE_LIBRERIA_H

#endif //LAST_CHANCE_LIBRERIA_H