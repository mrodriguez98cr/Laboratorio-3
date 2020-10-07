#pragma once
#include"IIterador.h"

template<class T>
class IIterable
{
public:
	virtual IIterador* obtenerIterador() = 0;
	~IIterable() = default;
};
