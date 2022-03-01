#ifndef LISTA_H
#define LISTA_H

#include <cstdlib>

template <class T>
class Nodo {
public:
    Nodo<T> *sig;
    T dato;
public:
    Nodo(Nodo<T>* sig = NULL);
    Nodo(T dato, Nodo<T>* sig = NULL);
    ~Nodo(){
        delete sig;
    }
};

template <class T>
class Lista
{
private:
    Nodo<T>* inicio;
public:
    Lista(){
        inicio->dato;
    }
};

template <class T>
Nodo<T>::Nodo(Nodo<T>* sig){
    this->sig = sig;
}

template <class T>
Nodo<T>::Nodo(T dato, Nodo<T>* sig){
    this->dato = dato;
    this->sig = sig;
}

template <class T>
Lista<T>::Lista(){
    this->inicio = NULL;
}

#endif // LISTA_H
