#include "figura.h"
#include <iostream>
#include <cmath>

using namespace figuras;

/*

    Sección de Figura

*/

figuras::Figura::Figura()
{

}

int Figura::area(){
    std::cout << "Area de figura" << std::endl;
    return -1;
}

int Figura::perimetro(){
    std::cout << "Perimetro de figura" << std::endl;
    return -1;
}

/*

    Sección de Cuadrado

*/

Cuadrado::Cuadrado(int lado){
    this->lado = lado;
}

int Cuadrado::area(){
    return lado*lado;
}

int Cuadrado::perimetro(){
    return lado*4;
}

/*

  Triangulo (Equilatero)

*/

Triangulo::Triangulo(int base, int altura){
    this->base = base;
    this->altura = altura;
}

int Triangulo::area(){
    return (base*altura)/2;
}

int Triangulo::perimetro(){
    return base*3;
}

/*

    Circulo

*/

Circulo::Circulo(int diametro){
    this->diametro = diametro;
}

int Circulo::area(){
    return PI*pow((this->diametro/2), 2);
}

int Circulo::perimetro(){
    return PI*this->diametro;
}
