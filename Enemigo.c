#include "Enemigo.h"
#include <stdlib.h>

struct EnemigoRep
{
    Imagen i;
    int x;
    int y;
    int h;
    int w;
    int vx;
    int vy;
};

typedef struct EnemigoRep e;

Enemigo EnemigoCrea(Imagen i, int x, int y, int h, int w, int vx, int vy)
{
    Enemigo e = malloc(sizeof (struct EnemigoRep));
    e->i = i;
    e->x = x;
    e->y = y;
    e->h = h;
    e->w = w;
    e->vx = vx;
    e->vy = vy;
    return e;
}

void EnemigoLibera(Enemigo e)
{
    free(e);
}

void EnemigoMueve(Enemigo e)
{
    e->x = e->x + e->vx;
    e->y = e->y + e->vy;
    if ((e->x < 0) || e->x > Pantalla_Anchura() - e->w) {
        e->vx = -e->vx;
    }
     if ((e->y < 0) || e->y > Pantalla_Altura() - e->h) {
        e->vy = -e->vy;
    }

}

void EnemigoDibuja(Enemigo e) { Pantalla_DibujaImagen(e->i, e->x, e->y, e->w, e->h); }

int EnemigoX(Enemigo e) { return e->x; }
int EnemigoY(Enemigo e) { return e->y; }
int EnemigoW(Enemigo e) { return e->w; }
int EnemigoH(Enemigo e) { return e->h; }

