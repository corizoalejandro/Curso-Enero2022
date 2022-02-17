#ifndef FECHA_H
#define FECHA_H

#include <iostream>

class Fecha
{
public:
    Fecha();
    Fecha(int _dia, int _mes, int _anio);
    std::string muestra_en_formato();
    static std::string muestra_en_formato(int dia, int mes, int anio);

private:
    int dia;
    int mes;
    int anio;
};

#endif // FECHA_H
