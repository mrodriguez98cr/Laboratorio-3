#pragma once
#include <iostream>
#include <sstream>


using namespace std;

template<class T>
class Nodo
{
private:
    T* dato;
    Nodo<T>* siguiente;

public:
    Nodo(T* dato, Nodo* siguiente);
    T* getDato() const;
    void setDato(T* dato);
    Nodo<T>* getSiguiente() const;
    void setSiguiente(Nodo<T>* siguiente);
};

template<class T>
Nodo<T>::Nodo(T* dato, Nodo<T>* siguiente)
{
    this->dato = dato;
    this->siguiente = siguiente;
}

template<class T>
T* Nodo<T>::getDato() const
{
    return dato;
}

template<class T>
void Nodo<T>::setDato(T* dato)
{
    this->dato = dato;
}

template<class T>
Nodo<T>* Nodo<T>::getSiguiente() const
{
    return siguiente;
}

template<class T>
void Nodo<T>::setSiguiente(Nodo<T>* siguiente)
{
    this->siguiente = siguiente;
}
