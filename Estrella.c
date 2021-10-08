#include "Estrella.h"
#include <stdlib.h>

struct EstrellaRep
{
    Imagen i;
    int x;
    int y;
    int h;
    int w;
};

typedef struct EstrellaRep e;

Estrella EstrellaCrea(Imagen i, int x, int y, int h, int w)
{
    Estrella e = malloc(sizeof (struct EstrellaRep));
    e->i = i;
    e->x = x;
    e->y = y;
    e->h = h;
    e->w = w;
    return e;
}

void EstrellaLibera(Estrella e)
{
    free(e);
}

void EstrellaDibuja(Estrella e) { Pantalla_DibujaImagen(e->i, e->x, e->y, e->w, e->h); }

int EstrellaX(Estrella e) { return e->x; }
int EstrellaY(Estrella e) { return e->y; }
int EstrellaW(Estrella e) { return e->w; }
int EstrellaH(Estrella e) { return e->h; }

