#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon.h"

void asigna_valor(int* variable, int valor);
void ejemplo_1(void);
void ejemplo_2(void);
pokemon lee_pokemon(void);

void juega_pokemon(pokemon* poke);

int main()
{
    pokemon* equipo = NULL;
    pokemon* realocado = NULL;

    pokemon pruebas = lee_pokemon();
    muestra_datos_pokemon(&pruebas);
//    printf("apuntando a: %p\n", equipo);
//     inicializa equipo (reserva memoria)
//    equipo = (pokemon*) malloc(sizeof (pokemon));
//    printf("apuntando a: %p\n", equipo);
//    juega_pokemon(equipo);
//    inicializa_pokemon_alt(equipo, "pikachu", "electrico", "");
//    muestra_datos_pokemon(equipo);
//    realocado = (pokemon*) realloc(equipo, sizeof (pokemon)*STRING_POKEMON);
//    printf("apuntando a: %p\n", realocado);
//    muestra_datos_pokemon(&equipo[0]);
    free(equipo);
    free(realocado);

    printf("fin de programa\n");
    return EXIT_SUCCESS;
}



pokemon lee_pokemon(void){
    pokemon p;
    char buffer[STRING_POKEMON];
//    fflush(stdin);
    scanf("%s", buffer);
    strcpy(p.nombre, buffer);
//    fflush(stdin);
    scanf("%s", buffer);
    strcpy(p.tipo1, buffer);
    // los datos que falten
    return p;
}

void juega_pokemon(pokemon* poke){
    inicializa_pokemon_alt(poke, "pikachu", "electrico", "");
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
