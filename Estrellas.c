#include "Estrellas.h"
#include "Estrella.h"
#include "Colision.h"
#include <stdlib.h>

struct EstrellasRep {
    Estrella * e;
    int n, maximo;
};

Estrellas EstrellasCrea(int maximo) {
    Estrellas es = malloc( sizeof (struct EstrellasRep));
    es->e = malloc( maximo * sizeof (Estrella));
    es->maximo = maximo;
    es->n = 0;
    return es;
}

void EstrellasLibera(Estrellas es) {
    int i = es->n - 1;
    while (i >= 0) {
        EstrellaLibera(es->e[i]);
        i--;
    }
    free(es->e);
    free(es);
}

void EstrellasDibuja(Estrellas es) {
    int i = es->n - 1;
    while (i >= 0) {
        EstrellaDibuja(es->e[i]);
        i--;
    }
}

void EstrellasInserta(Estrellas es, Imagen i, int x, int y, int w, int h) {
    if (es->n < es->maximo) {
        es->e[es->n] = EstrellaCrea(i, x, y, w, h);
        es->n++;
    }
}

int EstrellasColision(Estrellas es, int x, int y, int w, int h) {
    int contador = 0;
    for (int i = 0; i < es->n;) {
        if ( Colision (EstrellaX(es->e[i]), EstrellaY(es->e[i]), EstrellaW(es->e[i]), EstrellaH(es->e[i]), x, y, w, h)) {
            EstrellaLibera(es->e[i]);
            es->e[i] = es->e[es->n - 1];
            es->n--;
            contador++;
        } else {
            i++;
        }
    }
    return contador;
}
