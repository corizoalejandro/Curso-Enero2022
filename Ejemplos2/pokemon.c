#include "pokemon.h"
#include <stdio.h>
#include <string.h>

pokemon inicializa_pokemon(const char nombre[], const char tipo1[], const char tipo2[]){
    pokemon p;
    strcpy(p.nombre, nombre);
    strcpy(p.tipo1, tipo1);
    if(strlen(tipo2)){
        strcpy(p.tipo2, tipo2);
    }else{
        strcpy(p.tipo2, "N/A");
    }

    return p;
}

void inicializa_pokemon_alt(pokemon *p, const char* nombre, const char* tipo1, const char* tipo2){
    strcpy(p->nombre, nombre);
    strcpy(p->tipo1, tipo1);
    if(strlen(tipo2)){
        strcpy(p->tipo2, tipo2);
    }else{
        strcpy(p->tipo2, "N/A");
    }
}

void muestra_datos_pokemon(pokemon *p){
    printf("Nombre: %s\n", p->nombre);
    printf("Tipo 1: %s\n", p->tipo1);
    printf("Tipo 2: %s\n", p->tipo2);
    printf("\n");
}
