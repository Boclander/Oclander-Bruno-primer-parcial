#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FuncionesBasicas.h"

int pedirEntero(char mensaje[])
{
    int entero;

    printf("%s", mensaje);
    scanf("%d", &entero);

    return entero;
}

float pedirFlotante(char mensaje[])
{
    float flotante;

    printf("%s", mensaje);
    scanf("%f", &flotante);

    return flotante;
}

char* pedirString(char mensaje[], char* cadena, int limite)
{
    printf("%s", mensaje);
    fflush(stdin);
    fgets(cadena, limite, stdin);

    cadena[strlen(cadena)-1] = '\0';

    return cadena;
}

int menu(void)
{
    int opcion;
    system("cls");
            printf("========================================================\n");
            printf("\n");
            printf("  1) Ingresar una pelicula.      3) Borrar una pelicula.\n");
            printf("\n");
            printf("  2) Modificar una pelicula.     4) Mostrar peliculas.  \n");
            printf("\n");
            printf("                        5) Salir.                       \n");
            printf("\n");
            printf("========================================================\n");
            printf("\n");
            printf("Ingrese una opcion: ");
            scanf("%d", &opcion);

    return opcion;
}
