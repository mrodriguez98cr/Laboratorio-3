#pragma once
#include <iostream>
#include <sstream>

#include "IList.h"
#include "Nodo.h"
#include "IteradorLinkedList.h"

using namespace std;

template<class T>
class LinkedList :public IList<T>
{
private:
	Nodo* primero;
	int cantidad;
	void eliminarPrimero();
	void eliminarNodo(bool liberarMemoria, Nodo<T>* eliminar);

public:
	LinkedList();
	void insertarAlFinal(T* elemento) override;
	void insertarEnPosicion(T* elemento, int posicion) override;
	void borrarEnPosicion(int posicion, bool liberarMemoria = false) override;
	T* consultarPorPosicion(int posicion) override;
	bool contiene(T* elemento) override;
	int getCantidad() override;
	void liberarDatosInternos() override;
	string toString() override;
	IIterador* obtenerIterador() override;
	~LinkedList();
};

template<class T>
inline void LinkedList<T>::eliminarPrimero()
{
	if (this->primero != nullptr)
	{
		Nodo<T>* eliminado = primero;
		this->primero = this->primero->getSiguiente();
		delete eliminado;
	}
}

template<class T>
inline void LinkedList<T>::eliminarNodo(bool liberarMemoria, Nodo<T>* eliminar)
{
	if (liberarMemoria && eliminar->getDato())
	{
		delete eliminar->getDato();
	}
	delete eliminar;
	this->cantidad--;
}

template<class T>
inline LinkedList<T>::LinkedList()
{
	this->primero = nullptr;
	this->cantidad = 0;
}

template<class T>
inline void LinkedList<T>::insertarAlFinal(T* elemento)
{
	Nodo<T>* nuevo = new Nodo(elemento, nullptr);

	if (this->primero == nullptr)
	{
		this->primero = nuevo;
	}
	else
	{
		Nodo<T>* actual = this->primero;
		while (actual->getSiguiente() != nullptr)
		{
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevo);
	}

	this->cantidad++;
}

template<class T>
inline void LinkedList<T>::insertarEnPosicion(T* elemento, int posicion)
{
	if (posicion > this->cantidad)
	{
		cerr << "Posicion de insercion invalida" << endl;
		return;
	}

	Nodo<T>* nuevo = new Nodo(elemento, nullptr);
	if (this->primero == nullptr)
	{
		this->primero = nuevo;
	}
	else
	{
		if (posicion == 0)
		{
			nuevo->setSiguiente(this->primero);
			this->primero = nuevo;
		}
		else
		{
			Nodo<T>* actual = this->primero;
			for (int i = 0; actual->getSiguiente() != nullptr && i < posicion - 1; i++)
			{
				actual = actual->getSiguiente();
			}
			nuevo->setSiguiente(actual->getSiguiente());
			actual->setSiguiente(nuevo);
		}
	}

	this->cantidad++;
}

template<class T>
inline void LinkedList<T>::borrarEnPosicion(int posicion, bool liberarMemoria)
{
	if (this->primero == nullptr)
	{
		return;
	}
	else
	{
		Nodo<T>* eliminar;
		if (posicion == 0)
		{
			eliminar = this->primero;
			this->primero = this->primero->getSiguiente();
			eliminarNodo(liberarMemoria, eliminar);
		}
		else
		{
			Nodo<T>* actual = this->primero;
			for (int i = 0; actual->getSiguiente() != nullptr && i < posicion - 1; i++)
			{
				actual = actual->getSiguiente();
			}
			if (actual->getSiguiente() != nullptr)
			{
				eliminar = actual->getSiguiente();
				actual->setSiguiente(eliminar->getSiguiente());
				eliminarNodo(liberarMemoria, eliminar);
			}
		}
	}
}

template<class T>
inline T* LinkedList<T>::consultarPorPosicion(int posicion)
{
	Nodo<T>* actual = this->primero;
	int i = 0;
	for (int i = 0; i < posicion && actual != nullptr; i++)
	{
		actual = actual->getSiguiente();
	}

	if (actual != nullptr)
	{
		return actual->getDato();
	}
	else
	{
		cerr << "Posicion invalida" << endl;
		return nullptr; // Posicion estaba fuera de los límites de la colección
	}
}

template<class T>
inline bool LinkedList<T>::contiene(T* elemento)
{
	Nodo<T>* actual = this->primero;
	while (actual != nullptr)
	{
		if (actual->getDato() == elemento)
			return true;
		actual = actual->getSiguiente();
	}
	return false;
}

template<class T>
inline int LinkedList<T>::getCantidad()
{
	return this->cantidad;
}


template<class T>
inline void LinkedList<T>::liberarDatosInternos()
{
	while (primero != nullptr)
	{
		if (primero->getDato())
		{
			delete primero->getDato();
		}
		eliminarPrimero();
	}

	this->cantidad = 0;
}


template<class T>
inline string LinkedList<T>::toString()
{
	stringstream s;
	Nodo<T>* actual = this->primero;

	while (actual != nullptr)
	{
		if (actual->getDato())
		{
			s << actual->getDato()->toString() << endl;
		}
		actual = actual->getSiguiente();
	}

	return s.str();
}


template<class T>
inline IIterador<T>* LinkedList<T>::obtenerIterador()
{
	return new IteradorLinkedList(this->primero);
}

template<class T>
inline LinkedList<T>::~LinkedList()
{
	while (primero != nullptr)
	{
		eliminarPrimero();
	}
}









