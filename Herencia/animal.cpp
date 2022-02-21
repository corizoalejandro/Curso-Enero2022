#include "animal.h"

Animal::Animal()
{
    this->nombre = "N/A";
    this->especie = "N/A";
    this->edad = -1;
}

Animal::Animal(std::string nombre, std::string especie, int edad){
    this->nombre = nombre;
    this->especie = especie;
    this->edad = edad;
}

void Animal::saludar(){
    std::cout << "Hola, soy " << this->nombre <<
                 " de la especie " << this->especie <<
                 " y tengo la edad de: " << this->edad << std::endl;
}

void Animal::set_nombre(std::string nombre){
    this->nombre = nombre;
}

std::string Animal::get_nombre(){
    return this->nombre;
}

// Llamando constructor padre sin parámetros
Canino::Canino() : Animal() {
    this->raza = "N/A";
}

// Llamando onstructor padre con parámetros
Canino::Canino(std::string nombre, std::string especie, int edad, std::string raza)
    : Animal(nombre, especie, edad){
    this->raza = raza;
}

void Canino::ladrar(){
    std::cout << this->nombre << ": bark bark! || raza: " << this->raza <<std::endl;
}
