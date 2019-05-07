#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FuncionesBasicas.h"
#include "Peliculas.h"
#define LIBRE -1
#define OCUPADO 0

int inicializarPeliculas(sPelicula listadoPeliculas[], int limite)
{
    int retorno=-1;
    //if(listadoPeliculas != NULL && limite < 0)
    // {
    int i;

    for(i=0; i<limite; i++)
    {
        listadoPeliculas[i].isEmpty=LIBRE;
    }
    retorno=0;
    // }
    return retorno;
}

int buscarLibre(sPelicula listadoPeliculas[], int limite)
{
    int i;
    int indice;

    for(i=0; i<limite; i++)
    {
        if(listadoPeliculas[i].isEmpty == LIBRE)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int altaPelicula(sPelicula listadoPeliculas[], int indice, int limite)
{
    int retorno=-1;
    //if(listadoPeliculas != NULL && limite < 0)
    //{
    fflush(stdin);
    strcpy(listadoPeliculas[indice].titulo, pedirString("Ingrese el titulo: ", listadoPeliculas[indice].titulo, 30));
    printf("Ingrese fecha de estreno: \n");
    listadoPeliculas[indice].fechaEstreno.dia=pedirEntero("Dia:");
    listadoPeliculas[indice].fechaEstreno.mes=pedirEntero("Mes:");
    listadoPeliculas[indice].fechaEstreno.anio=pedirEntero("Anio:");
    listadoPeliculas[indice].genero=pedirEntero("Ingrese el genero:\n1.Accion\n2.Comedia\n3.Drama\n4.Romance\n5.Terror\n");
    listadoPeliculas[indice].actor=pedirEntero("Ingrese numero del actor: ");
    listadoPeliculas[indice].id=generarId();
    listadoPeliculas[indice].isEmpty=OCUPADO;

    retorno=0;
    // }
    return retorno;
}

int mostrarPelicula(sPelicula listadoPeliculas[], int indice)
{
    printf("%4d-%29s -%2d/%2d/%4d- %2d - %d\n", listadoPeliculas[indice].id, listadoPeliculas[indice].titulo, listadoPeliculas[indice].fechaEstreno.dia, listadoPeliculas[indice].fechaEstreno.mes,
           listadoPeliculas[indice].fechaEstreno.anio, listadoPeliculas[indice].actor, listadoPeliculas[indice].genero);

    return 0;
}

int mostrarListadoPeliculas(sPelicula listadoPeliculas[], int limite)
{
    int retorno=-1;
    int i;
    for(i=0; i<limite; i++)
    {
        if(listadoPeliculas[i].isEmpty==OCUPADO)
        {
            mostrarPelicula(listadoPeliculas, i);
            retorno=0;
        }
    }
    return retorno;
}

int hardcodePeliculas(sPelicula listadoPeliculas[], int limite)
{
    int retorno=-1;
    int i;

    char titulos[][30]= {"Avengers EndGame", "Thor", "Cellular", "Men in Black4", "IronMan", "13 Going on 30", "Lucy", "Nace una estrella", "¿Dime con cuantos?", "Guardianes de la galaxia", "A perfect murder", "La isla", "Que paso ayer", "Home Alone 3", "Deadpool", "Sherlock Holmes", "Men in Black 3", "Avengers Infinity War", "Grandes esperanzas", "SWAT", "XxX"};
    int dia[21]= {20, 10, 2, 10, 5, 7, 9, 8, 4, 20, 6, 3, 5, 6, 7, 5, 2, 6, 8, 20, 11};
    int mes[21]= {4, 6, 5, 7, 9, 5, 2, 3, 4, 5, 8, 10, 2, 10, 12, 6, 5, 4, 12, 2, 5};
    int anio[21]= {2019, 2013, 2004, 2019, 2012, 2004, 2014, 2018, 2010, 2014, 1995, 2005, 2013, 1997, 2015, 2011, 2010, 2017, 1995, 1998, 1992};
    int actor[21]= {2, 5, 4, 5, 2, 3, 1, 9, 4, 9, 7, 1, 9, 1, 10, 2, 10, 10, 7, 6, 6};
    int genero[21]= {1, 1, 1, 1, 1, 4, 1, 4, 4, 1, 3, 2, 2, 1, 1, 1, 1, 4, 1, 1};

    for(i=0; i<21; i++)
    {
        strcpy(listadoPeliculas[i].titulo, titulos[i]);
        listadoPeliculas[i].fechaEstreno.dia=dia[i];
        listadoPeliculas[i].fechaEstreno.mes=mes[i];
        listadoPeliculas[i].fechaEstreno.anio=anio[i];
        listadoPeliculas[i].actor=actor[i];
        listadoPeliculas[i].genero=genero[i];
        listadoPeliculas[i].id=generarId();
        listadoPeliculas[i].isEmpty=OCUPADO;
        retorno=0;
    }
    return retorno;
}

int generarId(void)
{
    static int generadorId=999;
    generadorId++;

    return generadorId;
}

int ordenarAnio(sPelicula listadoPeliculas[], int limite)
{
    int retorno=-1;
    int i;
    int j;
    sPelicula aux;

    for(i=0; i<limite-1; i++)
    {
        for(j=i+1; j<limite; j++)
        {
            if(listadoPeliculas[j].fechaEstreno.anio < listadoPeliculas[i].fechaEstreno.anio)
            {
                aux=listadoPeliculas[i];
                listadoPeliculas[i]=listadoPeliculas[j];
                listadoPeliculas[j]=aux;
                retorno=0;
            }
        }
    }
    return retorno;
}

int preguntarOrdenar(sPelicula listadoPeliculas[], int limite)
{
    int opcion;
    int retorno=-1;

    printf("========================================================\n");
    printf("            1) Peliculas sin ordenar.\n\n");
    printf("            2) Peliculas ordenadas por anio.\n");
    printf("========================================================\n");
    opcion=pedirEntero("Ingrese una opcion: ");
    switch(opcion)
    {
    case 1:
        mostrarListadoPeliculas(listadoPeliculas, limite);
        retorno=0;
        break;
    case 2:
        ordenarAnio(listadoPeliculas, limite);
        mostrarListadoPeliculas(listadoPeliculas, limite);
        retorno=0;
        break;
    }
    return retorno;
}

int buscarId(sPelicula listadoPeliculas[], int limite)
{
    int idIngresado=pedirEntero("Ingrese el Id de la pelicula: ");
    int i;
    int indiceEncontrado;

    for(i=0; i<limite; i++)
    {
        if(listadoPeliculas[i].id == idIngresado)
        {
            indiceEncontrado=i;
            break;
        }
    }
    return indiceEncontrado;
}

int borrarPelicula(sPelicula listadoPeliculas[], int limite)
{
    int retorno=-1;
    int indice=buscarId(listadoPeliculas, limite);
    char respuesta;

    if(indice >= 0)
    {
        printf("\n");
        mostrarPelicula(listadoPeliculas, indice);
        printf("\n Esta seguro que desea borrar esta pelicula? (S para Si, N para No)\n");
        fflush(stdin);
        respuesta=getchar();
        if(respuesta == 'S' || respuesta == 's')
        {
            listadoPeliculas[indice].isEmpty=LIBRE;
            printf("\nPelicula borrada con exito!\n");
        }
        retorno=0;
    }
    return retorno;
}

int modificarPelicula(sPelicula listadoPeliculas[], int limite)
{
    int retorno=-1;
    int indice=buscarId(listadoPeliculas, limite);
    int opcion;

    mostrarPelicula(listadoPeliculas, indice);
    printf("1) Titulo\n2) Fecha de estreno\n3) Actor\n");
    opcion=pedirEntero("Ingrese la opcion que desea modificar");
    switch(opcion)
    {
        case 1:
            retorno=modificarTitulo(listadoPeliculas, indice);
            break;
        case 2:
            retorno=modificarFecha(listadoPeliculas, indice);
            break;
        case 3:
            retorno=modificarActor(listadoPeliculas, indice);
            break;
    }
    return retorno;
}

int modificarTitulo(sPelicula listadoPeliculas[], int indice)
{
    int retorno=-1;

    if(indice >= 0)
    {
        strcpy(listadoPeliculas[indice].titulo, pedirString("Ingrese el nuevo titulo: ", listadoPeliculas[indice].titulo, 30));
        printf("\nModificacion exitosa!\n");
        retorno=0;
    }
    return retorno;
}

int modificarActor(sPelicula listadoPeliculas[], int indice)
{
    int retorno=-1;

    if(indice >= 0)
    {
        listadoPeliculas[indice].actor=pedirEntero("Ingrese nuevo actor: ");
        printf("\nModificacion exitosa!\n");
        retorno=0;
    }
    return retorno;
}

int modificarFecha(sPelicula listadoPeliculas[], int indice)
{
    int retorno=-1;

    if(indice >= 0)
    {
        listadoPeliculas[indice].fechaEstreno.dia=pedirEntero("Ingrese el nuevo dia: ");
        listadoPeliculas[indice].fechaEstreno.mes=pedirEntero("Ingrese el nuevo mes: ");
        listadoPeliculas[indice].fechaEstreno.anio=pedirEntero("Ingrese el nuevo anio: ");
        printf("\nModificacion exitosa!\n");
        retorno=0;
    }
    return retorno;
}

int hardcodeActores(sActor listadoActores, int limite)
{
    int id[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char nombre[][21]={"Scarlett Johansson", "Robert Downey Jr", "Mark Ruffalo", "Chris Evans", "Chris Hemsworth", "Samuel Jackson", "Gwyneth Paltrow", "Paul Rudd", "Bradley Cooper", "Josh Brolin"};

}
