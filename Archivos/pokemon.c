#include "pokemon.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Carga los datos tomados en los parámetros para
// rellenar una estructura simple y la regresa
pokemon inicializa_pokemon(const char nombre[], const char tipo1[], const char tipo2[]){
    pokemon p;
    // rellenado de datos
    strcpy(p.nombre, nombre);
    strcpy(p.tipo1, tipo1);
    if(strlen(tipo2)){
        strcpy(p.tipo2, tipo2);
    }else{
        strcpy(p.tipo2, "N/A");
    }

    return p;
}

// Toma los datos necesarios para rellenar
// una estructura de pokemon y los almacena
// dentro de la que toma como parámetro
void inicializa_pokemon_alt(pokemon *p, const char* nombre, const char* tipo1, const char* tipo2){
    // checamos si el puntero de pokemon tomado
    // es nula, en caso de, salirse de la función
    if(p == NULL){
        printf("No se inicializo pokemon insertado\n");
        return;
    }
    // rellenado de datos
    strcpy(p->nombre, nombre);
    strcpy(p->tipo1, tipo1);
    if(strlen(tipo2)){
        strcpy(p->tipo2, tipo2);
    }else{
        strcpy(p->tipo2, "N/A");
    }
}

// Carga los datos de los parámetros creando un nuevo
// pokemon con los respectivos datos y lo regresa
pokemon* inicializa_puntero_pokemon(const char* nombre, const char* tipo1, const char* tipo2){
    pokemon *p = (pokemon*) malloc(sizeof(pokemon));
    inicializa_pokemon_alt(p, nombre, tipo1, tipo2);
    return p;
}

// Muestra los datos contenidos dentro de una estructura
// de pokemon dada
void muestra_datos_pokemon(pokemon *p){
    printf("Nombre: %s\n", p->nombre);
    printf("Tipo 1: %s\n", p->tipo1);
    printf("Tipo 2: %s\n", p->tipo2);
    printf("\n");
}

// Compara 2 pokemon utilizando el nombre como
// parámetro de comparación
// se utilizan punteros a void para poder aplicarlo
// dentro de un puntero a función
int compara_pokemon(void *pokemon1, void *pokemon2){
    pokemon* p1 = (pokemon*) pokemon1;
    pokemon* p2 = (pokemon*) pokemon2;
    // strcmp regresa:
    // < 0 cuando es menor
    // == 0 cuando son iguales
    // > 0 cuando es mayor
    return strcmp(p1->tipo1, p2->tipo1);
}

// almacenar un pokemon dentro de un archivo
int guarda_pokemon(pokemon* p, FILE *archivo, int tipo){
    int resultado = 0;
    // checamos si nos pasaron un archivo válido
    if(archivo == NULL){
        return resultado;
    }
    // guardamos en texto
    if(tipo == POKEMON_TEXTO){
        resultado = fprintf(archivo, "%s,%s,%s\n", p->nombre, p->tipo1, p->tipo2);
    // guardamos en binario
    }else if(tipo == POKEMON_BINARIO){
        resultado = fputs((char*) p, archivo);
    }
    // regresamos nuestro resultado
    return resultado;
}
