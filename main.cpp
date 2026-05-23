#include <iostream>
#include <string>
#include "inc/libreria_tipi.h"
#include "inc/libreria.h"

using namespace std;

int main() {
    // --- TEST 1: crea_gara ---
    cout << "\n[TEST 1] Inizializzazione delle gare con crea_gara()" << endl;
    Gara_Tappe_t g1, g2, g3, g4;
    
    crea_gara(g1, "Giro d'Italia", 109);
    crea_gara(g2, "Tour de France", 113);
    crea_gara(g3, "Vuelta a Espana", 79);
    crea_gara(g4, "Giro d'Italia", 108); // Seconda edizione dello stesso evento per test storico

    cout << "Rilevate/Inizializzate le seguenti gare:" << endl;
    cout << "- " << g1.nome << " (Edizione " << g1.anno << ")" << endl;
    cout << "- " << g2.nome << " (Edizione " << g2.anno << ")" << endl;
    cout << "- " << g3.nome << " (Edizione " << g3.anno << ")" << endl;
    cout << "- " << g4.nome << " (Edizione " << g4.anno << ")" << endl;

    // --- TEST 2: aggiungi_tappa ---
    cout << "\n[TEST 2] Aggiunta di tappe con aggiungi_tappa()" << endl;
    
    // Gara 1: Giro d'Italia Ed. 109
    cout << "Aggiunta tappe a " << g1.nome << " (Ed. " << g1.anno << "):" << endl;
    if (aggiungi_tappa(g1, 150.5f)) cout << "  Tappa 1 (150.5 km) aggiunta." << endl;
    if (aggiungi_tappa(g1, 180.2f)) cout << "  Tappa 2 (180.2 km) aggiunta." << endl;
    if (aggiungi_tappa(g1, 35.0f))  cout << "  Tappa 3 (35.0 km) aggiunta." << endl;

    // Gara 2: Tour de France Ed. 113
    cout << "Aggiunta tappe a " << g2.nome << " (Ed. " << g2.anno << "):" << endl;
    if (aggiungi_tappa(g2, 200.0f)) cout << "  Tappa 1 (200.0 km) aggiunta." << endl;
    if (aggiungi_tappa(g2, 220.5f)) cout << "  Tappa 2 (220.5 km) aggiunta." << endl;

    // Gara 3: Vuelta a Espana Ed. 79
    cout << "Aggiunta tappe a " << g3.nome << " (Ed. " << g3.anno << "):" << endl;
    if (aggiungi_tappa(g3, 140.0f)) cout << "  Tappa 1 (140.0 km) aggiunta." << endl;
    if (aggiungi_tappa(g3, 165.8f)) cout << "  Tappa 2 (165.8 km) aggiunta." << endl;

    // Gara 4: Giro d'Italia Ed. 108 (storica)
    cout << "Aggiunta tappe a " << g4.nome << " (Ed. " << g4.anno << "):" << endl;
    if (aggiungi_tappa(g4, 190.0f)) cout << "  Tappa 1 (190.0 km) aggiunta." << endl;
    if (aggiungi_tappa(g4, 210.0f)) cout << "  Tappa 2 (210.0 km) aggiunta." << endl;

    // --- TEST 3: lunghezza_media ---
    cout << "\n[TEST 3] Calcolo della lunghezza media con lunghezza_media()" << endl;
    lunghezza_media(g1);
    lunghezza_media(g2);
    lunghezza_media(g3);
    lunghezza_media(g4);
    cout << "Lunghezze medie calcolate ed aggiornate correttamente." << endl;

    Gara_Tappe_t *pg1 = &g1;
    Gara_Tappe_t *pg2 = &g2;

    // --- TEST 4: stampa_gara ---
    cout << "\n[TEST 4] Stampa dei dettagli della gara con stampa_gara()" << endl;
    cout << "--------------------------------------------------" << endl;
    stampa_gara(pg1);
    cout << "--------------------------------------------------" << endl;
    stampa_gara(pg2);
    cout << "--------------------------------------------------" << endl;

    // --- TEST 5: gara_piu_lunga ---
    cout << "\n[TEST 5] Trovare la gara piu' lunga con gara_piu_lunga()" << endl;
    cout << "--------------------------------------------------" << endl;
    Gara_Tappe_t gare[4] = {g1, g2, g3, g4};
    Gara_Tappe_t *pGaraPiuLunga = gara_piu_lunga( gare, 4);
    cout << "La gara piu' lunga e': " << pGaraPiuLunga->nome <<endl;

    return 0;
}