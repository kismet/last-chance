// Autore: salatti dario
// Data:   2026/05/23
// Classe: 3CI
// Fila:   B

#include "../inc/libreria_tipi.h"
#include "../inc/libreria.h"
#include "iostream"

/**
* Calcola la media di punteggi
 */
void calcola_media(Pilota_t &x);

int s = 0;

for (int i = 0; i < x.n_granpremi; i++) {
    s = s + x.punteggi[i];
}
x.media = s / x.n_granpremi;

/**
 * Aggiunge il p punti al pilota x, se ci sono posti liberi e altrimenti restituisce false
 */
bool aggiungi_granpremio(Pilota_t &x, int p);

/**
 * Inizializza un pilota, dandogli un nome n e una scuderia s
 */
void crea_pilota(Pilota_t &x, string n, string s);
{
    x.nome = n
    x.scuderia = s

    x.n_granpremi = 0
    x.media = 0;
}

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
 * Restituisce il nome della scuderia che ha fatto più punti
 * BONUS: per chi ha diritto alla riduzione
 */
string scuderia_campione(Pilota_t pilots[], int dim);

