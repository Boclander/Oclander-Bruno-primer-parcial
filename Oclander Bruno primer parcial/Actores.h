#define MAXPELICULAS 1000
#define MAXACTORES 50
#ifndef Actores
typedef struct
{
    int id;
    char nombre[21];
    char pais[12];
    int isEmpty;

}sActor;

int inicializarActores(sActor listadoActores[], int limite);
int hardcodeActores(sActor listadoActores[]);
int listarActores(sActor listadoActores[], int limite);

#endif // Actores
