#include "excepcionespruebas.h"

#include <iostream>

ExcepcionesPruebas::ExcepcionesPruebas()
{

}

void ExcepcionesPruebas::ejemplo1()
{
    int valor = 9;
    // try va a evaluar un bloque de sentencias
    try {
        if(valor > 7){
            // En caso de que si fuese a haber un error,
            // lanzas el error con throw
            throw "hubo un error :(";
        }
    // Aquí cachas el error lanzado
    } catch (const char* error) {
        std::cerr << error << std::endl;
    }
}

void ExcepcionesPruebas::ejemplo2()
{
    int valor = 9;
    try {
        if(valor > 8){
            throw 501;
        }
    } catch (int error) {
        std::cerr << "Código de error: " << error << std::endl;
    }
}

void ExcepcionesPruebas::ejemplo3()
{
    int valor = 9;
    try {
        if(valor > 8){
            throw "hubo un error";
        }else if(valor > 10){
            throw 501;
        }
    } catch (const char* error){
        std::cerr << error << std::endl;
    } catch (int error){
        std::cerr << "Código de error: " << error << std::endl;
    } catch (...) {
        std::cerr << "Hubo error, no se que onda, pero hubo error :(" << std::endl;
    }
}

void ExcepcionesPruebas::ejemplo4()
{
    char* buffer = NULL;
    try {
        buffer = new char[BUFFER];
    } catch (std::bad_alloc &e){
        std::cerr << "Error reservando memoria: " << e.what() << std::endl;
    }
}
