#ifndef __ESTRELLAS_H
#define __ESTRELLAS_H
#include "Pantalla.h"

typedef struct EstrellasRep * Estrellas;
Estrellas EstrellasCrea(int maximo);
void EstrellasLibera(Estrellas e);
void EstrellasDibuja(Estrellas e);
void EstrellasInserta(Estrellas e, Imagen i, int x, int y, int w, int h);
int EstrellasColision(Estrellas e, int x, int y, int w, int h);

#endif // __ESTRELLAS_H
