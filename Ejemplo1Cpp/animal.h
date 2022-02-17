#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
private:
    // atributos / propiedades
    std::string nombre;
    std::string especie;
    int edad;
public:
    Animal();
    Animal(std::string nombre, std::string especie, int edad);
    // Constructor copia
    Animal(const Animal *copia);
    // métodos / acciones
    void decir_nombre();
    void caminar();
    void hablar();
    void saludar();
};

#endif // ANIMAL_H
