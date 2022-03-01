#include <iostream>
#include <cstdlib>

using namespace std;

class Nodo{
    // Se está diciendo que la clase Lista va a ser
    // amiga de Nodo, por lo que Lista puede acceder
    // a los atributos privados de Nodo
    friend class Lista;
private:
    Nodo *sig;
    int dato;
};

class Lista {
public:
private:
    void inicia_nodo();
    int checa_nodo();
    // Se está diciendo que la función externa a_ver_nodo
    // puede acceder a los datos privados de Lista
    friend void a_ver_nodo(Lista* l);
    Nodo* inicio = NULL;
};

void a_ver_nodo(Lista* l);

int main()
{
    Lista l;
    // Esta linea comentada de abajo no se puede porque main()
    // no es amiga de Lists
//    l.inicia_nodo();
    a_ver_nodo(&l);
    return 0;
}

void a_ver_nodo(Lista* l){
    l->inicio = new Nodo();
    l->inicio = (Nodo*) malloc(sizeof(Nodo));
    l->inicia_nodo();
    cout << "El dato de nodo es: " << l->checa_nodo() << endl;
}

void Lista::inicia_nodo(){
    this->inicio->dato = 5;
}

int Lista::checa_nodo(){
    return this->inicio->dato;
}
