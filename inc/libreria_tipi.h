//
// Created by stefy on 22/05/2026.
//

#ifndef LAST_CHANCE_LIBRERIA_TIPI_H
#define LAST_CHANCE_LIBRERIA_TIPI_H
#include <cstdint>
#include <string>

using namespace std;

uint16_t const N_MASSIMO_TAPPE = 100;

typedef struct Gara_Tappe {
    string nome; //nome della gara. Es.: Giro d'Italia, Tour de France, etc.
    int anno; //edizione di riferimento: 30°, 55°, etc.
    float tappe[N_MASSIMO_TAPPE] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                                    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                                    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                                    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                                    -1, -1, -1, -1, -1, -1}; //i km per ogni tappa
    int num_tappe; //il numero di tappe in archivio
    float lunghezza_media_tappe;  //media della lunghezza delle tappe
} Gara_Tappe_t;

#endif //LAST_CHANCE_LIBRERIA_TIPI_H