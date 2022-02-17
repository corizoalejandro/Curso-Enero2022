#include "animal.h"

Animal::Animal(){
    this->nombre = "N/A";
    this->especie = "N/A";
    this->edad = -1;
}

Animal::Animal(std::string nombre, std::string especie, int edad){
    this->nombre = nombre;
    this->especie = especie;
    this->edad = edad;
}

// Constructor copia
Animal::Animal(const Animal *copia){
    this->nombre = copia->nombre;
    this->especie = copia->especie;
    this->edad = copia->edad;
}

void Animal::decir_nombre(){
    std::cout << "Mi nombre es: " << this->nombre << std::endl;
}

void Animal::caminar(){
    std::cout << "* " << this->nombre << " esta caminando *" << std::endl;
}

void Animal::hablar(){
    std::cout << this->nombre << " *esta hablando*" << std::endl;
}

void Animal::saludar(){
    std::cout << "Hola, soy " << this->nombre <<
                 " soy de la especie " << this->especie <<
                 " y tengo " << this->edad << " años!" << std::endl;
}
