#include "persona.h"

Persona::Persona()
{

}

Persona::Persona(QString nombre, QString edad, int genero)
{
    this->nombre = nombre;
    this->edad = edad;
    this->genero = genero;
}
