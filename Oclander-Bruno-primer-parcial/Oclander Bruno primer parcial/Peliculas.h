#ifndef Peliculas

typedef struct
{
    int dia;
    int mes;
    int anio;

}sFecha;

typedef struct
{
    char titulo[30];
    sFecha fechaEstreno;
    int genero;
    int actor;
    int id;
    int isEmpty;

}sPelicula;

typedef struct
{
    int id;
    char* nombre;

}sGenero;

typedef struct
{
    int id;
    char nombre[21];
    char pais[12];

}sActor;

int inicializarPeliculas(sPelicula listadoPeliculas[], int limite);
int buscarLibre(sPelicula listadoPeliculas[], int limite);
int generarId(void);
int altaPelicula(sPelicula listadoPeliculas[], int indice, int limite);
int hardcodePeliculas(sPelicula listadoPeliculas[], int limite);
int mostrarPelicula(sPelicula listadoPeliculas[], int indice);
int mostrarListadoPeliculas(sPelicula listadoPeliculas[], int limite);
int ordenarAnio(sPelicula listadoPeliculas[], int limite);
int preguntarOrdenar(sPelicula listadoPeliculas[], int limite);
int buscarId(sPelicula listadoPeliculas[], int limite);
int borrarPelicula(sPelicula listadoPeliculas[], int limite);
int modificarPelicula(sPelicula listadoPeliculas[], int limite);
int modificarTitulo(sPelicula listadoPeliculas[], int indice);
int modificarFecha(sPelicula listadoPeliculas[], int indice);
int modificarActor(sPelicula listadoPeliculas[], int indice);
int hardcodeActores(sActor listadoActores[], int limite);
#endif // Peliculas
