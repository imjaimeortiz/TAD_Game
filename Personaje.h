#ifndef __PERSONAJE_H
#define __PERSONAJE_H
#include "Pantalla.h"

typedef struct PersonajeRep * Personaje;
Personaje PersonajeCrea(Imagen i, int x, int y, int h, int w);
void PersonajeLibera(Personaje p);
void PersonajeMueve(Personaje p);
void PersonajeDibuja(Personaje p);
int PersonajeX(Personaje p);
int PersonajeY(Personaje p);
int PersonajeW(Personaje p);
int PersonajeH(Personaje p);

#endif // __PERSONAJE_H
