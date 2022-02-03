#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon.h"

void ordena_arreglo(void **arreglo, int tam, int (*compara) (void*,void*));

int main()
{
    // inicializamos un arreglo de punteros
    // para almacenar nuestro equipo pokemon
    pokemon** equipo = (pokemon**) malloc(sizeof (pokemon*)*MAX_EQUIPO_POKEMON);

    // rellenando nuestro equipo pokemon
    equipo[0] = inicializa_puntero_pokemon("pikachu", "electrico", "");
    equipo[1] = inicializa_puntero_pokemon("bulbasaur", "planta", "veneno");
    equipo[2] = inicializa_puntero_pokemon("squirtle", "agua", "");
    equipo[3] = inicializa_puntero_pokemon("charmander", "fuego", "");
    equipo[4] = inicializa_puntero_pokemon("abra", "psiquico", "");
    equipo[5] = inicializa_puntero_pokemon("gengar", "fantasma", "veneno");

    // ordenamos nuestro arreglo
    ordena_arreglo((void**) equipo, MAX_EQUIPO_POKEMON, &compara_pokemon);

    // mostramos arreglo
    for(int i=0; i < MAX_EQUIPO_POKEMON; i++){
        muestra_datos_pokemon(equipo[i]);
    }

    return EXIT_SUCCESS;
}

// metodo burbuja para arreglar un arreglo cualquiera
// que contenga un arreglo de punteros
void ordena_arreglo(void **arreglo, int tam, int (*compara) (void*,void*)){
    void *aux = NULL;
    for(int i=1;i < tam; i++){
        for(int j=0; j < tam-1; j++){
            if(compara(arreglo[i], arreglo[j]) < 0){
                aux = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = aux;
            }
        }
    }
}
