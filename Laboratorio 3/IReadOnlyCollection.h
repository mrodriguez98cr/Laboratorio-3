#pragma once


#include"IIterable.h"

template<class T>
class IReadOnlyCollection : public IIterable<T>
{
public:
	virtual T* consultarPorPosicion(int posicion) = 0;
	virtual bool contiene(T* elemento) = 0;
	virtual int getCantidad() = 0;
	virtual ~IReadOnlyCollection() = default;
};
