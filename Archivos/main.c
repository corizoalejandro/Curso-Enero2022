#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon.h"

#define NOMBRE_ARCHIVO "./archivito.txt"
#define ARCHIVO_POKEMON "./pokemon.csv"

void guardando_datos_texto();
void guardando_datos_texto_variables();
void guardando_pokemon();

int main()
{
    guardando_pokemon();
    printf("Fin de programa\n");
    return EXIT_SUCCESS;
}

// función para almacenar datos dentro de
// un archivo
void guardando_datos_texto(){
    // creamos un descriptor de archivo FILE
    FILE* archivito = NULL;
    // Abrimos el archivo
    archivito = fopen(NOMBRE_ARCHIVO, "w");
//    archivito = fopen(NOMBRE_ARCHIVO, "a");
    // guardamos datos dentro del archivo
    fputs(" no son trucos!!", archivito);

    // cerramos el archivo
    fclose(archivito);
    printf("Archivo guardado con exito: %s\n", NOMBRE_ARCHIVO);
}

// función para almacenar datos dentro de
// un archivo usando variables
void guardando_datos_texto_variables(){
    // creamos un descrptor de archivo FILE
    FILE* archivito = NULL;
    // variables para almacenar dentro del archivo
    int dato1, dato2, dato3;
    // tomar datos para almacenar
    printf("Dame los 3 datos de golpe:");
    scanf("%i %i %i", &dato1, &dato2, &dato3);
    fflush(stdin);
    // Abrimos el archivo
    archivito = fopen(NOMBRE_ARCHIVO, "w");
    // guardar datos dentro del archivo
    fprintf(archivito, "Voy a meter variables como: %i %i %i", dato1, dato2, dato3);
    // cerramos el archivo
    fclose(archivito);
    printf("Archivo guardado con exito: %s\n", NOMBRE_ARCHIVO);
}

// ejemplo para guardar estructuras
void guardando_pokemon(){
    // creamos nuestro descriptor de arhivo
    FILE* archivito = NULL;
    // creamos estructura(s) a guardar
    pokemon* pikachu = inicializa_puntero_pokemon("pikachu", "electrico", "");
    // vamos a guardar pokemon en texto
    archivito = fopen(ARCHIVO_POKEMON, "w");
    if(guarda_pokemon(pikachu, archivito, POKEMON_TEXTO) == 0){
        printf("pokemon no se pudo guardar :(\n");
    }else{
        printf("pokemon guardado con exito :D\n");
    }
    // cerramos el archivo
    fclose(archivito);
}
