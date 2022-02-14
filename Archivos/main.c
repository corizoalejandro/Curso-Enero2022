#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon.h"

#define NOMBRE_ARCHIVO "./archivito.txt"
#define ARCHIVO_POKEMON "./pokemon.txt"
#define ARCHIVO_POKEMON_BIN "./pokemon.bin"
#define BUFFER 50
#define MODO_BIN

void guardando_datos_texto(void);
void guardando_datos_texto_variables(void);
void guardando_pokemon(void);
void cargando_datos_texto(void);
void cargando_datos_texto_con_buffer(void);
void cargando_datos_pokemon(void);

int main()
{
    guardando_pokemon();
    cargando_datos_pokemon();
    printf("Fin de programa\n");
    return EXIT_SUCCESS;
}

/*

  GUARDAR DATOS

*/

// función para almacenar datos dentro de
// un archivo
void guardando_datos_texto(){
    // creamos un descriptor de archivo FILE
    FILE* archivito = NULL;
    // Abrimos el archivo
    archivito = fopen(NOMBRE_ARCHIVO, "w");
//    archivito = fopen(NOMBRE_ARCHIVO, "a");
    // guardamos datos dentro del archivo
    fputs("Mira cambie de texto!", archivito);

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
#ifdef MODO_BIN
    archivito = fopen(ARCHIVO_POKEMON, "wb");
    if(guarda_pokemon(pikachu, archivito, POKEMON_BINARIO) == 0){
#else
    archivito = fopen(ARCHIVO_POKEMON, "w");
    if(guarda_pokemon(pikachu, archivito, POKEMON_TEXTO) == 0){
#endif
        printf("pokemon no se pudo guardar :(\n");
    }else{
        printf("pokemon guardado con exito :D\n");
    }
    // cerramos el archivo
    fclose(archivito);
}

/*

  CARGAR DATOS

*/

// ejemplo para cargar datos
void cargando_datos_texto(void){
    // crear nuestro descriptor de archivo
    FILE* archivito = NULL;
    printf("Mostrando los datos de: %s\n", NOMBRE_ARCHIVO);
    // abrir el archivo en modo lectura
    archivito = fopen(NOMBRE_ARCHIVO, "r");
    // vamos a leer caracter por caracter
    do{
        printf("%c", fgetc(archivito));
    }while(!feof(archivito));
    printf("\n");
    // cerrar el archivo
    fclose(archivito);
}

// 2do ejemplo para cargar datos
void cargando_datos_texto_con_buffer(void){
    // cargamos el buffer donde vamos a meter los datos
    char* buffer = malloc(BUFFER);
    memset(buffer, '\0', BUFFER);
    // crear nuestro descriptor de archivo
    FILE* archivito = NULL;
    printf("Mostrando los datos de: %s\n", NOMBRE_ARCHIVO);
    // abrir el archivo en modo lectura
    archivito = fopen(NOMBRE_ARCHIVO, "r");
    // almacenando datos del archivo dentro del buffer
    for(int i=0;i < BUFFER || !feof(archivito);i++){
        buffer[i] = fgetc(archivito);
    }
    printf("buffer: %s\n", buffer);
    // cerramos el archivo
    fclose(archivito);
    free(buffer);
}

// cargando datos de una estructura
void cargando_datos_pokemon(void){
    // creamos la estructura donde almacenaremos los datos
    pokemon* pikachu = (pokemon*) malloc(sizeof(pokemon));
    // creamos el descriptor de archivo
    FILE* archivito = NULL;
    printf("Mostrando los datos de: %s\n", ARCHIVO_POKEMON);
    // abrimos el archivo
    // cargando datos de pokemon
#ifdef MODO_BIN
    archivito = fopen(ARCHIVO_POKEMON, "rb");
    if(carga_pokemon(pikachu, archivito, POKEMON_BINARIO)){
#else
    archivito = fopen(ARCHIVO_POKEMON, "r");
    if(carga_pokemon(pikachu, archivito, POKEMON_TEXTO)){
#endif
        muestra_datos_pokemon(pikachu);
    }else{
        printf("no se pudo leer el archivo :(\n");
    }
    // cerramos el archivo
    fclose(archivito);
    free(pikachu);
}
