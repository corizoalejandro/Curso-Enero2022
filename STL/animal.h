#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <fstream>

class Animal
{
public:
    Animal();

    Animal(std::string nombre, std::string especie, int edad);
    void saludar();
    void set_nombre(std::string nombre);
    std::string get_nombre();
    // sobrecargando operador << para guardar objeto como archivo
    friend std::ofstream& operator << (std::ofstream &archivito, const Animal &a){
        // creamos un int auxiliar para saber los tamaños de las cadenas
        int tam_aux;
        // sacabamos el tamaño de una cadena
        tam_aux = a.nombre.size();
        // guardamos el tamaño de la cadena dentro del archivo
        archivito.write((char*) &tam_aux, sizeof (int));
        // guardamos la cadena de la que sacamos tamaño dentro del archivo
        archivito.write(a.nombre.c_str(), tam_aux);
        // se repite el proceso por cada uno de los strings
        tam_aux = a.especie.size();
        archivito.write((char*) &tam_aux, sizeof (int));
        archivito.write(a.especie.c_str(), tam_aux);
        // se guarda el en tero del objeto
        archivito.write((char*) &a.edad, sizeof (int));
        // regresamos el ofstream
        return archivito;
    }
    // sobrecargando operador >> para leer desde un archivo datos
    // y meterlos dentro del objeto
    friend std::ifstream& operator >> (std::ifstream &archivito, Animal &a){
        // cramos un auxiliar para almacenar el tamaño de las cadenas
        int tam_aux;
        // creamos un buffer en donde leeremos las cadenas
        char* buffer = NULL;
        // leemos el tamaño de la cadena
        archivito.read((char*) &tam_aux, sizeof (int));
        // reservamos memoria para que el buffer tenga el tamaño suficiente
        buffer = new char[tam_aux+1];
        // leemos lacadena dentro de un buffer
        archivito.read(buffer, tam_aux);
        // truncamos el caracter '\0' para indicar que ahí termina la cadena
        // este no lo guardamos dentro del archivo, es por eso que lo colocamos
        buffer[tam_aux] = '\0';
        // metemos el buffer dentro de la respectiva cadena
        a.nombre = buffer;
        // liberamos la memoria del buffer
        delete [] buffer;
        // se repite por cada string que tengas
        archivito.read((char*) &tam_aux, sizeof (int));
        buffer = new char[tam_aux+1];
        archivito.read(buffer, tam_aux);
        buffer[tam_aux] = '\0';
        a.especie = buffer;
        delete [] buffer;
        // leemos el entero
        archivito.read((char*) &a.edad, sizeof (int));
        return archivito;
    }
protected:
    std::string nombre;
    std::string especie;
    int edad;
};


class Canino : public Animal {
public:
    Canino();
    Canino(std::string nombre, std::string especie, int edad, std::string raza);
    void ladrar();
private:
    std::string raza;
};

#endif // ANIMAL_H
