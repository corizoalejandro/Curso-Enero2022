#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>

#define TAMANO_CADENA 30

class Persona
{
private:
    char nombre[TAMANO_CADENA];
    char apellido[TAMANO_CADENA];
    int edad;
public:
    Persona();
    Persona(const char* nombre, const char* apellido, int edad);
    friend std::ostream& operator << (std::ostream& os, const Persona &p){
        os << "Nombre: " << p.nombre << std::endl <<
              "Apellido(s): " << p.apellido << std::endl <<
              "Edad: " << p.edad << std::endl << std::endl;

        return os;
    }
};

#endif // PERSONA_H
