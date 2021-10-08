#include "Pantalla.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "Personaje.h"
#include "Enemigo.h"
#include "Colision.h"
#include "Estrella.h"
#include "Estrellas.h"

int main(int argc, char **argv)
{
    srand(time(NULL));
    Pantalla_Crea("Titulo", 700, 480);
    Imagen fondo = Pantalla_ImagenLee("decima.bmp", 20);
    Imagen segundaPantalla = Pantalla_ImagenLee("undecima.bmp", 20);
    Imagen ultima = Pantalla_ImagenLee("duodecima.bmp", 20);
    Imagen iestrella = Pantalla_ImagenLee("Estrella.bmp", 1);

    int terminado = 0;
    char texto[50];

    while (Pantalla_Activa() && !terminado) {
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_RETURN)) {
            terminado = 1;
        }
        Pantalla_DibujaImagen(fondo,0,0,Pantalla_Anchura(),Pantalla_Altura());
        Pantalla_ColorTrazo(255,255,255,255);
        Pantalla_DibujaTexto("Pulsa return para empezar", 50,50);
        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }

    Imagen pi = Pantalla_ImagenLee("personaje.bmp", 20);
    Imagen enemigo = Pantalla_ImagenLee("gravesen.bmp", 0);
    Personaje p = PersonajeCrea(pi,rand()%(Pantalla_Anchura()-100),Pantalla_Altura()-100,50,50);
    Enemigo e = EnemigoCrea(enemigo, rand()%(Pantalla_Anchura()-100),Pantalla_Altura()-100, 100, 100, 30, 40);
    Estrellas estrellas = EstrellasCrea(5);
    Estrella estrella = EstrellaCrea(iestrella, 100, 100, 50, 50);
    terminado = 0;
    int tSistema = time(NULL);
    while (Pantalla_Activa() && !terminado) {
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_SPACE)) {
            terminado = 1;
        }
        PersonajeMueve(p);
        EnemigoMueve(e);

        int tEjecucion = time(NULL);
        sprintf(texto, "El tiempo transcurrido es : %d", tEjecucion - tSistema);


        Pantalla_DibujaImagen(segundaPantalla,0,0,Pantalla_Anchura(),Pantalla_Altura());
        Pantalla_ColorTrazo(255,255,255,255);
        PersonajeDibuja(p);
        EnemigoDibuja(e);
        EstrellasDibuja(estrellas);
        EstrellaDibuja(estrella);
        EstrellasColision(estrellas, rand()%(Pantalla_Anchura()-200),Pantalla_Altura()-200,50,50 );
        Pantalla_DibujaTexto("Pulsa espacio para terminar", 50,50);
        Pantalla_DibujaTexto(texto, 30, 30);
        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }

    terminado = 0;
    int tTotal = time(NULL);
    sprintf(texto, "El tiempo total es : %d segundos", tTotal - tSistema);
    int tReal = tTotal-tSistema;
    FILE * f = fopen("tmax.txt", "r");
    int tmax;
    fscanf(f, "%d",&tmax);
    fclose(f);
    char texto2[100];
    if (tReal > tmax)
    {
        f = fopen("tmax.txt", "w");
        fprintf(f, "%d", tReal);
        fclose(f);
        sprintf(texto2," ¡ NUEVO RECORD ! %d", tReal);
    } else sprintf(texto2," Sigue intentándolo : %d", tReal);
    while (Pantalla_Activa() && !terminado) {
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE)) {
            terminado = 1;
        }
        Pantalla_DibujaImagen(ultima,0,0,Pantalla_Anchura(),Pantalla_Altura());
        Pantalla_ColorTrazo(255,255,255,255);
        Pantalla_DibujaTexto("Pulsa escape para salir", 50,50);
        Pantalla_DibujaTexto(texto, 30, 30);
        Pantalla_DibujaTexto(texto2, 30, 150);
        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }

    Pantalla_ImagenLibera(fondo);
    Pantalla_ImagenLibera(segundaPantalla);
    Pantalla_ImagenLibera(ultima);
    Pantalla_ImagenLibera(pi);
    Pantalla_ImagenLibera(enemigo);
    Pantalla_ImagenLibera(iestrella);
    PersonajeLibera(p);
    EnemigoLibera(e);
    Pantalla_Libera();

    return 0;
}

