#ifndef __ENEMIGO_H
#define __ENEMIGO_H
#include "Pantalla.h"

typedef struct EnemigoRep * Enemigo;
Enemigo EnemigoCrea(Imagen i, int x, int y, int h, int w, int vx, int vy);
void EnemigoLibera(Enemigo e);
void EnemigoMueve(Enemigo e);
void EnemigoDibuja(Enemigo e);
int EnemigoX(Enemigo e);
int EnemigoY(Enemigo e);
int EnemigoW(Enemigo e);
int EnemigoH(Enemigo e);

#endif // __ENEMIGO_H
