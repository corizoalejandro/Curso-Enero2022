#include <iostream>
#include "animal.h"

/* Ejemplo del Nodo */
class Nodo {
public:
    Nodo(Nodo *sig = NULL){
        this->sig = sig;
    }

    Nodo(int dato, Nodo *sig = NULL){
        this->dato = dato;
        this->sig = sig;
    }

    int dato;
    Nodo *sig;
};

void ejemplo1();
void ejemplo2();
void ejemplo_constructor_copia();
void ejemplo_llamadas_constructores();

int main()
{

    return 0;
}

// cuando todo era publico
void ejemplo1(){
//    Animal peppa, babe;
//    peppa.nombre = "Peppa";
//    peppa.especie = "Cerdo";
//    peppa.edad = 6;

//    peppa.saludar();

//    babe.nombre = "Babe";
//    babe.especie = "Cerdo";
//    babe.edad = 7;

//    babe.saludar();
}

void ejemplo2(){
    Animal peppa;
    Animal babe("Babe", "Cerdo", 7);
    peppa.saludar();
    babe.saludar();
}

void ejemplo_constructor_copia(){
    Animal firulais("Firulais", "Perro", 2);
    Animal copia(&firulais);

    firulais.saludar();
    copia.saludar();
}

void ejemplo_llamadas_constructores(){
    // llamada implicita
    Animal firulais = { "firulais", "perro", 8 };
    // llamada explicita
    Animal perrito("perrito","perro",8);
    // llamada implicita constructor copia
    Animal copia = firulais;
}
