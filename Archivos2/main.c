#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CADENA 20
#define NO_PERSONAS 5
#define ARCHIVO_PERSONA "persona.txt"

typedef struct persona{
    char nombre[CADENA];
    char apellido[CADENA];
    int edad;
} persona;

void muestra_persona(persona* p);
persona* inicializa_persona(const char* nombre, const char* apellido, const int edad);
int guarda_persona(persona* p, FILE* archivo);
int carga_persona(persona* p, FILE* archivo);
void guarda_datos(void);
void carga_datos(void);


int main()
{
    persona** arregloDePunteros = (persona**) malloc(sizeof (persona*)*NO_PERSONAS);
    arregloDePunteros[0] = inicializa_persona("juanito", "perez", 85);
    arregloDePunteros[1] = inicializa_persona("pedrito", "lopez", 96);
    arregloDePunteros[2] = inicializa_persona("maria", "gonzalez", 78);
    arregloDePunteros[3] = inicializa_persona("juanita", "apellido", 79);
    arregloDePunteros[4] = inicializa_persona("josefina", "lopez", 87);

    for(int i=0;i < NO_PERSONAS;i++){
        muestra_persona(arregloDePunteros[i]);
    }

    printf("fin de programa\n");
    return EXIT_SUCCESS;
}

void muestra_persona(persona* p){
    printf("Nombre: %s\n", p->nombre);
    printf("Apellido: %s\n", p->apellido);
    printf("Edad: %i\n\n", p->edad);
}

persona* inicializa_persona(const char* nombre, const char* apellido, const int edad){
    persona* p = (persona*) malloc(sizeof (persona));
    strcpy(p->nombre, nombre);
    strcpy(p->apellido, apellido);
    p->edad = edad;

    return p;
}

int guarda_persona(persona* p, FILE* archivo){
    int resultado = 0;
    if(archivo == NULL){
        return resultado;
    }

    resultado = fprintf(archivo, "%s %s %i", p->nombre, p->apellido, p->edad);

    return resultado;
}

int carga_persona(persona* p, FILE* archivo){
    int resultado = 0;
    if(!archivo){
        return resultado;
    }

    resultado = fscanf(archivo, "%s %s %i", p->nombre, p->apellido, &p->edad);

    return resultado;
}

void guarda_datos(void){
    persona* pepito = inicializa_persona("Pepito", "Perez", 7);
    FILE* archivito = fopen(ARCHIVO_PERSONA, "w");

    if(guarda_persona(pepito, archivito)){
        printf("datos guardados con exito dentro de: %s\n", ARCHIVO_PERSONA);
    }else{
        printf("no se pudo guardar los datos :(\n");
    }

    fclose(archivito);
    free(pepito);
}

void carga_datos(void){
    persona* pepito = (persona*) malloc(sizeof (persona));
    FILE* archivito = fopen(ARCHIVO_PERSONA, "r");

    printf("Cargando los datos del archivo: %s\n", ARCHIVO_PERSONA);

    if(carga_persona(pepito, archivito)){
        muestra_persona(pepito);
    }else{
        printf("No se pudo cargar el archivo :(\n");
    }

    fclose(archivito);
    free(pepito);
}
