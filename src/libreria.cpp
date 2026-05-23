//
// Created by stefy on 22/05/2026.
//

#ifndef LAST_CHANCE_LIBRERIA_H
#include "../inc/libreria_tipi.h"
#include "../inc/libreria.h"

#include "../inc/libreria_tipi.h"

void costo_medio_libri(Libri_t &x) {
    if (x.num_libri == 0) {
        x.media=0.0;
    }
}

bool aggiungi_costo_libro(Libri_t &x, float p) {
    if (x.num_libri<N_MATERIE) {
        x.costo[x.num_libri]=p;
        x.num_libri++;
        return true;
    }
}

void crea_lista_libri(Libri_t &x, string c, string i) {
    x.anno=c;
    x.indirizzo=i;
    x.num_libri++;
    x.media=0.0;
}

void stampa_lista_libri(Libri_t *x) {
    if (x==nullptr) {
        return;
    }
}

void sconto(Libri_t *s, float punti) {
    if (s!=nullptr and s->num_libri>0) {
        s->costo[s->num_libri-1]=punti;

        if (s->costo[s->num_libri-1]<0) {
            s->costo[s->num_libri-1]=0;
        }
    }
}

Libri_t* libro_economico(Libri_t elenchi[], int dim) {
    if (dim<=0) {
        return nullptr;
    }
    Libri_t* lista_col_minimo=nullptr;
    float minimo=-1.0;
    bool trovato=false;

    for (int i=0;i<dim;i++) {
        for (int j=0; j<elenchi[i].num_libri; j++) {
            if (!trovato or elenchi[i].costo[j]<minimo) {
                minimo=elenchi[i].costo[j];
                lista_col_minimo=&elenchi[i];
                trovato=true;
            }
        }
    }

    return lista_col_minimo;
}

string scuderia_campione(Libri_t elenchi[], int dim) {
    if (dim<=0) {
        return "";
    }
}


#define LAST_CHANCE_LIBRERIA_H

#endif //LAST_CHANCE_LIBRERIA_H