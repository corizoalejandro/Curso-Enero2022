#include <iostream>
#include "figura.h"

using namespace std;

class Figura {
public:
    string nombre;
    int lado;
};

int main()
{
    figuras::Figura* cuadrado = new figuras::Cuadrado(6);
    Figura triangulo;
    triangulo.nombre = "Triangulo";
    triangulo.lado = 8;
    cout << "area de cuadrado: " << cuadrado->area() << endl;
    return 0;
}
