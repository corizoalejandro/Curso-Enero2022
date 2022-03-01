#include "persona.h"
#include <cstring>

Persona::Persona()
{

}

Persona::Persona(const char *nombre, const char *apellido, int edad)
{
    strcpy(this->nombre, nombre);
    strcpy(this->apellido, apellido);
    this->edad = edad;
}
