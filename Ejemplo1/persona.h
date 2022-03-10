#ifndef PERSONA_H
#define PERSONA_H

#include <QString>

enum {
    FEMENINO = 1,
    MASCULINO,
    OTRO
};

class Persona
{
public:
    Persona();
    Persona(QString nombre, QString edad, int genero);
    QString nombre;
    QString edad;
    int genero;
};

#endif // PERSONA_H
