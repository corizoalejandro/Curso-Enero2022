#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FOREVER for(;;)
#define TRUE 1
#define NUM 50

// Si es windows
#if WIN32
#define CLEAR "cls"
// si no es windows
#else
#define CLEAR "clear"
#endif

char* invierte_cadena(char* cadena);

int main()
{
    // ejecutando forever
    FOREVER {
        break;
    }
// si la condición es verdadero, compila esto
#if TRUE
    printf("hola mundo!\n");
#else
// si la condición anterior no es verdadera, forzamos error
// en tiempo de compilación
#error yo forzando este error
#endif

    // si está definida la macro, compilamos el siguientr
    // trozo de código
#ifdef CLEAR
    printf("compilando normal :)\n");
#endif

    // si clear no está definido
    // pues la definimos
#ifndef CLEAR

#if WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#endif

    // Undefinimos a forever
#undef FOREVER

    getchar();
    // manda a llamar a la consola
    system(CLEAR);

    printf("Despues de limpiar pantalla\n");

    char* cadena = malloc(NUM);
    gets(cadena);
    printf("La cadena invertida es: %s\n", invierte_cadena(cadena));

    // practica

//    FOREVER {

//    }
    return 0;
}

char* invierte_cadena(char* cadena){
    int longitud = strlen(cadena);
    if(!longitud){
        return NULL;
    }
    cadena = realloc(cadena, (longitud*2)+1);
    for(int i=longitud-1, j=longitud;i>=0;i--,j++){
        cadena[j] = cadena[i];
        cadena[j+1] = '\0';
    }

    return &cadena[longitud];
}
