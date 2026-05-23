// Autore: [Clipa] [Amos]
// Data:   2026/05/23
// Classe: 3CI
// Fila:   [A]


/**
* Calcola la media di punteggi
 */
void calcola_media(Pilota_t &x) {
    int somma=0;

    for (int i = 0; i < x.numero_gp; i++) {
        somma += x.punti[i];
    }

    if (x.numero_gp > 0) {
        x.media = somma/x.numero_gp;
    }
    else {
        x.media = 0;
    }

};

/**
 * Aggiunge il p punti al pilota x, se ci sono posti liberi e altrimenti restituisce false
 */
bool aggiungi_granpremio(Pilota_t &x, int p) {

    if (x.numero_gp >= N_GRAN_PREMI) {
        return false;
    }
    x.punti[x.numero_gp] = p;
    x.numero_gp++;

    return true;
};

/**
 * Inizializza un pilota, dandogli un nome n e una scuderia s
 */
void crea_pilota(Pilota_t &x, string n, string s) {

    x.cognome = n;
    x.scuderia = s;
    x.numero_gp = 0;
    x.media = 0;

};

/**
 * Stampa tutte le informazioni del pilota x: nome, cognome, numero di gran premi e punteggio per ogni gran premio
 * e infine la media
 */
void stampa_pilota(Pilota_t *x) {

    cout << "Nome: " << x.cognome << endl;
    cout << "Scuderia: " << x.scuderia << endl;
    cout << "Numero gp: " << x.numero_gp << endl;
    cout << "Punti: ";

    for (int i= 0; i < x.numero_gp; i++) {
        cout << x.punti[i] << " ";
    }
    cout << endl;

    cout << "Media: " << x.media << endl;

};

/**
 * Togli p punti dall'ultimo piazzamento del pilota x
 * OPZIONALE: per chi ha diritto alla riduzione
 */
void retrocedi(Pilota_t *s, float punti) {

    if (s->numero_gp > 0) {
        s->punti[s->numero_gp - 1] -= punti;

        if (s->punti[s->numero_gp - 1] < 0) {
            s->punti[s->numero_gp - 1] = 0;
        }
        calcola_media(*s);
    }

};

/**
 * Restituisce il Pilota campione del mondo (quello con più punti)
 * OPZIONALE: per chi ha diritto alla riduzione
 */
Pilota_t* campione_del_mondo(Pilota_t pilots[], int dim) {

    int indice = 0;
    int max = 0;

    for (int i = 0; i < dim; i++) {
        int somma = 0;

        for (int j = 0; j < pilots[i].numero_gp; j++) {
            somma += pilots[i].punti[j];
        }
        if (max < somma) {
            max = somma;
            indice = i;
        }
    }
    return &pilots[indice];

};

/**
 * Restituisce il nome della scuderia che ha fatto più punti
 * BONUS: per chi ha diritto alla riduzione
 */
string scuderia_campione(Pilota_t pilots[], int dim) {

    int maxPunti = 0;
    string migliore = "";

    for (int i = 0; i < dim; i++) {

        int total = 0;

        for (int j = 0; j < dim; j++) {
            if (pilots[i].scuderia == pilots[j].scuderia) {

                for (int k = 0; k < pilots[j].numero_gp; k++) {
                    total += pilots[j].punti[k];
                }
            }
        }
        if (total > maxPunti) {
            maxPunti = total;
            migliore = pilots[i].scuderia;
        }
    }
    return migliore;

};

