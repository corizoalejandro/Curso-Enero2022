#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>

#define STRING_POKEMON 20
#define MAX_MOVIMIEMTOS 4
#define MAX_EQUIPO_POKEMON 6

enum {
    POKEMON_TEXTO,
    POKEMON_BINARIO
};

typedef struct movimiento {
    char nombre[STRING_POKEMON];
    char tipo[STRING_POKEMON];
    int poderBase;
} movimiento;

typedef struct pokemon {
   char nombre[STRING_POKEMON];
   char tipo1[STRING_POKEMON];
   char tipo2[STRING_POKEMON];
   movimiento movimientos[MAX_MOVIMIEMTOS];
} pokemon;

pokemon inicializa_pokemon(const char nombre[], const char tipo1[], const char tipo2[]);

void inicializa_pokemon_alt(pokemon *p, const char* nombre, const char *tipo1, const char *tipo2);

pokemon* inicializa_puntero_pokemon(const char* nombre, const char* tipo1, const char* tipo2);

void muestra_datos_pokemon(pokemon *p);

int compara_pokemon(void *pokemon1, void *pokemon2);

int guarda_pokemon(pokemon* p, FILE *archivo, int tipo);

int carga_pokemon(pokemon* p, FILE *archivo, int tipo);

#endif
