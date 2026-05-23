//
// Created by stefy on 22/05/2026.
//

// Autore: Ciardelli Alessandro
// Data:   2026/05/23
// Classe: 3CI
// Fila:   B

#ifndef LAST_CHANCE_LIBRERIA_TIPI_H
#define LAST_CHANCE_LIBRERIA_TIPI_H
#include <cstdint>
#include <string>

using namespace std;

uint16_t const N_MATERIE = 10;

typedef struct Libri {
    string anno; //anno delle superiori: prima, quinta, seconda, etc.
    string indirizzo; //nome dell'indirizzo scienze applicate, informatica, etc.
    float costo[N_MATERIE]; //il costo di ogni singolo libro necessario per questa classe
    int num_libri; //il numero di libri in quella classe
    float media;  //media del costo dei libri per questa classe
} Libri_t;

#endif //LAST_CHANCE_LIBRERIA_TIPI_H