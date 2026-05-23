//
// Created by stefy on 22/05/2026.
//
#ifndef LIBRERIA_H
#define LIBRERIA_H

#ifndef LAST_CHANCE_LIBRERIA_H
#include "libreria_tipi.h"

/**
 * Calcola la media di punteggi
 */
void calcola_media(Pilota_t &x);
/**
 * Aggiunge il p punti al pilota x, se ci sono posti liberi e altrimenti restituisce false
 */
bool aggiungi_granpremio(Pilota_t &x, int p);

/**
 * Inizializza un pilota, dandogli un nome n e una scuderia s
 */
void crea_pilota(Pilota_t &x, string n, string s);


/**
 * Stampa tutte le informazioni del pilota x: nome, cognome, numero di gran premi e punteggio per ogni gran premio
 * e infine la media
 */
void stampa_pilota(Pilota_t *x);

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
 * Restituisce il nome della scuderia che ha fatto più punti (contando i punti dei piloti di quella scuderia)
 * BONUS: per chi ha diritto alla riduzione
 */
string scuderia_campione(Pilota_t pilots[], int dim);


#define LAST_CHANCE_LIBRERIA_H

#endif //LAST_CHANCE_LIBRERIA_H
#endif // LIBRERIA_H
