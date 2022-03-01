#ifndef ADMINISTRADORARCHIVOS_H
#define ADMINISTRADORARCHIVOS_H

#include <iostream>
#define NO_PERSONAS 5

class AdministradorArchivos
{
public:
    AdministradorArchivos();
    void guarda_archivo_e1(std::string nombre);
    void lee_archivo_e1(std::string nombre);
    void guarda_datos_bin(std::string nombre);
    void lee_datos_bin(std::string nombre);
    void guarda_objetos_e1(std::string nombre);
    void lee_objetos_e1(std::string nombre);
    void guarda_objetos_e2(std::string nombre);
    void lee_objetos_e2(std::string nombre);
    void guarda_arreglo_e1(std::string nombre);
    void lee_arreglo_e1(std::string nombre);
    void lee_persona(std::string nombre);
    void guarda_vector(std::string nombre);
};

#endif // ADMINISTRADORARCHIVOS_H
