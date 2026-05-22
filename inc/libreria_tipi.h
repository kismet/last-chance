//
// Created by stefy on 22/05/2026.
//

#ifndef LAST_CHANCE_LIBRERIA_TIPI_H
#define LAST_CHANCE_LIBRERIA_TIPI_H
#include <cstdint>
#include <string>

using namespace std;

uint16_t const N_FERMATE_STOP = 22;

typedef struct Viaggio {
    string partenza; //luogo di partenza del viaggio
    string destinazione; //luogo di destinazioni del viaggio
    float tratte[N_FERMATE_STOP]; //i km percorsi a ogni tratta del percorso
    int numero_tratte; //il numero di tratte fatte fino a quel momento
    float media;  //medi dei km percorsi prima di fare una sosta
} Viaggio_t;

#endif //LAST_CHANCE_LIBRERIA_TIPI_H