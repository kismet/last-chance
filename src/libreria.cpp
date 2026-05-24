// Autore: Capezzuoli Leonardo
// Data:   2026/05/23
// Classe: 3CI
// Fila:   A
#include "../inc/libreria.h"
#include "../inc/libreria_tipi.h"
#include <iostream>
#include <vector>
/**
* Calcola la media di punteggi
 */
void calcola_media(Pilota_t &x) {
    int sum = 0;
    //LENZI mai visto a scuola...
    for (int i : x.punti) {
        if (i != -1) {
            sum = sum + i;
        }
    }
    //LENZI non funziona nel caso x.numero_gp == 0
    x.media = sum / x.numero_gp;
}

/**
 * Aggiunge il p punti al pilota x, se ci sono posti liberi e altrimenti restituisce false
 */
bool aggiungi_granpremio(Pilota_t &x, int p) {
    //LENZI sbagliato c'era da usare la costante N_GRAN_PREMI
    int grandezza = 22;
    for (int i = 0; i < grandezza; i++) {
        if (x.punti[i] == -1) {
            x.punti[i] = p;
            x.numero_gp = x.numero_gp + 1;
            calcola_media(x);
            return true;
        }
    }
    //LENZI in questo caso non serve ricalcolare la media
    calcola_media(x);
    return false;
}

/**
 * Inizializza un pilota, dandogli un nome n e una scuderia s
 */
void crea_pilota(Pilota_t &x, string n, string s) {
    int const numGP = 22;
    x.nome = n;
    x.scuderia = s;
    for (int i = 0; i < numGP; i++) {
        //LENZI ottima idea inizializzarli a valore "nullo" ma non necessario considerato
        //che hai il campo numero_gp
        x.punti[i] = -1;
    }
    x.media = 0;
    x.numero_gp = 0;
}

/**
 * Stampa tutte le informazioni del pilota x: nome, cognome, numero di gran premi e punteggio per ogni gran premio
 * e infine la media
 */
void stampa_pilota(Pilota_t *x) {
    //LENZI non stampi la scuderia
    std::cout << x->nome << "\n";
    std::cout << x->numero_gp << "\n";
    //LENZI mettere una cout<<"sto stampando i punti:"
    for (int i : x->punti) {
        if (i != -1) {
            std::cout << i << ' ';
        }
    }
    std::cout << "\n";
    std::cout << x->media << "\n";
}

/**
 * Togli p punti dall'ultimo piazzamento del pilota x
 * OPZIONALE: per chi ha diritto alla riduzione
 */
void retrocedi(Pilota_t *s, float punti) {
    //LENZI letto male il testo non vanno tolti i punti da TUTTI i gp
    //ma solo dall'ultimo...
    //LENZI Errore quando numero_gp == N_GRAN_PREMI perchè s->punti[i] va fuori dall'array
    for (int i = s->numero_gp; i > 0; i--) {
        s->punti[i] = s->punti[i] - punti -1;
    }
}

/**
 * Restituisce il Pilota campione del mondo (quello con più punti)
 * OPZIONALE: per chi ha diritto alla riduzione
 */
Pilota_t* campione_del_mondo(Pilota_t pilots[], int const dim) {
    int puntiTot[dim];
    int ricordaIndice = 0;
    for (int i = 0; i < dim; i++) {
        //LENZI errore manca inizializzazione puntiTot[i] = 0;
        //LENZI sbagliato questo indice j non si deve fermare a dim ma
        //j < pilots[i].numero_gp
        for (int j = 0; j < dim; j++) {
            if (pilots[i].punti[j] != -1) {
                puntiTot[i] = puntiTot[i] + pilots[i].punti[j];
            }
        }
    }
    for (int i = 0; i < dim; i++) {
        //GRAVE non si trova così il massimo...
        for (int j = 0; j < dim; j++) {
            if (puntiTot[i] > puntiTot[j]) {
                ricordaIndice = j;
            }
        }
    }
    return &pilots[ricordaIndice];
}

/**
 * Restituisce il nome della scuderia che ha fatto più punti
 * BONUS: per chi ha diritto alla riduzione
 */
string scuderia_campione(Pilota_t pilots[], int dim) {
    vector<string> arrScuderie;
    for (int i = 0; i < dim; i++) {
        arrScuderie.push_back(pilots[i].scuderia);
    }
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (arrScuderie[i + 1] == arrScuderie[j]) {
                //LENZI idea okay ma non funziona non tornano gli indici perchè arrScuderia diminuisce di un elemento
                arrScuderie[i].erase();
            }
        }
    }
    int puntiScuderia[arrScuderie.size()];
    //LENZI sbagliato di nuovo limite per j deve essere j < arrScuderie.size()
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (pilots[i].scuderia == arrScuderie[j]) {
                for (int k = 0; k < dim; k++) {
                    puntiScuderia[i] = puntiScuderia[i] + pilots[i].punti[k];
                }
            }
        }
    }
    //LENZI manca la return
}

