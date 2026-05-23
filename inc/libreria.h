//
// Created by stefy on 22/05/2026.
//

#ifndef LAST_CHANCE_LIBRERIA_H
#include "libreria_tipi.h"

/**
 * Calcola la media in km delle varie tratte
 */
void tratta_media(Viaggio_t &x);

/**
 * Aggiunge il km kilometri al viaggio x, se ci sono posti liberi e altrimenti restituisce false
 */
bool aggiungi_tratta(Viaggio_t &x, float km);

/**
 * Inizializza un pilota, dandogli una partenza p e una destinazione d
 */
void crea_viaggio(Viaggio_t &x, string p, string d);

/**
 * Stampa tutte le informazioni del viaggio x: partenza, destinazione, numero di tratte, km per ogni tratta
 * e infine la distanza media di ogni tratta
 */
void stampa_viaggio(Viaggio_t &x);

/**
 * Togli km kilometri dall'ultimo tratta
 * OPZIONALE: per chi ha diritto alla riduzione
 */
void scorciatoia(Viaggio_t *s, float punti);

/**
 * Restituisce il Viaggio più lungo in termini di kilometri
 * OPZIONALE: per chi ha diritto alla riduzione
 */
Viaggio_t* viaggio_lungo(Viaggio_t viaggi[], int dim);

/**
 * Restituisce la destinazione che ha il maggior numero di km percorsi che la raggiungono
 * BONUS: per chi ha diritto alla riduzione
 */
string destinazione_principale(Viaggio_t viaggi[], int dim);


#define LAST_CHANCE_LIBRERIA_H

#endif //LAST_CHANCE_LIBRERIA_H