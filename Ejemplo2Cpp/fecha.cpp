#include "fecha.h"

Fecha::Fecha()
{
    this->dia = 0;
    this->mes = 0;
    this->anio = 0;
}

Fecha::Fecha(int _dia, int _mes, int _anio){
    this->dia = _dia;
    this->mes = _mes;
    this->anio = _anio;
}

// funcion no estatica
std::string Fecha::muestra_en_formato(){
    return this->muestra_en_formato(this->dia, this->mes, this->anio);
}

// funcion estatica
std::string Fecha::muestra_en_formato(int dia, int mes, int anio){
    std::string formato;

    // to_string convierte un dato numérico a cadena
    // se concatenan para dar formato
    formato = std::to_string(dia) + "/" +
            std::to_string(mes) + "/" +
            std::to_string(anio);

    return formato;
}
