#pragma once
#include"IIterador.h"
#include"Nodo.h"

template<class T>
class IteradorLinkedList : public IIterador<T>
{
private:
	Nodo<T>* punteroActual;

public:
	IteradorLinkedList(Nodo<T>* inicial);
	virtual bool haySiguiente() override;
	virtual T* actual() override;
};

template<class T>
inline IteradorLinkedList<T>::IteradorLinkedList(Nodo<T>* inicial)
{
	this->punteroActual = inicial;
}

template<class T>
inline bool IteradorLinkedList<T>::haySiguiente()
{
	return this->punteroActual != nullptr;
}

template<class T>
inline T* IteradorLinkedList<T>::actual()
{
	if (this->haySiguiente())
	{
		T* dato = this->punteroActual->getDato();
		this->punteroActual = this->punteroActual->getSiguiente();
		return dato;
	}
	return nullptr;
}







