#include <iostream>
#include "administradorarchivos.h"

#define NOMBRE_ARCHIVO "archivito.txt"
#define ARCHIVO_PERSONA "personas.txt"

using namespace std;

int main()
{
    AdministradorArchivos admin;
    // admin.guarda_archivo_e1(NOMBRE_ARCHIVO);
//    admin.lee_archivo_e1(NOMBRE_ARCHIVO);
//    admin.guarda_datos_bin(NOMBRE_ARCHIVO);
//    admin.lee_datos_bin(NOMBRE_ARCHIVO);
//    admin.guarda_objetos_e1(NOMBRE_ARCHIVO);
//    admin.lee_objetos_e1(NOMBRE_ARCHIVO);
//    admin.guarda_objetos_e2(ARCHIVO_PERSONA);
//    admin.lee_objetos_e2(ARCHIVO_PERSONA);
//    admin.guarda_arreglo_e1(ARCHIVO_PERSONA);
//    admin.lee_arreglo_e1(ARCHIVO_PERSONA);
    admin.lee_persona(ARCHIVO_PERSONA);
    cout << "fin de programa" << endl;
    return 0;
}
