#include <stdio.h>
#include <stdlib.h>
#include "pokemon.h"

void asigna_valor(int* variable, int valor);
void ejemplo_1(void);
void ejemplo_2(void);

int main()
{
    pokemon* equipo = NULL;
    pokemon* realocado = NULL;
    printf("apuntando a: %p\n", equipo);
    equipo = (pokemon*) malloc(sizeof (pokemon));
    printf("apuntando a: %p\n", equipo);
    inicializa_pokemon_alt(equipo, "pikachu", "electrico", "");
    muestra_datos_pokemon(equipo);
    realocado = (pokemon*) realloc(equipo, sizeof (pokemon)*STRING_POKEMON);
    printf("apuntando a: %p\n", realocado);
    muestra_datos_pokemon(&equipo[0]);
    free(equipo);
    free(realocado);

    printf("fin de programa\n");
    return EXIT_SUCCESS;
}

void asigna_valor(int* variable, int valor){
    *variable = valor;
}

void ejemplo_1(void){
    int dato = 7;
    int otroDato = 97;
    int* pDato;
    printf("El valor del dato al que apuntamos es: %i\n", *pDato);
    printf("La direccion del puntero es: %p\n", pDato);
    asigna_valor(&dato, 47);
    pDato = &dato;
    printf("La direccion del puntero es %p\n", pDato);
    printf("El valor del dato al que apuntamos es: %i\n", *pDato);
    pDato = &otroDato;
    printf("La direccion del puntero es %p\n", pDato);
    printf("El valor del dato al que apuntamos es: %i\n", *pDato);
}

void ejemplo_2(void){
    pokemon pikachu;
    printf("el tamano de una estructura pokemon es: %i\n", sizeof(pokemon));
    inicializa_pokemon_alt(&pikachu, "pikachu", "electrico", "");
    muestra_datos_pokemon(&pikachu);
}
