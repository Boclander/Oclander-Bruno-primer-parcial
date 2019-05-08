#include <stdio.h>
#include <stdlib.h>
#include "Actores.h"
#include "Peliculas.h"
#include "FuncionesBasicas.h"
#define MAXPELICULAS 1000
#define MAXACTORES 50


int main()
{
    int opcion;
    int indice;
    sPelicula listadoPeliculas[MAXPELICULAS];
    sActor listadoActores[MAXACTORES];
    inicializarPeliculas(listadoPeliculas, MAXPELICULAS);
    inicializarActores(listadoActores, MAXACTORES);
    hardcodePeliculas(listadoPeliculas);
    hardcodeActores(listadoActores);

    do
    {
        opcion=menu();
        system("pause");
        switch(opcion)
        {
            case 1:
                indice=buscarLibre(listadoPeliculas, MAXPELICULAS);
                altaPelicula(listadoPeliculas, listadoActores, indice, MAXPELICULAS);
                system("pause");
                break;
            case 2:
                modificarPelicula(listadoPeliculas, listadoActores, MAXPELICULAS);
                system("pause");
                break;
            case 3:
                borrarPelicula(listadoPeliculas, MAXPELICULAS);
                system("pause");
                break;
            case 4:
                preguntarOrdenar(listadoPeliculas, MAXPELICULAS);
                system("pause");
                break;
            case 5:
                opcion=5;
                break;
        }
    }while(opcion!=5);

    return 0;
}
