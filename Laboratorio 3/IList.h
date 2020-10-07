#pragma once
#include <iostream>
#include <sstream>
#include "IReadOnlyCollection.h"

using namespace std;

template<class T>
class IList : public IReadOnlyCollection<T>
{
public:
	virtual void insertarAlFinal(T* elemento) = 0;
	virtual void insertarEnPosicion(T* elemento, int posicion) = 0;
	virtual void borrarEnPosicion(int posicion, bool liberarMemoria = false) = 0;
	virtual void liberarDatosInternos() = 0;
	virtual ~IList() = default;
};