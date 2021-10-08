#include "Personaje.h"
#include <stdlib.h>

struct PersonajeRep
{
    Imagen i;
    int x;
    int y;
    int h;
    int w;
};

//typedef struct PersonajeRep p;

Personaje PersonajeCrea(Imagen i, int x, int y, int h, int w)
{
    Personaje p = malloc(sizeof (struct PersonajeRep));
    p->i = i;
    p->x = x;
    p->y = y;
    p->h = h;
    p->w = w;
    return p;
}

void PersonajeLibera(Personaje p)
{
    free(p);
}

void PersonajeMueve(Personaje p)
{
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_UP))
    {
        p->y -= 50;
        if (p->y < 0) p->y = 0;
    }
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN))
    {
        p->y += 50;
        if(p->y > Pantalla_Altura() - p->h) p->y = Pantalla_Altura() - p->h;
    }
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT))
    {
        p->x += 50;
        if (p->x > Pantalla_Anchura() - p->w) p->x = Pantalla_Anchura() - p->w;
    }
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT))
    {
        p->x -= 50;
        if (p->x < 0) p->x = 0;
    }
}

void PersonajeDibuja(Personaje p) { Pantalla_DibujaImagen(p->i, p->x, p->y, p->w, p->h); }

int PersonajeX(Personaje p) { return p->x; }
int PersonajeY(Personaje p) { return p->y; }
int PersonajeW(Personaje p) { return p->w; }
int PersonajeH(Personaje p) { return p->h; }
