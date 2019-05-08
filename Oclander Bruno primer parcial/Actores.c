#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FuncionesBasicas.h"
#include "Actores.h"
#include "Peliculas.h"
#define LIBRE -1
#define OCUPADO 0

int inicializarActores(sActor listadoActores[], int limite)
{
    int retorno=-1;
    int i;

    if(limite >= 0)
    {
        for(i=0; i<limite; i++)
        {
            listadoActores[i].isEmpty=LIBRE;
        }
        retorno=0;
    }
    return retorno;
}

int hardcodeActores(sActor listadoActores[])
{
    int retorno=-1;
    int i;

    char nombre[][21]={"Scarlett Johansson", "Robert Downey Jr", "Mark Ruffalo", "Chris Evans", "Chris Hemsworth", "Samuel Jackson", "Gwyneth Paltrow", "Paul Rudd", "Bradley Cooper", "Josh Brolin"};
    char pais [][12]={"Argentina", "EEUU", "Canada", "EEUU", "Argentina", "EEUU", "Canada", "Argentina", "EEUU", "Canada"};
    int id[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for(i=0; i<10; i++)
    {
        listadoActores[i].id=id[i];
        strcpy(listadoActores[i].nombre, nombre[i]);
        strcpy(listadoActores[i].pais, pais[i]);
        listadoActores[i].isEmpty=OCUPADO;

        retorno=0;
    }
    return retorno;
}

int listarActores(sActor listadoActores[], int limite)
{
    int retorno=-1;
    int i;

    if(limite > 0)
    {
        for(i=0; i<limite; i++)
        {
            printf("%d) %s\n", listadoActores[i].id, listadoActores[i].nombre);
        }
        retorno=0;
    }
    return retorno;
}
