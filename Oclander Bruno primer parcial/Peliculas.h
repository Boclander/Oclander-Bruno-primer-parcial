#ifndef Peliculas
#include "Actores.h"

typedef struct
{
    int dia;
    int mes;
    int anio;

}sFecha;

typedef struct
{
    int id;
    char* nombre;

}sGenero;

typedef struct
{
    char titulo[30];
    sFecha fechaEstreno;
    sGenero genero;
    sActor actor;
    int id;
    int isEmpty;

}sPelicula;

int inicializarPeliculas(sPelicula listadoPeliculas[], int limite);
int buscarLibre(sPelicula listadoPeliculas[], int limite);
int generarId(void);
int altaPelicula(sPelicula listadoPeliculas[], sActor listadoActores[], int indice, int limite);
int hardcodePeliculas(sPelicula listadoPeliculas[]);
int mostrarPelicula(sPelicula listadoPeliculas[], int indice);
int mostrarListadoPeliculas(sPelicula listadoPeliculas[], int limite);
int ordenarAnio(sPelicula listadoPeliculas[], int limite);
int preguntarOrdenar(sPelicula listadoPeliculas[], int limite);
int buscarId(sPelicula listadoPeliculas[], int limite);
int borrarPelicula(sPelicula listadoPeliculas[], int limite);
int modificarPelicula(sPelicula listadoPeliculas[], sActor listadoActores[], int limite);
int modificarTitulo(sPelicula listadoPeliculas[], int indice);
int modificarFecha(sPelicula listadoPeliculas[], int indice);
int modificarActor(sPelicula listadoPeliculas[], sActor listadoActores[], int indice);
#endif // Peliculas
