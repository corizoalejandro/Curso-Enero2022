#include "administradorarchivos.h"

#include <fstream>
#include <vector>
#include "animal.h"
#include "persona.h"

AdministradorArchivos::AdministradorArchivos()
{

}

void AdministradorArchivos::guarda_archivo_e1(std::string nombre)
{
    // se crea archivo de salida (guardar archivo)
    std::ofstream archivito(nombre);
    // se checa que se haya abierto
    if(archivito.is_open()){
        // guardamos datos
        archivito << "Hola" << std::endl;
        archivito << "Mundo!" << std::endl;
    }else{
        // mostramos mensaje de error en caso de no poderse abrir el archivo
        std::cerr << "No se pudo abrir el archivo: " << nombre << std::endl;
    }
    // cerramos archivo
    archivito.close();
}

void AdministradorArchivos::lee_archivo_e1(std::string nombre)
{
    // se crea archivo de entrada (leer archivo)
    std::ifstream archivito(nombre);
    // se crea un buffer en el que se almacenaran datos temporalmente
    std::string buffer;
    // se checa que se haya abierto
    if(archivito.is_open()){
        // leemes el archivo mientras no lleguemos al final del archivo
        while(!archivito.eof()){ // End Of File (EOF)
            // leemos una linea de texto
            getline(archivito, buffer);
            // mostramos los datos leidos
            std::cout << buffer << std::endl;
        }
    }else{
        // en caso de no poder abrir el archivo, mensaje de error
        std::cerr << "No se pudo abrir el archivo:" << nombre << std::endl;
    }
    // cerramos el archivo
    archivito.close();
}

void AdministradorArchivos::guarda_datos_bin(std::string nombre)
{
    std::fstream archivito(nombre, std::ios::binary | std::ios::out);
    Animal peppa("Peppa", "cerdo", 8);
    if(archivito.is_open()){
        archivito.write((char*) &peppa, sizeof (Animal));
    }else{
        std::cerr << "No se pudo abrir el archivo: " << nombre << std::endl;
    }
    archivito.close();
}

void AdministradorArchivos::lee_datos_bin(std::string nombre)
{
    std::fstream archivito(nombre, std::ios::binary | std::ios::in);
    Animal peppa;
    if(archivito.is_open()){
        archivito.read((char*) &peppa, sizeof (Animal));
    }else{
        std::cerr << "No se pudo abrir el archivo: " << nombre << std::endl;
    }
    // archivo cerraditto
    archivito.close();
    peppa.saludar();
}

void AdministradorArchivos::guarda_objetos_e1(std::string nombre)
{
    std::ofstream archivito(nombre, std::ios::binary);
    Animal peppa("Peppa", "Cerdo", 8);
    if(archivito.is_open()){
        archivito << peppa;
    }else{
        std::cerr << "No se pudo abrir el archivo: " << nombre << std::endl;
    }
    archivito.close();
}

void AdministradorArchivos::lee_objetos_e1(std::string nombre)
{
    std::ifstream archivito(nombre, std::ios::binary);
    Animal peppa;
    if(archivito.is_open()){
        archivito >> peppa;
    }else{
        std::cerr << "No se pudo abrir el archivo: " << nombre << std::endl;
    }
    archivito.close();
    peppa.saludar();
}

void AdministradorArchivos::guarda_objetos_e2(std::string nombre)
{
    std::ofstream archivito(nombre, std::ios::binary);
    Persona juanito("Juanito", "Perez", 80);
    if(archivito.is_open()){
        archivito.write((char*) &juanito, sizeof (Persona));
    }else{
        std::cerr << "No se pudo abrir el archivo: " << nombre << std::endl;
    }
    archivito.close();
}

void AdministradorArchivos::lee_objetos_e2(std::string nombre)
{
    std::ifstream archivito(nombre, std::ios::binary);
    Persona juanito;
    if(archivito.is_open()){
        archivito.read((char*) &juanito, sizeof (Persona));
    }else{
        std::cerr << "No se pudo abrir el archivo: " << nombre << std::endl;
    }
    archivito.close();
    std::cout << juanito;
}

void AdministradorArchivos::guarda_arreglo_e1(std::string nombre)
{
    std::fstream archivito(nombre, std::ios::in | std::ios::out | std::ios::binary);
    if(!archivito.is_open()){
        std::cerr << "No se pudo abrir el archivo: " << nombre << std::endl;
        return;
    }
    Persona *personas = new Persona[NO_PERSONAS];
    personas[0] = Persona("Juanito", "Perez", 80);
    personas[1] = Persona("Pedrito", "Sola", 80);
    personas[2] = Persona("Vladimir", "Putin", 70);
    personas[3] = Persona("Volodimir", "Zelinsky", 50);
    personas[4] = Persona("Andres Manuel", "Lopez", 90);
    for(int i=0;i < NO_PERSONAS;i++){
        archivito.write((char*) &personas[i], sizeof (Persona));
    }
    archivito.close();
}

void AdministradorArchivos::lee_arreglo_e1(std::string nombre)
{
    std::fstream archivito(nombre, std::ios::in | std::ios::out | std::ios::binary);
    if(!archivito.is_open()){
        std::cerr << "No se pudo abrir el archivo: " << nombre << std::endl;
        return;
    }
    Persona *personas = new Persona[NO_PERSONAS];
    for(int i=0;i < NO_PERSONAS; i++){
        archivito.read((char*) &personas[i], sizeof(Persona));
        std::cout << personas[i];
    }
    delete [] personas;
    archivito.close();
}

void AdministradorArchivos::lee_persona(std::string nombre)
{
    std::fstream archivito(nombre, std::ios::in | std::ios::out | std::ios::binary);
    if(!archivito.is_open()){
        std::cerr << "No se pudo abrir el archivo: " << nombre << std::endl;
        return;
    }
    Persona persona;
    archivito.seekg(0*sizeof (Persona));
    archivito.read((char*) &persona, sizeof (Persona));
    archivito.close();
    std::cout << persona;
}

void AdministradorArchivos::guarda_vector(std::string nombre)
{
    std::vector<Persona> personas;
    std::fstream archivito(nombre, std::ios::in | std::ios::out | std::ios::binary);
    if(!archivito.is_open()){
        std::cerr << "No se pudo abrir el archivo: " << nombre << std::endl;
        return;
    }
    personas.push_back(Persona("Juanito", "Perez", 80));
    personas.push_back(Persona("Chabelo", "Lopez", 100000));
    personas.push_back(Persona("Pepito", "Jimenez", 20));
    std::cout << personas[0];
    for(std::vector<Persona>::iterator i = personas.begin(); i != personas.end(); i++);
    for(int i=0;i < personas.size(); i++){
        archivito.write((char*) &personas[i], sizeof (Persona));
    }
    archivito.close();
}
