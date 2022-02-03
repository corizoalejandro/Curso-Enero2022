// Van las bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculadora.h"
#include "punto.h"
#include "pokemon.h"

// Constantes
#define CONSTANTE 10
#define TAMANO 5
#define TAM_CADENA 20
#define TEAM_POKEMON 6

enum Elementos {
    TIERRA, // = 0
    AGUA,   // = 1
    FUEGO,  // = 2
    AIRE    // = 3
};

enum Pokemon {
    PIKACHU = 25
};

// declarando funciones
void ejemplos_clase_2(void);
void repaso_clase_2(void);
void clase_3_ejemplo_1(void);
void clase_3_ejemplo_2(void);
void muestra_menu(void);
void clase_5_ejemplo_1(void);
void clase_5_ejemplo_2(void);

// Función prinicpal
int main(void){
    pokemon equipo[TEAM_POKEMON];

    equipo[0] = inicializa_pokemon("pikachu", "electrico", "");
    equipo[1] = inicializa_pokemon("squirtle", "agua", "");
    equipo[2] = inicializa_pokemon("bulbasaur", "planta", "veneno");
    equipo[3] = inicializa_pokemon("charmander", "fuego", "");
    equipo[4] = inicializa_pokemon("gengar", "fantasma", "veneno");
    equipo[5] = inicializa_pokemon("alakazam", "psiquico", "");

    for(int i=0;i < TEAM_POKEMON; i++){
        muestra_datos_pokemon(equipo[i]);
    }

    return EXIT_SUCCESS;
}

// definicion de funciones
void ejemplos_clase_2(void){
    int entrada = FUEGO;
    printf("ingresa un valor de elemento: ");
    scanf("%i", &entrada);
    printf("valor de entrada = %i\n", entrada);
    printf("El valor ingresado fue: %i\n", (entrada >> 2));
    if (entrada < CONSTANTE){
        printf("entrada es menor que constante\n");
    }else if(entrada > CONSTANTE){
        printf("entrada es mayor que constante\n");
    }else if(entrada == CONSTANTE){
        printf("entrada es igual que constante\n");
    }else{
        printf("no se que rayos esta pasando\n");
    }


    switch(entrada){
    case TIERRA: {
        printf("La seleccion fue TIERRA\n");
        break;
    }
    case FUEGO: {
        printf("Pero todo cambio cuando la nacion de fuego ataco\n");
        break;
    }
    case AGUA: {
        printf("La seleccion fue AGUA\n");
        break;
    }
    case AIRE: {
        printf("La seleccion fue AIRE\n");
        break;
    }
    default: {
        printf("La seleccion no fue valida\n");
        break;
    }
    }
}

void repaso_clase_2(void){
    int elemento = 80;
    if(elemento <= AIRE && elemento >= TIERRA){
        printf("Dentro del rango\n");
    }else{
        printf("Fuera del rango\n");
    }
}

void clase_3_ejemplo_1(void){
    //    int contador = 6;
    //    while(contador < CONSTANTE){
    //        printf("Dentro del bucle - %i\n", contador);
    //        contador++;
    //    }
    //    do{
    //        printf("Dentro del bucle - %i\n", contador);
    //        contador++;
    //    }while(contador < CONSTANTE);
        for(int contador = 0, aux = 4; contador < CONSTANTE; contador++, aux--){
            printf("contador = %i // aux = %i\n", contador, aux);
        }
}

void clase_3_ejemplo_2(void){
    int arreglo[TAMANO];

    for(int i=0; i < TAMANO; i++){
        arreglo[i] = i*i;
    }

    for(int i=0; i < TAMANO; i++){
        printf("arreglo[%i] = %i\n", i, arreglo[i]);
    }

}


void clase_4_ejemplos(void)
{
    //    char cadenita[CONSTANTE] = { 'h', 'o', 'l', 'a' };
    //    printf("cadenita: %s\n", cadenita);
    //    char cadenita[TAM_CADENA];
    //    char cadenitaUnion[TAM_CADENA];
    //    strcpy(cadenita, "hola");
    //    strcpy(cadenitaUnion, " mundo!");
    //    strcat(cadenita, cadenitaUnion);
    //    printf("cadenita: %s\n", cadenita);
    //    printf("El tamano de cadenita es: %i\n", strlen(cadenita));

    //    if(strcmp(cadenita, cadenitaUnion)){
    //    }
        int numero1, numero2;
        char operador;

        scanf("%i %c %i", &numero1, &operador, &numero2);
        printf("%i %c %i\n", numero1, operador, numero2);
        printf("fin de programa\n");
}

void muestra_menu(void){
    printf("a) suma +\n");
    printf("b) resta -\n");
    printf("c) multiplicacion *\n");
    printf("d) division /\n");
    printf("e) modulo %%\n");
    printf("\n");
}

void clase_5_ejemplo_1(void){
    int resultado;
    int valor1 = 2;
    int valor2 = 3;
    muestra_menu();
    muestra_menu();
    muestra_menu();
    resultado = suma(valor1, valor2);
    printf("La suma de 2 numeros es: %i\n", resultado);
    printf("el valor de valor1: %i\n", valor1);
}

void clase_5_ejemplo_2(void){
        struct punto puntito1, puntito2;
        puntito1.x = 5;
        puntito1 = genera_punto(4, 9, 71, "el nombre 1");
        puntito2 = genera_punto(8, 87, 9, "firulais");

        imprime_punto(puntito1);
        imprime_punto(puntito2);
}
