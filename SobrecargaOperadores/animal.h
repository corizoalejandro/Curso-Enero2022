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

    // operador << sobrecargado
    friend std::ostream& operator << (std::ostream &o, const Animal &a){
        o << "Nombre: " << a.nombre << std::endl <<
             "Especie: " << a.especie << std::endl <<
             "Edad: " << a.edad << std::endl << std::endl;
        return o;
    }

    Animal operator + (const Animal &a){
        Animal aux;
        aux.nombre = this->nombre + " " + a.nombre;
        aux.especie = this->especie + " " + a.especie;
        aux.edad = this->edad + a.edad;
        return aux;
    }
};

#endif // ANIMAL_H
