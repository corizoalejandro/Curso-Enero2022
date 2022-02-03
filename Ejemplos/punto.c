#include <stdio.h>
#include <string.h>
#include "punto.h"

struct punto genera_punto(int x, int y, int z, const char nombre[]){
    struct punto puntito;
    puntito.x = x;
    puntito.y = y;
    puntito.z = z;
    strcpy(puntito.nombre, nombre);

    return puntito;
}

void imprime_punto(struct punto puntito){
    printf("El eje X de %s es: %i\n", puntito.nombre, puntito.x);
    printf("El eje Y de %s es: %i\n", puntito.nombre, puntito.y);
    printf("El eje Z de %s es: %i\n", puntito.nombre, puntito.z);
    printf("\n");
}
