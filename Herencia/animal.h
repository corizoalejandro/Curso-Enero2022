#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal
{
public:
    Animal();

    Animal(std::string nombre, std::string especie, int edad);
    void saludar();
    void set_nombre(std::string nombre);
    std::string get_nombre();
protected:
    std::string nombre;
    std::string especie;
    int edad;
};


class Canino : public Animal {
public:
    Canino();
    Canino(std::string nombre, std::string especie, int edad, std::string raza);
    void ladrar();
private:
    std::string raza;
};

#endif // ANIMAL_H
