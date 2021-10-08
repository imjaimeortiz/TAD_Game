#ifndef __ESTRELLA_H
#define __ESTRELLA_H
#include "Pantalla.h"

typedef struct EstrellaRep * Estrella;
Estrella EstrellaCrea(Imagen i, int x, int y, int h, int w);
void EstrellaLibera(Estrella e);
void EstrellaDibuja(Estrella e);
int EstrellaX(Estrella e);
int EstrellaY(Estrella e);
int EstrellaW(Estrella e);
int EstrellaH(Estrella e);


#endif // __ESTRELLA_H
