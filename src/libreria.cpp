// Autore: [Zoppi] [Joele]
// Data: 2026/05/23
// Classe: 3CI
// Fila: Fila A]

#include <iostream>
#include "../inc/libreria.h"
/**
* Calcola la media di punteggi
 */
float calcola_media(Pilota_t &x) {
    //LENZI perchè hai cambiato la firma?
int somma=0;
float media =0;
    for (int i = 0; i < x;i++) {
        //LENZI che cosa è p?
        somma = somma+p;
        media = somma/i;

    };

};

/**
 * Aggiunge il p punti al pilota x, se ci sono posti liberi e altrimenti restituisce false
 */
bool aggiungi_granpremio(Pilota_t &x, int p) {
    //LENZI codice incompleto...
    if (x == ) {

        Pilota_t &x + p;

    }
    else {
        return false;
    }
};

/**
 * Inizializza un pilota, dandogli un nome n e una scuderia s
 */
void crea_pilota(Pilota_t &x, string n, string s) {
    //LENZI cosa volevi fare?
    Pilota_t p1, p2, p3;
    crea_pilota(p1, n, s);
    crea_pilota(p2, n, s);
    crea_pilota(p3, n, s);

};

/**
 * Stampa tutte le informazioni del pilota x: nome, cognome, numero di gran premi e punteggio per ogni gran premio
 * e infine la media
 */
void stampa_pilota(Pilota_t *x,p1,p2,p3) {
    //LENZI ma dovevi implementarle...
    stampa_pilota(p1);
    stampa_pilota(p2);
    stampa_pilota(p3);
    cout << endl;
};

/**
 * Togli p punti dall'ultimo piazzamento del pilota x
 * OPZIONALE: per chi ha diritto alla riduzione
 */
void retrocedi(Pilota_t *s, float punti) {


};

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

