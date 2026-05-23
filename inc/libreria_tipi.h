// Autore: Capezzuoli Leonardo
// Data:   2026/05/23
// Classe: 3CI
// Fila:   A
//
// Created by stefy on 22/05/2026.
//

#ifndef LAST_CHANCE_LIBRERIA_TIPI_H
#define LAST_CHANCE_LIBRERIA_TIPI_H
#include <cstdint>
#include <string>

using namespace std;

uint16_t const N_GRAN_PREMI = 22;

typedef struct Pilota {
    string nome;
    string scuderia; //nome della scuderia a cui appartiene
    int punti[N_GRAN_PREMI]; //i punti presi in ogni gran premio
    int numero_gp; //il numero di gran premi svolti fino a oggi
    float media;  //media dei punti fatti a ogni gran premio
} Pilota_t;

#endif //LAST_CHANCE_LIBRERIA_TIPI_H