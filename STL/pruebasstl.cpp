#include "pruebasstl.h"
#include <vector>
#include <iostream>
// cola
#include <queue>
// pila
#include <stack>
// map
#include <map>

PruebasSTL::PruebasSTL()
{

}

void PruebasSTL::pruebas_vector()
{
    // Arreglo con funciones :D
    std::vector<Animal*> animalitos;
    animalitos.push_back(new Animal("Peppa", "Cerdo", 8));
    animalitos.push_back(new Animal("Firulais", "Perro", 10));
    animalitos.push_back(new Animal("Coto", "Cotorro", 1));

    // forma 1 de recorrerlo
    for(unsigned long i=0;i < animalitos.size(); i++){
        animalitos[i]->saludar();
    }

    // forma 2
    for(auto x : animalitos){
        x->saludar();
    }

    // forma 3
    for(std::vector<Animal*>::iterator i = animalitos.begin(); i != animalitos.end(); i++){
    }

    // liberando memoria de cada uno de los punteros con memoria reservada
    for(auto animal : animalitos){
        delete animal;
    }

    animalitos.clear();

}

void PruebasSTL::pruebas_cola()
{
    std::queue<Animal*> animalitos;
    animalitos.push(new Animal("Peppa", "Cerdo", 8));
    animalitos.push(new Animal("Firulais", "Perro", 10));
    animalitos.push(new Animal("Coto", "Cotorro", 1));

    while (!animalitos.empty()) {
        // accede al dato de en frente de la cola
        animalitos.front()->saludar();
        delete animalitos.front();
        // saca el dato de en frente de la cola
        animalitos.pop();
    }
}

void PruebasSTL::pruebas_pila()
{
    std::stack<Animal*> animalitos;
    animalitos.push(new Animal("Peppa", "Cerdo", 8));
    animalitos.push(new Animal("Firulais", "Perro", 10));
    animalitos.push(new Animal("Coto", "Cotorro", 1));

    while (!animalitos.empty()){
        // accede al tope de la pila
        animalitos.top()->saludar();
        delete animalitos.top();
        // saca el dato de la pila
        animalitos.pop();
    }
}

void PruebasSTL::pruebas_map()
{
    std::map<std::string, Animal*> animalitos;
    animalitos.insert(std::pair<std::string, Animal*>("Peppa", new Animal("Peppa", "Cerdo", 8)));
    animalitos.insert(std::pair<std::string, Animal*>("Firulais", new Animal("Firulais", "Perro", 10)));
    animalitos.insert(std::pair<std::string, Animal*>("Coto", new Animal("Coto", "Cotorro", 1)));

    animalitos["Peppa"]->saludar();
    animalitos.at("Peppa")->saludar();

    std::cout << "iterando map" << std::endl;

    // iterando map
    for(std::map<std::string, Animal*>::iterator i = animalitos.begin(); i != animalitos.end(); i++){
        i->second->saludar();
    }
}
