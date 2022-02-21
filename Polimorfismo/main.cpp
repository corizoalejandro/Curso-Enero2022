#include <iostream>
#include "figura.h"

using namespace std;

int main()
{
//    Cuadrado cuadrado(9);
//    Triangulo triangulo(4, 4);
//    Circulo circulo(7);

//    cout << "El area del cuadrado es: " << cuadrado.area() << endl;
//    cout << "El perimetro del cuadrado es: " << cuadrado.perimetro() << endl;
//    cout << "El area del triangulo es: " << triangulo.area() << endl;
//    cout << "El perimetro del triangulo es: " << triangulo.perimetro() << endl;
//    cout << "El area del circulo es: " << circulo.area() << endl;
//    cout << "El perimetro del circulo es: " << circulo.perimetro() << endl;

    Figura* cuadrado = new Cuadrado(9);
    Figura* triangulo = new Triangulo(4, 4);
    Figura* circulo = new Circulo(7);

    Figura* figura = new Figura[10];
    delete [] figura;

    cout << "El area del cuadrado es: " << cuadrado->area() << endl;
    cout << "El perimetro del cuadrado es: " << cuadrado->perimetro() << endl;
    cout << "El area del triangulo es: " << triangulo->area() << endl;
    cout << "El perimetro del triangulo es: " << triangulo->perimetro() << endl;
    cout << "El area del circulo es: " << circulo->area() << endl;
    cout << "El perimetro del circulo es: " << circulo->perimetro() << endl;
    return 0;
}
