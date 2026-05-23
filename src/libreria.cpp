//Autore: Gargiulo Michele
// Data:  2026/05/23
// Classe: 3CI
// Fila: A
#include "../inc/libreria.h"
#include <iostream>
using namespace std;
void calcola_media(Pilota_t &x)
{
    if (x.numero_gp == 0) {
        x.media = 0.0;
        return;
    }
    int somma=0;
    for (int i =0; i<x.numero_gp; i++) {
        somma += x.punti[i];
    }
    x.media = (somma) / x.numero_gp;
}


bool aggiungi_granpremio(Pilota_t &x, int p)
{
    if (x.numero_gp>= N_GRAN_PREMI) {
        return false;
    }
    x.punti[x.numero_gp] = p;
    x.numero_gp++;
    calcola_media(x);
    return true;
}


void crea_pilota(Pilota_t &x, string n, string s)
{
    x.cognome= n;
    x.scuderia= s;
    x.numero_gp= 0;
    x.media = 0.0;
    for ( int i =0; i<N_GRAN_PREMI; i++) {
        x.punti[i] = 0;
    }
}

/**
 * Stampa tutte le informazioni del pilota x: nome, cognome, numero di gran premi e punteggio per ogni gran premio
 * e infine la media
 */
void stampa_pilota(Pilota_t *x)
{
    cout<< "pilota: "<<x->cognome<<endl;
    cout<< "scuderia: "<<x->scuderia<<endl;
    cout<< "Gp svolti: "<<x->numero_gp<<endl;
    for (int i =0; i<x->numero_gp; i++) {
        cout<<"gp "<<(i+1)<<": "<<x->punti[i]<<endl;
    }
    cout<<"media: "<<x->media<<endl;
}

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

