#include <iostream>
#include "animal.h"

using namespace std;

class Entero {
public:
    Entero(int valor = 0);
    Entero operator + (const Entero &e){
        Entero aux;
        aux = this->valor + e.valor + 6;
        return aux;
    }
    friend ostream& operator << (ostream &o, const Entero &e){
        o << e.valor;
        return o;
    }
    bool operator < (const Entero &e){
        return this->valor < e.valor;
    }
private:
    int valor;
};

int main()
{
    Entero a = 2;
    Entero b = 2;
    Entero c = a + b;

    cout << "El resultado es: " << c << endl;

    Animal firulais("firulais", "perro", 8);
    cout << firulais;

    Animal peppa("Peppa", "cerdo", 2);
    Animal fusion = firulais + peppa;
    cout << fusion;

    return 0;
}

Entero::Entero(int valor){
    this->valor = valor;
}
